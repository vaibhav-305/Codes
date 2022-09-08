// The diameter of a tree is the number of nodes on the longest path between two leaves in the tree. Longest path may or may not pass through root node.
// (note that there may be more than one path in the tree of the same diameter)
//! T.C.= O(n)     S.C.= O(1)
#include <iostream>
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
int diameterOfTree(Node *, int *,Node **);

void Inorder(Node *root)
{
    if(root!=NULL)
    {
        Inorder(root->left);
        cout<<root->data<<" ";
        Inorder(root->right);
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
    //Inorder(root);
    //cout<<endl;
    int d=0;
    Node *droot=NULL;
    diameterOfTree(root,&d,&droot);
    cout<<d<<" "<<droot->data<<"\n";
  return 0;
}
Node * createTree(int *arr,int n)
{
    // Your code here
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
int diameterOfTree(Node *root, int *d,Node **droot)
{
    if(root==NULL)
        return 0;

    int lh=diameterOfTree(root->left,d,droot);
    int rh=diameterOfTree(root->right,d,droot);

    if(*d < lh+rh+1){
        *d=lh+rh+1;
        *droot=root;
    }

    return max(lh,rh)+1;
}
/*
22
1 2 3 4 5 -1 -1 6 7 -1 8 -1 -1 9 -1 10 11 -1 12 -1 -1 13
*/
