//! T.C.= O(n)  1 traversal      S.C.= O(1)
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
using namespace std;
struct Node
{
    int data;
    Node *left,*right,*next;

    Node(int x)
    {
        data = x;
        left = right = next = NULL;
    }
};

Node * createTree(string );
void connect(Node *);

void LeftView(Node *root, int h, vector<Node*>& v)    //! T.C.= O(n) 1 traversal       S.C.= O(h) {h->max height of tree} call stack space
{
    if(root==NULL)
        return ;

    if(h>v.size())
        v.push_back(root);      //initializing vector element with a value which is not present in tree

    LeftView(root->left, h+1,v);
    LeftView(root->right, h+1, v);
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

    connect(root);

    //for checking the answer
    int h=1;
    vector<Node*> lv;
    LeftView(root,h,lv);
    for(Node *tmp: lv)
    {
        while(tmp!=nullptr)
        {
            cout<<tmp->data<<" ";
            tmp=tmp->next;
        }
        cout<<"\n";
    }
    Free(root);
    return 0;
}
void connect(Node *root)
{
    Node* leftWall = NULL; // leftmost node of the next level.
    Node* prev = NULL; // leading node on the next level
    Node* curr = root; // current node on the current level

    while(curr != NULL)          //for traversing one level to next level
    {
        while(curr != NULL)         //for traversing that whole current level
        {
            if(curr->left != NULL)
            {
                if(prev == NULL)
                    leftWall = curr->left;
                else
                    prev->next = curr->left;

                prev = curr->left;
            }

            if(curr->right != NULL)
            {
                if(prev == NULL)
                    leftWall = curr->right;
                else
                    prev->next = curr->right;

                prev = curr->right;
            }
            // move to the next node
            curr = curr->next;
        }
        // move to the next level
        curr = leftWall;
        leftWall = NULL;
        prev = NULL;
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
        else
        {
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
