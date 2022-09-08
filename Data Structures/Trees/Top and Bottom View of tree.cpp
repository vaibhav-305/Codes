//! T.C.= O(n*log(n))  as we have used map       S.C.= O(width of tree)
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <map>     //for top/bottom view
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
void TopView_recursive(Node *, int , int , map<int,pair<int,int>>& );
void BottomView_recursive(Node *, int , int , map<int,pair<int,int>>& );

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

    ///top view of binary tree Recursive approach (for iterative approach, we can do level order traversal which will take care of levels itself)
    // key -> relative horizontal distance of the node from the root node, and
    // value -> pair containing the node's value and its level
    map<int,pair<int,int>> Tv;
    TopView_recursive(root,0,0,Tv);            //we would consider root position as origin, so distance is 0
    for(pair<int,pair<int,int>> p: Tv)
        cout<<(p.second).first<<" ";
    cout<<endl;

    ///Bottom view of binary tree Recursive approach (for iterative approach, we can do level order traversal which will take care of levels itself)
    //If there are multiple bottom-most nodes for a horizontal distance from root, then print the later one in level traversal.

    // key -> relative horizontal distance of the node from the root node, and
    // value -> pair containing the node's value and its level
    map<int,pair<int,int>> Bv;
    BottomView_recursive(root,0,0,Bv);            //we would consider root position as origin, so distance is 0
    for(pair<int,pair<int,int>> p: Bv)
        cout<<(p.second).first<<" ";

    Free(root);
  return 0;
}
void TopView_recursive(Node *root, int h, int pos, map<int,pair<int,int>>& Tv)
{
    if(root==nullptr)
        return ;

    if(Tv.find(pos)==Tv.end() || Tv[pos].second>h)      //! we need to check height too for TopView(see the example testcase below)
        Tv[pos]=make_pair(root->data, h);

    TopView_recursive(root->left, h+1, pos-1, Tv);
    TopView_recursive(root->right, h+1, pos+1, Tv);
}
void BottomView_recursive(Node *root, int h, int pos, map<int,pair<int,int>>& Bv)
{
    if(root==nullptr)
        return ;

    if(Bv[pos].second <=h)      //! we only need to check height for BottomView so that we take the deeper nodes (see the example testcase below); we have used '<=' because we need to get the later nodes of same level/pos in level order traversal
        Bv[pos]=make_pair(root->data, h);

    BottomView_recursive(root->left, h+1, pos-1, Bv);
    BottomView_recursive(root->right, h+1, pos+1, Bv);
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
         1
        / \
       2   3
        \
         4
          \
           5
1 2 3 N 4 N N N 5
*/
