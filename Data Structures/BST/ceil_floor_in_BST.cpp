#include <iostream>
#include <utility>
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
pair<int,int> floorCeilBSTHelper(Node* , int );

void Preorder(Node *root)
{
    if(root!=NULL)
    {
        printf("%d ",root->data);
        Preorder(root->left);
        Preorder(root->right);
    }
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
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&inp);
        root=insert_in_BST(root,inp);
    }
    pair<int,int> floor_n_ceil=floorCeilBSTHelper(root,11);
    cout<<11<<" "<<floor_n_ceil.first<<" "<<floor_n_ceil.second;
    cout<<"\nInorder: ";
    showBST(root);
    cout<<endl<<"Preorder: ";
    Preorder(root);
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

pair<int,int> floorCeilBSTHelper(Node* root, int key)
{
    int Floor=-1,Ceil=-1;

    while (root) {

        if (root->data == key) {
            Ceil = root->data;
            Floor = root->data;
            return {Floor,Ceil};
        }

        if (key > root->data) {
            Floor = root->data;
            root = root->right;
        }
        else {
            Ceil = root->data;
            root = root->left;
        }
    }

    return {Floor,Ceil};
}
