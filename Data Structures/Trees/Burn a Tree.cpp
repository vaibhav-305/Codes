//Problem : https://www.interviewbit.com/problems/burn-a-tree/
//! T.C.= O(n) [2 traversals]       S.C.= O(n) [hashmap + queue]
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

Node * createTree(string );
int Time_Taken_To_Burn_Tree(Node *root, int key);

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
int main()
{
    string s;
    getline(cin,s);
    Node *root=createTree(s);
    //Inorder(root);
    int key;
    cin>>key;

    cout<<Time_Taken_To_Burn_Tree(root,key);
    Free(root);
  return 0;
}
int Time_Taken_To_Burn_Tree(Node *root, int key)
{
    if(root==NULL || (root->left==NULL && root->right==NULL))
        return 0;

    unordered_map<int,Node*> parent;
    parent[root->data]=NULL;

    Node *temp,*first;
    queue<Node*> Q;
    Q.push(root);
    while(!Q.empty())
    {
        temp=Q.front();
        Q.pop();

        if(temp->data==key)        //to find the first node from where the fire would start
            first=temp;

        if(temp->left != NULL){
            parent[temp->left->data]=temp;
            Q.push(temp->left);
        }
        if(temp->right != NULL){
            parent[temp->right->data]=temp;
            Q.push(temp->right);
        }
    }

    Node *parentnode,*lc,*rc;
    int timetaken=0,sz;
    //we'll do DFS and for visited[] array we will use our parent[]
    Q.push(first);
    while(!Q.empty())
    {
        sz=Q.size();
        while(sz--)
        {
            temp=Q.front();
            Q.pop();

            parentnode=parent[temp->data];
            if(parentnode!=NULL && parent.find(parentnode->data)!=parent.end())
                Q.push(parentnode);

            lc=temp->left;
            if(lc!=NULL && parent.find(lc->data)!=parent.end())
                Q.push(lc);

            rc=temp->right;
            if(rc!=NULL && parent.find(rc->data)!=parent.end())
                Q.push(rc);

            parent.erase(temp->data);
        }
        timetaken++;
    }
    return timetaken-1;
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
