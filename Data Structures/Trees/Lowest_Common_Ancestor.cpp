//T.C.=O(n) (one traversal)
//S.C.=O(1)
//dataset: 1 2 3 4 5 6 7 8 9 -1 -1 10 -1 11
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

Node * createTree(int *,int);
Node * LCA(Node *,int,int);

void Preorder(Node *root)
{
    if(root!=NULL)
    {
        cout<<root->data<<" ";
        Preorder(root->left);
        Preorder(root->right);
    }
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
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    Node *root=createTree(arr,n);
    Inorder(root);
    cout<<endl;
    Preorder(root);
    cout<<endl;
    Node *node=LCA(root,3,11);
    if(node==NULL)
        cout<<"NOT EXIST"<<endl;
    else
        cout<<node->data<<endl;
    Free(root);
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
Node *LCAhelper(Node *root,int n1,int n2,bool &b1,bool &b2)
{
    if(root==NULL)
        return NULL;
    if(root->data == n1)
    {
        b1 = true;
        return root;
    }
    if(root->data == n2)
    {
        b2 = true;
        return root;
    }

    Node *leftSearchResult=LCAhelper(root->left,n1,n2,b1,b2);
    Node *rightSearchResult=LCAhelper(root->right,n1,n2,b1,b2);

    if(leftSearchResult==NULL)
        return rightSearchResult;
    if(rightSearchResult==NULL)
        return leftSearchResult;

    return root; //if both leftSearchResult and rightSearchResult are not NULL
}
bool find_otherone_beneath(Node *root,int k)
{
    if(root==NULL)
        return false;
     // If key is present at root, or in left subtree or right subtree,
    // return true;
    if (root->data == k || find_otherone_beneath(root->left, k) ||  find_otherone_beneath(root->right, k))
        return true;

    // Else return false
    return false;
}
Node * LCA(Node *root,int n1,int n2)
{

    bool b1=false,b2=false;
    Node *lcaNode=LCAhelper(root,n1,n2,b1,b2);

    if(b1==true && b2==true) //one is at left subtree and one is at right subtree of a node
        return lcaNode;

    else if((b1 && find_otherone_beneath(root,n2)) || (b2 && find_otherone_beneath(root,n1))) //to check if one is the parent of the other
        return lcaNode;

    else     //not found 1 node r both nodes
        return NULL;
}
