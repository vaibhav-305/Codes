//T.c. O(n)   S.C.=O(n) (Recurs stack)
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;
struct Node {
    int data;
    Node *left,*right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

Node * createTree();
void showBST(Node *);
void Free(Node *root)
{
    if(root!=NULL)
    {
        Free(root->left);
        Free(root->right);
        delete root;
    }
}

void inorderCorrection(Node *root,Node *prev,Node **first,Node **mid, Node **last){
    if(root==nullptr)
        return;

    inorderCorrection(root->left,prev,first,mid,last);
    if(root->data < prev->data){
        if(*first==nullptr){
            *first=prev;
            *mid=root;
        }
        else
            *last=root;
    }
    prev=root;
    inorderCorrection(root->right,prev,first,mid,last);
}
void RecoverBST(Node *root){
    Node *first,*middle,*last,*prev;
    first=middle=last=nullptr;
    prev=new Node(-1e9);
    inorderCorrection(root,prev,&first,&middle,&last);
    if(first && last){
        cout<<"swap nodes: "<<first->data<<" "<<last->data<<"\n";
        swap(first->data,last->data);
    }
    else{
        cout<<"swap nodes: "<<first->data<<" "<<middle->data<<"\n";
        swap(first->data,middle->data);
    }
}
int main()
{
    Node *root=createTree();
    RecoverBST(root);
    showBST(root);
    Free(root);
  return 0;
}
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
void showBST(Node *root)
{
    if(root!=NULL)
    {
        showBST(root->left);
        cout<<root->data<<" ";
        showBST(root->right);
    }
}
/*
3 1 4 N N 2

        1
       / \
      3   4     (3 swapped with 2)
         /
        2
*/
