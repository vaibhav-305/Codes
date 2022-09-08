#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct BSTnode
{
    int data;
    struct BSTnode *left,*right;
}Node;

Node * create_BST(Node *,int );
Node * Rotate(Node *);

int main()
{
    int val;
    Node *root=NULL;
    for(int i=0;i<3;i++)
    {
        scanf("%d",&val);
        root=create_BST(root,val);
    }
    Inorder(root);
    root=Rotate(root);
    Inorder(root);
  return 0;
}
Node * create_BST(Node *root,int val)
{
    if(root==NULL)
    {
        root=(Node *)malloc(sizeof(Node));
        root->data=val;
        root->left=NULL;
        root->right=NULL;
        return root;
    }
    else if(root->data>val)
        root->left=create_BST(root->left,val);
    else
        root->right=create_BST(root->right,val);

    return root;
}
Node * Rotate(Node *root)
{

}
