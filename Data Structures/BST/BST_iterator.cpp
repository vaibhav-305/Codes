// soln link: https://www.youtube.com/watch?v=D2jMcmxU4bs (take U forward channel BST iterator video)
/* Basically here first we push root node and all left nodes(root->left) in stack.
 * Then when next() is called we pop the top of stack, and check if St.top() node has any right child or not, if it has then push St.top()->right all the left of St.top()->right (st.top().right->left) and return St.top() value;
 * If hasNext() is called simply check if Stack is empty or not, if it is empty , then that means there is no next node so return false, and if Stack is not empty, return true.
 ** next() basically gives inorder traversal.
*/
//! T.C.= O(1)    S.C.= O(h) h->height of tree
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>   //for BST iterator
using namespace std;
struct Node {
    int data;
    Node *left,*right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

Node * createTree(string );

stack<Node*> St;
void intitalize_BSTiterator(Node *root)
{
    while(root!=NULL){
        St.push(root);
        root=root->left;
    }
}
int next()
{
    if(St.empty()){
        cout<<"Empty stack\n";
        return -1;
    }
    Node *x=St.top();
    St.pop();
    if(x->right!=NULL){
        Node *y=x->right;
        while(y!=NULL){
            St.push(y);
            y=y->left;
        }
    }
    return x->data;
}
bool hasNext(){
    return !St.empty();
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

    intitalize_BSTiterator(root);
    cout<<"***************\nType:\n 1 -> next()\n 2 -> hasNext()\n 3 -> exit\n***************\n";
    int i;
    while(true){
        cin>>i;
        if(i==1)
            cout<<next()<<"\n";
        else if(i==2){
            if(hasNext())
                cout<<"true\n";
            else
                cout<<"false\n";
        }
        else
            break;
    }
    Free(root);
  return 0;
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
7 3 15 N N 9 20
1 1 2 1 2 1 2 1 2 3
o/p:
3
7
true
9
true
15
true
20
false
*/
