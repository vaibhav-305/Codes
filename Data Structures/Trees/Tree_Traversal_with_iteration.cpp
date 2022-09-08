#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
// for implementing iterative traversal f trees, we use stack
#include <stack>
#include <unordered_set>
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
void Inorder_iter(Node *);
void Preorder_iter(Node *);
void Postorder_iter(Node *);

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
    cout<<"Inorder: ";
    Inorder_iter(root);
    cout<<endl<<"Preorder: ";
    Preorder_iter(root);
    cout<<endl<<"Postorder: ";
    Postorder_iter(root);
    Free(root);
  return 0;
}
void Inorder_iter(Node *root)
{
    stack<Node*> S;
    Node *curr=root;
    while(curr!=nullptr || !S.empty())       //nullptr is same as null
    {
        // if the current node exists, push it into the stack and move to its left child
        if(curr!=NULL)
        {
            S.push(curr);
            curr=curr->left;
            continue;
        }
        // otherwise, if the current node is null, pop an element from the stack,
        // print it, and finally set the current node to its right child
        curr=S.top();
        S.pop();
        cout<<curr->data<<" ";

        curr=curr->right;
    }

}
void Preorder_iter(Node *root)
{
    stack<Node*> S;
    Node *curr=root;
    while(curr!=NULL || !S.empty())
    {
        if(curr!=NULL){
            cout<<curr->data<<" ";
            S.push(curr);

            // after printing push the left node in stack
            curr=curr->left;
            continue;
        }

        // if curr=NULL that means we have traversed and printed left part, so now move on to right part
        curr=S.top();
        S.pop();

        curr=curr->right;
    }
}
void Postorder_iter(Node *root)
{
    stack<Node*> S;
    Node *curr=root,*rightchild;
    while(curr!=NULL || !S.empty())
    {
        if(curr!=nullptr){
            S.push(curr);
            curr=curr->left;
            continue;
        }

        rightchild=S.top().right;
        if(rightchild!=NULL){
            curr=rightchild;
            continue;
        }else {

        }


    }
    /*if(root!=NULL)
    {
        Postorder_iter(root->left);
        Postorder_iter(root->right);
        cout<<root->data<<" ";
    }*/
}

Node * createTree(string str){
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
