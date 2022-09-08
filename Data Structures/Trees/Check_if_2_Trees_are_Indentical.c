#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
typedef struct btreenode
{
    int data;
    struct btreenode *left,*right;
}Node;

Node * create_btree();
int isIdentical(Node *, Node *);

int main()
{
    Node *root1,*root2;
    printf("Enter Data for tree 1:---\n");
    root1=create_btree();
    printf("Enter Data for tree 2:---\n");
    root2=create_btree();
    if(isIdentical(root1,root2))
        printf("Trees are Identical");
    else
        printf("Trees are not identical");
}
Node * create_btree()
{
    int inp;
    printf("Enter data: ");
    scanf("%d",&inp);
    if(inp==-1)
        return NULL;
    Node *new_node;
    new_node=(Node *)malloc(sizeof(Node));
    new_node->data=inp;
    printf("Enter for Left Child:-\n");
    new_node->left=create_btree();
    printf("Enter for Right Child:-\n");
    new_node->right=create_btree();
    return new_node;
}
int isIdentical(Node *r1, Node *r2)
{
    //Your Code here
    if(r1==NULL && r2==NULL)
        return 1;
    if(r1!=NULL && r2!=NULL)
    {
        if((r1->data==r2->data) && isIdentical(r1->left,r2->left) && isIdentical(r1->right,r2->right))
             return 1;
    }
    return 0;
}


