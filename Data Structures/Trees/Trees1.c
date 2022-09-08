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
void dispaly_Preorder(BTNODE *);
void dispaly_Postorder(BTNODE *);
void height(BTNODE *,int ,int *);
void count_leafnodes(BTNODE *,int *);

int max(int a,int b)
{
    if(a>=b)
        return a;
    else
        return b;
}
int main()
{
    int h=0,mx=0,cnt=0;
    BTNODE *root;
    root=create_btree();
    height(root,0,&mx);
    printf("Height: %d\n",mx+1);
    count_leafnodes(root,&cnt);
    printf("Leaf Nodes: %d\n",cnt);
    printf("Inorder Transversal: ");
    dispaly_Inorder(root);
    printf("\nPreorder Transversal: ");
    display_Preorder(root);
    printf("\nPostorder Transversal: ");
    display_Postorder(root);
  return 0;
}

BTNODE * create_btree()
{
    int inp;
    printf("Enter data: ");
    scanf("%d",&inp);
    if(inp==-1)
        return NULL;
    BTNODE *new_node;
    new_node=(BTNODE *)malloc(sizeof(BTNODE));
    new_node->data=inp;
    printf("Enter for Left Child:-\n");
    new_node->left=create_btree();
    printf("Enter for Right Child:-\n");
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
void height(BTNODE *root,int h,int *mx)
{
    if(root==NULL)
        return ;
    height(root->left,h+1,mx);
    *mx=max(h,(*mx));
    height(root->right,h+1,mx);
}
void count_leafnodes(BTNODE *root,int *cnt)
{
    if(root==NULL)
        return ;
    count_leafnodes(root->left,cnt);
    if(root->left==NULL && root->right==NULL){
        (*cnt)++;
    }
    count_leafnodes(root->right,cnt);
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

void display_Postorder(BTNODE *root)
{
    if(root!=NULL)
    {
        display_Postorder(root->left);
        display_Postorder(root->right);
        printf("%d ",root->data);
    }
}
