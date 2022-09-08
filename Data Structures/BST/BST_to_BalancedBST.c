/** The basic idea is to first store inorder traversal of BST in
    array, and always take the mid element to be node and do this
    recursively.  */
#include <stdio.h>
#include <stdlib.h>
typedef struct BBSTnode
{
    int data;
    struct BBSTnode *left,*right;
}Node;
Node *newNode(int val)
{
    Node *node=(Node *)malloc(sizeof(Node));
    node->data=val;
    node->left=NULL;
    node->right=NULL;
  return node;
}

Node * createBBST(int *,int,int);

void preOrder(Node *root)
{
    if(root!=NULL)
    {
        printf("%d  ",root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    int ino[n];
    for(int i=0;i<n;i++)
        scanf("%d",&ino[i]);
    Node *root=createBBST(ino,0,n-1);
    preOrder(root);
  return 0;
}
Node * createBBST(int ino[],int iStart,int iEnd)
{
    if(iStart>iEnd)
        return NULL;
    int mid=iStart+(iEnd-iStart)/2;
    Node * new_node=newNode(ino[mid]);

    if(iStart==iEnd)
        return new_node;

    new_node->left=createBBST(ino,iStart,mid-1);
    new_node->right=createBBST(ino,mid+1,iEnd);

    return new_node;
}
