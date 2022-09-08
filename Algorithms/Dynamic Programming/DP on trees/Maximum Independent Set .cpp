//! T.C.=O(N)
//Link: https://www.techiedelight.com/maximum-independent-set-problem/
#include <bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node *left,*right;
    Node(int d){
        data=d;
        left=right=nullptr;
    }
};
Node * createTree();
void Inorder(Node *);
void Free(Node *);


int MISsize(Node *root)
{
    if(root==nullptr)
        return 0;
    if(root->left==nullptr && root->right==nullptr)
        return 1;

    int notInclude = MISsize(root->left)+MISsize(root->right);
    int include = 1;
    if(root->left!=nullptr)
        include+=MISsize(root->left->left)+MISsize(root->left->right);
    if(root->right!=nullptr)
        include+=MISsize(root->right->left)+MISsize(root->right->right);

    return max(notInclude,include);
}
int main()
{
    Node *root=createTree();
    //Inorder(root);
    cout<<MISsize(root);
    Free(root);
  return 0;
}
/*
1 2 3 4 N 5 6 N N 7 8
Ans: 5
*/
Node * createTree()
{
    string str;
    getline(cin,str);
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
