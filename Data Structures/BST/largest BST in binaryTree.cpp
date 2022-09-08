/*
A Tree is BST if following is true for every node x.
  1. The largest value in left subtree (of x) is smaller than value of x.
  2. The smallest value in right subtree (of x) is greater than value of x.
To determine if a subtree rooted under a node is a BST or not, the left subtree should provide information about the maximum value
in it. The right subtree should provide information about the minimum value in it. Also, the parent node should be notified when
both left and right child are also BST.
*/
#include <iostream>
using namespace std;
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

Node * insert_in_BST(Node *,int);

void showBST(Node *root)
{
    if(root!=NULL)
    {
        showBST(root->left);
        printf("%d ",root->data);
        showBST(root->right);
    }
}
void Free(Node *root)
{
    if(root!=NULL)
    {
        Free(root->left);
        Free(root->right);
        delete root;
    }
}
int main()
{
    Node *root=NULL;
    int n,inp;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>inp;
        root=insert_in_BST(root,inp);
    }
    Free(root);
  return 0;
}
Node * insert_in_BST(Node *root,int val)
{
    if(root==NULL)
    {
        root=new Node(val);
        return root;
    }
    else if(root->data>val)
        root->left=insert_in_BST(root->left,val);
    else
        root->right=insert_in_BST(root->right,val);

    return root;
}
