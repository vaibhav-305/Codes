#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
typedef struct btreenode
{
    int data;
    struct btreenode *left,*right;
}Node;

Node * create_btree();
int isImage(Node *, Node *);

int main()
{
    Node *root1,*root2;
    printf("Enter Data for tree 1:---\n");
    root1=create_btree();
    printf("Enter Data for tree 2:---\n");
    root2=create_btree();
    if(isImage(root1,root2))
        printf("Trees are Mirror Images of each other");
    else
        printf("Trees are not mirror images of each other");
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

int isImage(Node *root1,Node *root2)
{
    if(root1==NULL && root2==NULL)
        return 1;
    if(root1!=NULL && root2!=NULL)
    {
        if((root1->data==root2->data) && isImage(root1->left,root2->right) &&isImage(root1->right,root2->left))
            return 1;
    }
    return 0;
}
