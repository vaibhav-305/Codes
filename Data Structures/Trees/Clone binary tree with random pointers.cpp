//! T.C.= O(n)   2 traversals         S.C.= O(n)   hashmap
#include <iostream>
#include <unordered_map>
using namespace std;
struct Node
{
    int data;
    Node *left,*right,*random;

    Node(int x)
    {
        data = x;
        left = right = random = NULL;
    }
};

Node * cloneTree(Node * );

void Inorder(Node *root)
{
    if(root!=NULL)
    {
        Inorder(root->left);
        cout<<root<<"=>"<<root->data<<"->";
        if(root->random!=NULL)
            cout<<root->random->data<<"  ";
        else
            cout<<"NULL  ";
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
    Node *root = new Node(10);
    Node *n2 = new Node(6);
    Node *n3 = new Node(12);
    Node *n4 = new Node(5);
    Node *n5 = new Node(8);
    Node *n6 = new Node(11);
    Node *n7 = new Node(13);
    Node *n8 = new Node(7);
    Node *n9 = new Node(9);
    root->left = n2;
    root->right = n3;
    root->random = n2;
    n2->left = n4;
    n2->right = n5;
    n2->random = n8;
    n3->left = n6;
    n3->right = n7;
    n3->random = n5;
    n4->random = n9;
    n5->left = n8;
    n5->right = n9;
    n5->random = root;
    n6->random = n9;
    n9->random = n8;
    Inorder(root);
    cout<<"\n";

    Node *new_root=cloneTree(root);
    Inorder(new_root);

    Free(root);
    Free(new_root);
    return 0;
}
Node * cloneLeftRightNode(Node *root,unordered_map<int,Node*>& M)
{
    if(root==NULL)
        return NULL;

    Node *newnode = new Node(root->data);
    M[root->data] = newnode;
    newnode->left = cloneLeftRightNode(root->left, M);
    newnode->right = cloneLeftRightNode(root->right, M);
  return newnode;
}
void copyRandom(Node *root, Node *newroot, unordered_map<int,Node*>& M)
{
    if(root==NULL)
        return ;

    if(root->random!=NULL)
        M[root->data]->random = M[root->random->data];

    copyRandom(root->left, newroot->left, M);
    copyRandom(root->right, newroot->right, M);
}
Node * cloneTree(Node * root)
{
    /// 1. First traverse the original tree and we'll clone tree without random-pointers and hash all the nodes with their node values
    /// 2. Then we'll again traverse the original tree and assign the random pointers accordingly

    // Applying Preorder traversal (DFS)
    unordered_map<int,Node*> M;
    Node *newroot = cloneLeftRightNode(root,M);

    //Applying DFS again to assign random pointers values
    copyRandom(root,newroot,M);

    return newroot;
}

/*                   Random pointers :-
             1          1->5
            / \         4->1
           2   3        5->3
          / \         Rest pointing to NULL
         4   5
Node *root = new Node(1);
root->left = new Node(2);
root->right = new Node(3);
root->left->left = new Node(4);
root->left->right = new Node(5);
root->random = root->left->right;
root->left->left->random = root;
root->left->right->random = root->right;

              10            Random pointers
            /   \              5->9
           6     12            6->7
          / \    / \           8->10
         5   8  11  13         9->7
            / \               10->6
           7   9              11->9
                              12->8
Node *root = new Node(10);
Node *n2 = new Node(6);
Node *n3 = new Node(12);
Node *n4 = new Node(5);
Node *n5 = new Node(8);
Node *n6 = new Node(11);
Node *n7 = new Node(13);
Node *n8 = new Node(7);
Node *n9 = new Node(9);
root->left = n2;
root->right = n3;
root->random = n2;
n2->left = n4;
n2->right = n5;
n2->random = n8;
n3->left = n6;
n3->right = n7;
n3->random = n5;
n4->random = n9;
n5->left = n8;
n5->right = n9;
n5->random = root;
n6->random = n9;
n9->random = n8;
*/
