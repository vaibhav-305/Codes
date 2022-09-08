// Also known as Zigzag traversal
//! T.C.= O(n)      S.C.= O(n)
#include <iostream>
#include <stack>
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

Node * createTree(int *,int );
void spiral_traversal(Node *);          //using 2 stacks
void ZigZagTraversal(Node *);           //using 1 deque

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
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    Node *root=createTree(arr,n);
    cout<<"Spiral order:\n";
    spiral_traversal(root);     //using 2 stacks
    cout<<endl;
    ZigZagTraversal(root);    //Using 1 deque
    Free(root);
  return 0;
}
void spiral_traversal(Node *root)      /// Using 2 Stacks
{
    if(root==NULL)
        return;

    Node *nod;
    stack<Node*> S1,S2;
    S1.push(root);
    while(S1.size()!=0 || S2.size()!=0)
    {
        while(!S1.empty())
        {
            cout<<S1.top()->data<<" ";
            nod=S1.top();
            S1.pop();

            if(nod->left!=NULL)
                S2.push(nod->left);
            if(nod->right!=NULL)
                S2.push(nod->right);
        }
        while(!S2.empty())
        {
            cout<<S2.top()->data<<" ";
            nod=S2.top();
            S2.pop();

            if(nod->right!=NULL)
                S1.push(nod->right);
            if(nod->left!=NULL)
                S1.push(nod->left);
        }
    }
}
void ZigZagTraversal(Node *root)       /// Using 1 Deque
{
    if(root==NULL)
        return ;

    deque<Node*> Dq;
    Dq.push_back(root);
    Node *temp;
    int n;
    bool isEven=false;        //considering root as lvl=1 (i.e. odd)
    while(!Dq.empty())
    {
        n=Dq.size();
        while(n--)
        {
            if(isEven){
                temp=Dq.back();
                Dq.pop_back();
                cout<<temp->data<<" ";
                if(temp->right!=NULL)
                    Dq.push_front(temp->right);
                if(temp->left!=NULL)
                    Dq.push_front(temp->left);
                continue;
            }
            else {
                temp=Dq.front();
                Dq.pop_front();
                cout<<temp->data<<" ";
                if(temp->left!=NULL)
                    Dq.push_back(temp->left);
                if(temp->right!=NULL)
                    Dq.push_back(temp->right);
                continue;
            }
        }
        isEven= (!isEven);
    }
}
Node * createTree(int *arr,int n)
{
    if(n==0 || (n==1 && arr[0]==-1))
        return NULL;
    int fir,sec,indx=0;
    queue<Node*> Q;
    Node *root=new Node(arr[0]);
    Node *l,*r;
    Q.push(root);
    indx=indx+1;
    while(indx<n)
    {
        fir=indx;
        indx=indx+1;
        sec=indx;
        if(arr[fir]!=-1)
            l=new Node(arr[fir]);
        else
            l=NULL;
        if(sec==n)
            r=NULL;
        else{
                if(arr[sec]==-1)
                    r=NULL;
                else
                    r=new Node(arr[sec]);
            indx=indx+1;
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
15
1 2 3 4 5 6 7 8 9 -1 -1 10 -1 -1 11
*/
