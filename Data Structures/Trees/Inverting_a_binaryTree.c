#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct binarytreenode
{
    int data;
    struct binarytreenode *left,*right;
}BTNODE;

BTNODE * create_btree();
void dispaly_Inorder(BTNODE *);
void display_Preorder(BTNODE *root);
void invert_tree(BTNODE *);

int main()
{
    BTNODE *root;
    root=create_btree();
    printf("Inorder Transversal(before): ");
    dispaly_Inorder(root);
    printf("\nPreorder Transversal(before): ");
    display_Preorder(root);
    printf("\n");
    invert_tree(root);
    printf("\nInorder Transversal(after): ");
    dispaly_Inorder(root);
    printf("\nPreorder Transversal(after): ");
    display_Preorder(root);
  return 0;
}

BTNODE * create_btree()
{
    int inp;
    printf("Enter Data: ");
    scanf("%d",&inp);
    if(inp==-1)
        return NULL;
    BTNODE *new_node=(BTNODE *)malloc(sizeof(BTNODE));
    new_node->data=inp;
    printf("Enter for left child:-\n");
    new_node->left=create_btree();
    printf("Enter for right child:-\n");
    new_node->right=create_btree();
    return new_node;
}
void dispaly_Inorder(BTNODE *root)
{
    if(root!=NULL)
    {
        dispaly_Inorder(root->left);
        printf("%d ",root->data);
        dispaly_Inorder(root->right);
    }
}
void display_Preorder(BTNODE *root)
{
    if(root!=NULL)
    {
        printf("%d ",root->data);
        display_Preorder(root->left);
        display_Preorder(root->right);
    }
}
void invert_tree(BTNODE *root)
{
    if((root)!=NULL)
    {
        BTNODE *temp;
        temp=(root)->left;
        (root)->left=(root)->right;
        (root)->right=temp;
        //printf("%d ",(*root)->data);
        invert_tree(((root)->left));
        invert_tree(((root)->right));
    }
}
