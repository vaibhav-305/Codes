#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct BSTnode
{
    int data;
    struct BSTnode *left,*right;
}Node;

Node * insert_in_BST(Node *,int);
void showBST(Node *);
Node* search_in_BST(Node*,int);
Node * delete_from_BST(Node *,int);

void Preorder(Node *root)
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
    Node *root=NULL;
    int n,inp;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&inp);
        root=insert_in_BST(root,inp);
    }


    showBST(root);
    printf("\n");
    Preorder(root);
    /*Node *temp=search_in_BST(root,7);
    if(temp==NULL)
        printf("\nNOT FOUND");
    else
        printf("\nFOUND");*/
    printf("\n");
    int del;
    scanf("%d",&del);
    root=delete_from_BST(root,del);
    printf("\n");
    showBST(root);
    printf("\n");
    Preorder(root);
  return 0;
}

Node * insert_in_BST(Node *root,int val)
{
    if(root==NULL)
    {
        root=(Node *)malloc(sizeof(Node));
        root->data=val;
        root->right=NULL;
        root->left=NULL;
        return root;
    }
    else if(root->data>val)
        root->left=insert_in_BST(root->left,val);
    else
        root->right=insert_in_BST(root->right,val);

    return root;
}
void showBST(Node *root)
{
    if(root!=NULL)
    {
        showBST(root->left);
        printf("%d ",root->data);
        showBST(root->right);
    }
}
Node* search_in_BST(Node* root, int val)
{
    // Base Cases: root is null or key is present at root
    if (root == NULL || root->data == val){
       return root;
    }

    // Key is greater than root's key
    if (root->data < val)
       return search_in_BST(root->right, val);

    // Key is smaller than root's key
    return search_in_BST(root->left, val);
}

Node *inorder_successor(Node *root)
{
    Node *temp=root;
    while(temp->left!=NULL)
        temp=temp->left;
    return temp;
}

Node * delete_from_BST(Node *root,int val)
{
    if(root==NULL)
        return root;
    if((root->data)>val)
        root->left=delete_from_BST(root->left,val);
    else if((root->data)<val)
        root->right=delete_from_BST(root->right,val);

    //! if Node is found then below part is going to be executed
    else
    {
        //! 0 child
        if(root->left==NULL && root->right==NULL)
        {
            free(root);
            return NULL;
        }

        //! 1 child
        else if(root->left==NULL)
        {
            Node *temp=root;
            root=root->right;
            free(temp);
        }
        else if(root->right==NULL)
        {
            Node *temp=root;
            root=root->left;
            free(temp);
        }

        //! 2 child
        else
        {
            Node *temp=inorder_successor(root->right);
            root->data=temp->data;
            root->right=delete_from_BST(root->right,temp->data);
        }
    }
    return root;
}
//100 150 125 1 127 75 128 74 126
