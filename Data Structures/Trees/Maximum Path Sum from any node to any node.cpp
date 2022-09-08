// Given a binary tree, write an efficient algorithm to find the maximum path sum between any two nodes in it. The path can start and end at any node in the tree and need not go through the root.
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
    maxPathSum(root,&sum,&sumroot);
    cout<<sum<<" "<<sumroot->data<<"\n";
  return 0;
}
int maxPathSum(Node *root, int *sum, Node **sumnode)
{
    if(root==NULL)
        return 0;

    int lsum=maxPathSum(root->left, sum, sumnode);
    int rsum=maxPathSum(root->right, sum, sumnode);
                                                           //                                N      N          N           N
    int temp= max(max(lsum,rsum)+root->data, root->data);  //possibilities of getting sum:  /   or   \    or        or    / \      (the first 3's max will be returned and max of all 4 will be stored in answer for further comparisons)
    int Nthnodesum=max(temp,lsum+rsum+root->data);         //                             lsum      rsum               lsum  rsum
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
-10 9 20 N N 15 7

-6 -5 N -2 -10 -7 N N N -8 -9

-6 3 N 2 -10 -7 N N N -8 -9
*/
