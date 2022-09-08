/* In this we'll use 2 pointer approach. for this we'll need BST_iterator's next() and before() func as we know that next() is
   basically inorder traversal(ascending order) and before gives reverse-inorder(descending order).
   We'll use next() and before() 's values for 2-pointer approach and will do until next()'s value is less than before's value
*/
//! T.C.= O(n)      S.C.= O(h)+O(h)
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>   //for BST iterator
using namespace std;
using llt=long long int;
struct Node {
    int data;
    Node *left,*right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

Node * createTree(string );
void findTargetsumNodes(Node *root, llt sum);

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
    llt sum;
    cin>>sum;
    findTargetsumNodes(root,sum);
    Free(root);
  return 0;
}
int next(stack<Node*>& Front)
{
    if(Front.empty()){
        cout<<"Empty stack\n";
        return -1;
    }
    Node *x=Front.top();
    Front.pop();
    if(x->right!=NULL){
        Node *y=x->right;
        while(y!=NULL){
            Front.push(y);
            y=y->left;
        }
    }
    return x->data;
}
int before(stack<Node*>& Back)
{
    if(Back.empty()){
        cout<<"Empty stack\n";
        return -1;
    }
    Node *x=Back.top();
    Back.pop();
    if(x->left!=NULL){
        Node *y=x->left;
        while(y!=NULL){
            Back.push(y);
            y=y->right;
        }
    }
    return x->data;
}
void findTargetsumNodes(Node *root, llt sum)
{
    stack<Node*> Front;
    stack<Node*> Back;
    Node *temp;

    /// step1: initializing iterator
    temp=root;
    while(temp!=NULL){
        Front.push(temp);
        temp=temp->left;
    }
    temp=root;
    while(temp!=NULL){
        Back.push(temp);
        temp=temp->right;
    }

    /// step2: 2 pointer approach
    llt l=(llt)next(Front);
    llt r=(llt)before(Back);
    while(l<r)
    {
        if(l+r==sum){
            cout<<l<<" "<<r;
            return;
        }
        else if(l+r<sum)
            l=next(Front);
        else
            r=before(Back);
    }
    cout<<"Sum not found";
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
5 3 6 2 4 N 7
9

0 -3 2 -4 N 1
1
*/
