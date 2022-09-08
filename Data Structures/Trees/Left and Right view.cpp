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
void RightView(Node *, int , vector<int>& );      //! T.C.= O(n) 1 traversal       S.C.= O(h) {h->max height of tree} call stack space
void LeftView(Node *, int , vector<int>& );       //! T.C.= O(n) 1 traversal       S.C.= O(h) {h->max height of tree} call stack space

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

    //for right view
    int h=1;
    vector<int> rv;
    RightView(root,h,rv);
    for(int i: rv)
        cout<<i<<" ";
    cout<<endl;

    //for left view
    h=1;
    vector<int> lv;
    LeftView(root,h,lv);
    for(int i: lv)
        cout<<i<<" ";

    Free(root);
  return 0;
}
void RightView(Node *root, int h, vector<int>& v)     //! T.C.= O(n) 1 traversal       S.C.= O(h) {h->max height of tree} call stack space
{
    if(root==NULL)
        return ;

    if(h>v.size())
        v.push_back(0);
    v[h-1]=root->data;

    RightView(root->left, h+1,v);
    RightView(root->right, h+1, v);
}
void LeftView(Node *root, int h, vector<int>& v)    //! T.C.= O(n) 1 traversal       S.C.= O(h) {h->max height of tree} call stack space
{
    if(root==NULL)
        return ;

    if(h>v.size())
        v.push_back(-1);      //initializing vector element with a value which is not present in tree
    if(v[h-1]==-1)
        v[h-1]=root->data;

    LeftView(root->left, h+1,v);
    LeftView(root->right, h+1, v);
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
1 2 3 4 5 6 7 8 N N N 9 N N 10
*/
