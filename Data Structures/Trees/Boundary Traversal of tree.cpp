//! T.C.= O(h)+O(h)+O(n)        S.C.= O(n)      h->height of binary tree
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
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
void addLeftBoundary(Node *, vector<int>& );
void addLeafnodes(Node *, vector<int>& );
void addRightBoundary(Node *, vector<int>& );

bool isLeaf(Node *temp)
{
    if(temp->left==NULL && temp->right==NULL)
        return true;
    else
        return false;
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

    //for boundary traversal
    vector<int> res;
    if(!isLeaf(root))
        res.push_back(root->data);    //storing root node value
    addLeftBoundary(root,res);
    addLeafnodes(root,res);
    addRightBoundary(root,res);
    for(int i:res)
        cout<<i<<" ";

    Free(root);
  return 0;
}
void addLeftBoundary(Node *root, vector<int>& res)
{
    Node *curr=root->left;
    while(curr!=NULL)
    {
        if(!isLeaf(curr))
            res.push_back(curr->data);

        if(curr->left!=NULL)
            curr=curr->left;
        else
            curr=curr->right;
    }
}
void addRightBoundary(Node *root, vector<int>& res)
{
    stack<int> S;       //as we need to push values in reverse order for boundary traversal(because we are going from bottom leaf to top root node)
    Node *curr=root->right;
    while(curr!=NULL)
    {
        if(!isLeaf(curr))
            S.push(curr->data);

        if(curr->right!=NULL)
            curr=curr->right;
        else
            curr=curr->left;
    }
    while(!S.empty()){
        res.push_back(S.top());
        S.pop();
    }
}
void addLeafnodes(Node *root, vector<int>& res){
    //we do inorder traversal here
    if(root!=NULL)
    {
        addLeafnodes(root->left,res);
        if(isLeaf(root))
            res.push_back(root->data);
        addLeafnodes(root->right,res);
    }
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
    inp.clear();
  return root;
}
/*
1 2 3 N N 4 6 N 5 N N 7 N
        1
       / \
      2   3
         / \
        4   6           Ans: 1 2 7 6 3
         \
          5
         /
        7

1 2 N N 3 4
        1
       /
      2
       \        Ans: 1 2 3 4
        3
       /
      4
*/
