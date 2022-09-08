//! T.C.= O(h)+O(h)+O(h)      S.C.= O(h)   call stack     height/level of nodes/tree
#include <iostream>
using namespace std;
struct BSTNode {
    int data;
    BSTNode *left,*right;

    BSTNode(int x) {
        data = x;
        left = right = NULL;
    }
};

BSTNode * addItem(BSTNode *, int );
BSTNode * findLCA(BSTNode *, int , int );

void Inorder(BSTNode *root)
{
    if(root!=NULL)
    {
        Inorder(root->left);
        cout<<root->data<<" ";
        Inorder(root->right);
    }
}
bool searchBST(BSTNode *root, int val)   //T.C.= O(h)
{
    if(root==NULL)
        return false;

    if(root->data==val)
        return true;
    else if(root->data < val)
        return searchBST(root->right, val);
    else
        return searchBST(root->left, val);
}
void Free(BSTNode *root)
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
    BSTNode *root=NULL;
    int n,inp;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>inp;
        root=addItem(root,inp);
    }
    //Inorder(root);
    int n1, n2;
    cin>>n1>>n2;
    BSTNode *lcanode = findLCA(root,n1,n2);
    if(lcanode)
        cout<<lcanode->data;
    else
        cout<<"given nodes don't exist in tree";

    Free(root);
  return 0;
}
BSTNode * LCAhelper(BSTNode *root, int x, int y)    //T.C.= O(h)
{
    if(root==NULL)
        return NULL;

    // if both `x` and `y` are greater than the root, LCA exists in the right subtree
    else if(min(x,y) > root->data)
        return LCAhelper(root->right, x, y);

    // if both `x` and `y` is smaller than the root, LCA exists in the left subtree
    else if(max(x,y) < root->data)
        return LCAhelper(root->left, x, y);

    // if one key is greater (or equal) than the root and one key is smaller
    // (or equal) than the root, then the current node is LCA
    return root;
}
BSTNode * findLCA(BSTNode* root, int x, int y)
{
    // return if the tree is empty, or `x` or `y` is not present in the tree
    if (root == NULL || !searchBST(root, x) || !searchBST(root, y))
        return NULL;

    // `lca` stores the lowest common ancestor of `x` and `y`
    BSTNode* lca = LCAhelper(root, x, y);
    return lca;
}

BSTNode * addItem(BSTNode *root, int val)
{
    if(root==NULL){
        root=new BSTNode(val);
        return root;
    }
    else if(root->data > val)
        root->left = addItem(root->left, val);
    else
        root->right = addItem(root->right, val);

    return root;
}
/*
11
15 25 10 12 8 20 30 9 18 6 22
            15
           /  \
          /    \
         10    25          LCA(6, 12) = 10
        / \    / \         LCA(10, 12) = 10
       8  12  20  30       LCA(20,6) = 15
      / \     / \          LCA(18, 22) = 20
     6   9   18  22        LCA(30, 30) = 20
                           LCA(7, 20) = 7 doesn't exist in tree
*/
