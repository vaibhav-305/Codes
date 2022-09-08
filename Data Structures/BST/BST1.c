#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct binarytreenode{
    int data;
    struct binarytreenode *right,*left;
}BNODE;

void add_item(BNODE **,int );
void display_Inorder(BNODE *);
void display_Preorder(BNODE *);
void display_Postorder(BNODE *);

int main()
{
    BNODE *root;
    int inp,opt;
    root=NULL;
    do
    {
        printf("\n************** MENU ***************");
        printf("\n1. Insert Item");
        printf("\n2. Display Tree (INORDER)");
        printf("\n3. Display Tree (PREORDER)");
        printf("\n4. Display Tree (POSTORDER)");
        printf("\n5. Exit");
        printf("\n***********************************");
        printf("\nSelect option:");
        scanf("%d",&opt);
        switch(opt)
        {
        case 1:
            printf("Enter Input: ");
            scanf("%d",&inp);
            add_item(&root,inp);
            break;
        case 2:
            printf("Inorder traversal: ");
            display_Inorder(root);
            break;
        case 3:
            printf("Preorder traversal: ");
            display_Preorder(root);
            break;
        case 4:
            printf("Postorder traversal: ");
            display_Postorder(root);
            break;
        }
    }while(opt<5);
    return 0;
}
void add_item(BNODE **node, int num){
    if(*node==NULL){
        *node = (BNODE *)malloc(sizeof(BNODE));
        (*node)->data=num;
        (*node)->left = NULL;
        (*node)->right=NULL;
    }
    else{
        if(num<((*node)->data)){
            add_item(&((*node)->left),num);
        }
        else{
            add_item(&((*node)->right),num);
        }
    }
return ;
}

void display_Inorder(BNODE *node){
    if(node!=NULL){
        display_Inorder(node->left);
        printf("%d ",node->data);
        display_Inorder(node->right);
    }
}

void display_Preorder(BNODE *node){
    if(node!=NULL){
        printf("%d ",node->data);
        display_Preorder(node->left);
        display_Preorder(node->right);
    }
}

void display_Postorder(BNODE *node){
    if(node!=NULL){
        display_Postorder(node->left);
        display_Postorder(node->right);
        printf("%d ",node->data);
    }
}
