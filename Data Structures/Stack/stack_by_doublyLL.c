#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct node
{
    int data;
    struct node *prev,*next;
}Node;

Node* newNode(int val)
{
    Node* temp =(Node *)malloc(sizeof(Node));
    temp->data = val;
    temp->prev = NULL;
    temp->next = NULL;

    return temp;
}

int main()
{
    Node *top=NULL,*fir;
    int i,val;
    printf("Enter no. of values:");
    scanf("%d",&i);
    printf("Enter values:\n");
    for(int x=0;x<i;x++)
    {
        scanf("%d",&val);
        push_dll(&top,val,&fir);
    }
    display(top);
}
void push_dll(Node **top,int val,Node **fir)
{
    Node *temp=newNode(val);
    temp->next=*top;
    if((*top)!=NULL)
        (*top)->prev=temp;
    *top=temp;
    if((*top)->prev==NULL && (*top)->next==NULL)
        *fir=*top;
}
void display(Node *start)
{
    printf("\nThe Doubly Linked List:-\n");
    Node *temp;
    temp=start;
    while(temp!=NULL)
    {
        printf("%d  ",temp->data);
        temp=temp->prev;
    }
}
