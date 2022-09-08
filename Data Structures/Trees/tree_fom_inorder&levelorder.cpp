//! O(N*N) T.C & O(N) S.C.
#include <iostream>
#include <unordered_set>
#include <new>
using namespace std;

typedef struct treenode
{
    int data;
    struct treenode *right,*left;

    treenode(int val)
    {
        data=val;
        right=NULL;
        left=NULL;
    }
}Node;

Node * createTree(int *,int *,int,int,int);

void Preorder(Node *root)
{
    if(root!=NULL)
    {
        cout<<root->data<<" ";
        Preorder(root->left);
        Preorder(root->right);
    }
}
int main()
{
    int n;
    cin>>n;
    int ino[n],lvlord[n];
    for(int i=0;i<n;i++)
        cin>>ino[i];
    for(int i=0;i<n;i++)
        cin>>lvlord[i];
    Node *root=createTree(ino,lvlord,0,n-1,n);
    Preorder(root);
  return 0;
}
int searchIno(int *ino,int start,int endi,int temp)
{
    for(int i=start;i<=endi;i++)
    {
        if(ino[i]==temp)
            return i;
    }
}
Node * createTree(int *ino,int *lvlord,int start,int endi,int n)
{
    if(start>endi)
        return NULL;
    int temp;
    unordered_set<int> M;
    for(int i=start;i<=endi;i++)
        M.insert(ino[i]);
    for(int i=0;i<n;i++)
    {
        if(M.find(lvlord[i])!=M.end())
            {
                temp=lvlord[i];
                break;
            }
    }
    Node *new_node=new Node(temp);

    if(start==endi)
        return new_node;

    int loc=searchIno(ino,start,endi,temp);
    new_node->left=createTree(ino,lvlord,start,loc-1,n);
    new_node->right=createTree(ino,lvlord,loc+1,endi,n);

    return new_node;
}
