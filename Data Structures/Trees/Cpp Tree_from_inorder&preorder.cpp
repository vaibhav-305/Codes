//T.C.=S.C.=O(n)
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
struct Node{
    int data;
    Node *left,*right;
    Node(int val){
        data=val;
        left=right=nullptr;
    }
};

Node * buildTree(int l,int r,vector<int>& inorder,int &pIndx,vector<int>& preorder,unordered_map<int,int>& M){
    if(l>r)
        return nullptr;

    Node *newNode=new Node(preorder[pIndx++]);
    int pos=M[newNode->data];

    newNode->left=buildTree(l,pos-1,inorder,pIndx,preorder,M);
    newNode->right=buildTree(pos+1,r,inorder,pIndx,preorder,M);

    return newNode;
}
Node * createTree(vector<int>&inorder, vector<int>& preorder){
    int n=inorder.size();
    unordered_map<int,int> M;
    for(int i=0;i<n;i++){
        M[inorder[i]]=i;
    }
    // `preIndex` stores the index of the next unprocessed node in preorder; start with the root node (present at 0th index)
    ///passed by reference

    int preIndx=0;
    return buildTree(0,n-1,inorder,preIndx,preorder,M);
}
void postorder(Node* root){
    if(root!=nullptr){
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }
}
int main()
{
    int n;
    cin>>n;
    vector<int> inorder(n),preorder(n);
    for(int i=0;i<n;i++)
        cin>>inorder[i];
    for(int i=0;i<n;i++)
        cin>>preorder[i];

    Node *root=createTree(inorder,preorder);
    postorder(root);
  return 0;
}
/*
8
4 2 1 7 5 8 3 6
1 2 4 3 5 7 8 6
               1
             /   \
            /     \
           2       3
          /       / \
         /       /   \
        4       5     6
               / \
              /   \
             7     8

*/
