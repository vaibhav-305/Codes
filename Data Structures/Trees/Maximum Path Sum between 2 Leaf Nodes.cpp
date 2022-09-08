/* Problem:
Given a binary tree in which each node element contains a number. Find the maximum possible path sum from one leaf node to another leaf node.
Note: Here Leaf node is a node which is connected to exactly one different node.
*/
//! T.C.= O(n)    S.C.= O(1)
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
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

Node * createTree(string );
int maxPathSum(Node *, int *, Node **);

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

    int sum=INT_MIN;
    Node *sumroot=NULL;
    int tempsum=maxPathSum(root,&sum,&sumroot);
    if(root->left==NULL || root->right==NULL){      //see below test case to understand this
        if(sum<tempsum){
            sum=tempsum;
            sumroot=root;
        }
    }

    cout<<sum<<" "<<sumroot->data<<"\n";
  return 0;
}
int maxPathSum(Node *root, int *sum, Node **sumnode)
{
    if(root==NULL)
        return INT_MIN;
    if(root->left==NULL && root->right==NULL)
        return root->data;

    int lsum=maxPathSum(root->left, sum, sumnode);
    int rsum=maxPathSum(root->right, sum, sumnode);

    int temp=max(lsum,rsum) + root->data;

    int Nthnodesum;
    if(lsum==INT_MIN || rsum==INT_MIN)
        Nthnodesum=INT_MIN;
    else
        Nthnodesum=lsum+rsum+root->data;
    if(*sum<Nthnodesum)
    {
        *sum=Nthnodesum;
        *sumnode=root;
    }
    return temp;
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
1 2 N 3 -3 4
        1
       /
      2         Ans=10  ( 1+2+3+4 )
     / \
    3  -3
   /
  4
1 2 -1 3 N N -2
        1
       / \
      2  -1      Ans:3  ( 3+2+1+(-1)+(-2) )
     /     \
    3      -2

-15 5 6 -8 1 3 9 2 -3 N N N N N 0 N N N N 4 -1 N N 10

           -15
         /      \
        5        6
      /  \      / \
    -8    1    3   9           Ans:27  (3 + 6 + 9 + 0 + -1 + 10 = 27)
   /  \             \
  2   -3             0
                    / \
                   4  -1
                      /
                     10
*/
