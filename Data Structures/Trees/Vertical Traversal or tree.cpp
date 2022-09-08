//! T.C.= O(n*log(n))      S.C.= O(n)  as we are using map
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <map>
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
vector<vector<int>> verticalOrderTraversal(Node *);

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

    vector<vector<int>> ans = verticalOrderTraversal(root);
    for(vector<int> v:ans){
        for(int i: v)
            cout<<i<<" ";
        cout<<"\n";
    }

    Free(root);
  return 0;
}
vector<vector<int>> verticalOrderTraversal(Node *root)
{
    if(root==nullptr)
        return {};

    // key -> position
    // value -> vector to store the node values
    map<int,vector<int>> M;

    queue<pair<Node*,int>> Q;
    Q.push(make_pair(root, 0));       //we'll consider the position of root as 0
    pair<Node*,int> temp;
    Node *tempnode;
    while(!Q.empty())
    {
        temp=Q.front();
        Q.pop();

        tempnode=temp.first;
        M[temp.second].push_back(tempnode->data);

        if(tempnode->left != nullptr)
            Q.push(make_pair(tempnode->left, temp.second-1));
        if(temp.first->right != nullptr)
            Q.push(make_pair(tempnode->right, temp.second+1));
    }

    vector<vector<int>> ans(M.size());
    int x=0;
    for(pair<int,vector<int>> p: M)
    {
        for(int i: p.second)
            ans[x].push_back(i);
        x++;
    }
    return ans;
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
6 3 7 2 5 N 9

1 2 3 N 4 N N N 5
*/
