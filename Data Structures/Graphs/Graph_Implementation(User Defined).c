//For both directed/undirected
#include <stdio.h>
#include <stdlib.h>

struct Listnode
{
    int data;
    struct Listnode *next;
};
struct Graph {
  int numVertices;
  struct Listnode** adjLists;
};
void DFS(struct Listnode **,int,int *);
void BFS(struct Listnode **,int,int *);

struct Listnode* createNode(int v) {
  struct Listnode* newNode = (struct Listnode *)malloc(sizeof(struct Listnode));
  newNode->data = v;
  newNode->next = NULL;
  return newNode;
}
void add_in_LinkedList(struct Listnode **head,struct Listnode **tail,int val)
{
    struct Listnode *new_node=createNode(val);
    if(*head==NULL){
        *head=*tail=new_node;
        return ;
    }
    (*tail)->next=new_node;
    *tail=new_node;
}
struct Graph* createAGraph(int vertices) {
  struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
  graph->numVertices = vertices;
  graph->adjLists = (struct Listnode**)malloc(vertices * sizeof(struct Listnode*)); //array of pointers

  int ve,inp;
  for (int i = 0; i < vertices; i++)
  {
      printf("Enter no. of adjacencies for vertex %d: ",i);
      scanf("%d",&ve);
      if(ve!=0)
      {
          struct Listnode *head=NULL,*tail=NULL;
          printf("Enter adjacenies:\n");
          for(int j=0;j<ve;j++)
          {
              scanf("%d",&inp);
              add_in_LinkedList(&head,&tail,inp);
          }
          graph->adjLists[i] = head;
      }
      else
          graph->adjLists[i] = NULL;
  }
  return graph;
}
void printLinkedList(struct Listnode *head)
{
    struct Listnode *temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
}
void printGraph(struct Graph *grph)
{
    printf("Adjacency List:\n");
    for(int i=0;i<(grph->numVertices);i++)
    {
        printf("\nAdjacencies of %d:\n",i);
        printLinkedList(grph->adjLists[i]);
    }
}
void FreeLinkedList(struct Listnode *head)
{
    struct Listnode *temp;
    while(head!=NULL)
    {
        temp=head;
        head=head->next;
        free(temp);
    }
}
void Free(struct Graph *grph)
{
    for(int i=0;i<(grph->numVertices);i++)
    {
        FreeLinkedList(grph->adjLists[i]);
    }
    free(grph->adjLists);
    free(grph);
}

int main()
{
    printf("Enter no. of vertices: ");
    int v,ve,nd;
    scanf("%d",&v);
    int *visited=(int *)malloc(v*(sizeof(int)));
    for(int i=0;i<v;i++)
        visited[i]=0;
    struct Graph *grph=createAGraph(v);
    printGraph(grph);
    printf("\n\nEnter vertex no.(from 0 to %d):",v-1);
    scanf("%d",&nd);
    printf("DFS:\n");
    DFS(grph->adjLists,nd,visited);
    for(int i=0;i<v;i++)
        visited[i]=0;
    printf("\nBFS:\n");
    BFS(grph->adjLists,nd,visited);
    free(visited);
    Free(grph);
  return 0;
}
void DFS(struct Listnode **adjlst,int v,int *visited)
{
    struct Listnode *q;
    visited[v]=1;
    printf("%d  ",v);
    q=*(adjlst+v);  //basically-> adjlist[v] in pointer notation
    while(q!=NULL)
    {
        if(visited[q->data]==0)
	        DFS(adjlst,q->data,visited);
	    else
	        q=q->next;
    }
}
void BFS(struct Listnode **adjlst,int v,int *visited)
{

}
