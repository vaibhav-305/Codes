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
BNODE * createBtree(int *ino,int *pre,int start,int endi)
{
    static int indx=0;
    if(start>endi)
        return NULL;
    BNODE *new_node=(BNODE *)malloc(sizeof(BNODE));
    new_node->data=pre[indx];
    new_node->left=NULL;
    new_node->right=NULL;
    indx++;
    if(start==endi)
        return new_node;

    int loc=Search(ino,start,endi,(new_node->data));
    new_node->left=createBtree(ino,pre,start,loc-1);
    new_node->right=createBtree(ino,pre,loc+1,endi);

    return new_node;
}
void Postorder(BNODE *root)
{
    if(root!=NULL)
    {
        Postorder(root->left);
        Postorder(root->right);
        printf("%d ",root->data);
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    int pre[n],ino[n];
    for(int i=0;i<n;i++)
        scanf("%d",&ino[i]);
    for(int i=0;i<n;i++)
        scanf("%d",&pre[i]);
    BNODE *root=createBtree(ino,pre,0,n-1);
    printf("Post Order: ");
    Postorder(root);
}
