/**
A Tree is BST if following is true for every node x.
  1. The largest value in left subtree (of x) is smaller than value of x.
  2. The smallest value in right subtree (of x) is greater than value of x.
  3. Both the left and right subtrees must also be binary search trees.
To determine if a subtree rooted under a node is a BST or not, the left subtree should provide information about the maximum value
in it. The right subtree should provide information about the minimum value in it. Also, the parent node should be notified when
both left and right child are also BST. Do it recursively in top-down manner.
For root begin with largest as INT_MIN and smallest as INT_MAX
*/
//! T.C.= O(n)  S.C.= O(h) recursion stack space
//Another approach would be to check if the inorder of tree is sorted or not. If inorder is sorted then the tree is BST, otherwise not BST.
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <climits>    //for LONG_MAX and LONG_MIN
using namespace std;
struct Node {
    int data;
    Node *left,*right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};
struct NodeInfo{
    int maxNode,minNode;
};

Node * createTree(string );
bool isBST(Node *,long ,long );

void Inorder(Node *root)
{
    if(root!=NULL)
    {
        Inorder(root->left);
        cout<<root->data<<" ";
        Inorder(root->right);
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
    string s;
    getline(cin,s);
    Node *root=createTree(s);

    bool ans=isBST(root,LONG_MIN,LONG_MAX);
    if(ans)
        cout<<"true";
    else
        cout<<"false";
    Free(root);
  return 0;
}
bool isBST(Node *root,long minNodeVal,long maxNodeVal){
    if(root==NULL)
        return true;

    if(root->data >= maxNodeVal || root->data <= minNodeVal)
        return false;

    return isBST(root->left,minNodeVal,root->data) & isBST(root->right,root->data,maxNodeVal);
}
Node * createTree(string str)
{
    if(str.length()==0 || str[0]=='N')
        return NULL;

    vector<string> inp;

    istringstream iss(str);
    for(string s; iss>>s;)
        inp.push_back(s);

    int n=inp.size();

    int fir,sec,indx=0;
    queue<Node*> Q;
    Node *root=new Node(stoi(inp[0]));
    Node *l,*r;
    Q.push(root);
    indx=indx+1;
    while(indx<n)
    {
        fir=indx;
        indx++;
        sec=indx;
        //left child
        if(inp[fir]!="N")
            l=new Node(stoi(inp[fir]));
        else
            l=NULL;
        //right child
        if(sec==n)
            r=NULL;
        else{
            if(inp[sec]=="N")
                r=NULL;
            else
                r=new Node(stoi(inp[sec]));

            indx++;
        }
        Q.front()->left=l;
        Q.front()->right=r;
        if(l!=NULL)
            Q.push(l);
        if(r!=NULL)
            Q.push(r);
        Q.pop();
    }
    return root;
}
/*
Demo working:
                13 [-INF,INF]      12->[10,13]
              /    \               14->[13,15]
  [-INF,13] 10      15 [13,INF]
           /  \    /  \                As all node values are satisfied
[-INF,10] 7   12  14  17 [15,INF]      in the range[minNodeVal,maxNodeVal]
           \         /                 it is a valid BST.
     [7,10] 9       16 [15,17]      If we replace 12 by 14 , then node val
           /                        will be out of range, so it will not be a
          8 [7,9]                   BST
5 1 4 N N 3 6
ans: false

2 1 3
ans: true

5 4 6 N N 3 7
false
*/
