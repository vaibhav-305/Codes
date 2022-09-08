//! T.C.= O(h) (log(n) if balanced BST)    S.C.= O(1)
// Key may or may not be present in BST
#include <iostream>
#include <utility>
using namespace std;
struct Node
{
    int data;
    Node *left,*right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

Node * insert_in_BST(Node *,int);
pair<int,int> findPreSuc(Node*, int);

void showBST(Node *root)
{
    if(root!=NULL)
    {
        showBST(root->left);
        printf("%d ",root->data);
        showBST(root->right);
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
    Node *root=NULL;
    int n,inp;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>inp;
        root=insert_in_BST(root,inp);
    }
    int key;
    cin>>key;

    pair<int,int> pre_n_suc=findPreSuc(root,key);
    cout<<key<<" "<<pre_n_suc.first<<" "<<pre_n_suc.second;

    Free(root);
    return 0;
}

pair<int,int> findPreSuc(Node* root, int key)
{
    Node *suc,*pre;
    int a=-1,b=-1;

    if(root == NULL)
        return {a,b};

    // Search for given key in BST.
    while (root != NULL)
    {
        // If root is given key.
        if (root->data == key)
        {
            // the minimum value in right subtree is predecessor.
            if (root->right){
                suc = root->right;
                while (suc->left)
                    suc = suc->left;
            }
            // the maximum value in left subtree is successor.
            if (root->left){
                pre = root->left;
                while (pre->right)
                    pre = pre->right;
            }
            if(pre!=NULL)
                a=pre->data;
            if(suc!=NULL)
                b=suc->data;
            return {a,b};
        }

        // If key is greater than root, then key lies in right subtree. Root could be predecessor if left subtree of key is null.
        else if (root->data < key){
            pre = root;
            root = root->right;
        }

        // If key is smaller than root, then key lies in left subtree. Root could be successor if right subtree of key is null.
        else{
            suc = root;
            root = root->left;
        }
    }
    if(pre!=NULL)
        a=pre->data;
    if(suc!=NULL)
        b=suc->data;
    return {a,b};
}
Node * insert_in_BST(Node *root,int val)
{
    if(root==NULL)
    {
        root=new Node(val);
        return root;
    }
    else if(root->data>val)
        root->left=insert_in_BST(root->left,val);
    else
        root->right=insert_in_BST(root->right,val);

    return root;
}
