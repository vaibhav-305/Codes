#include <stdio.h>
#include <malloc.h>

typedef struct btreenode
{
    int data;
    struct btreenode *left,*right;
}BNODE;
int Search(int *ino,int start,int endi,int val)
{
    for(int i=start;i<=endi;i++)
    {
        if(ino[i]==val)
            return i;
    }
}
BNODE * createBinarytree(int *ino,int *pos,int start,int endi,int *indx)
{
    if(start>endi)
        return NULL;
    BNODE *new_node=(BNODE *)malloc(sizeof(BNODE));
    new_node->data=pos[(*indx)];
    new_node->left=NULL;
    new_node->right=NULL;
    (*indx)--;
    if(start==endi)
        return new_node;

    int loc=Search(ino,start,endi,(new_node->data));
    new_node->right=createBinarytree(ino,pos,loc+1,endi,indx);
    new_node->left=createBinarytree(ino,pos,start,loc-1,indx);

    return new_node;
}
void Preorder(BNODE *root)
{
    if(root!=NULL)
    {
        printf("%d ",root->data);
        Preorder(root->left);
        Preorder(root->right);
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    int pos[n],ino[n];
    for(int i=0;i<n;i++)
        scanf("%d",&ino[i]);
    for(int i=0;i<n;i++)
        scanf("%d",&pos[i]);
    int indx=n-1;
    BNODE *root=createBinarytree(ino,pos,0,n-1,&indx);
    printf("Pre Order: ");
    Preorder(root);
}
