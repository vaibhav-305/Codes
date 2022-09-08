//! T.C.= O(h) (log(n) if balanced BST)         S.C.= O(1)
//Valid if the key whose Inorder predecessor and successor is in the tree.
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
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
Node * getInorderSuccessor(Node *,int );
Node * getInorderPredecessor(Node *, int );

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
    int key;
    cin>>key;

    Node *suc=getInorderSuccessor(root,key);
    Node *pre=getInorderPredecessor(root,key);
    if(suc)
        cout<<"Succesor: "<<suc->data<<endl;
    else
        cout<<"Succesor: "<<-1<<endl;

    if(pre)
        cout<<"Predecessor: "<<pre->data<<endl;
    else
        cout<<"Predecessor: "<<-1<<endl;

    Free(root);
  return 0;
}
Node * getInorderSuccessor(Node *root,int key)
{
    /*
        If there exists any right subtree for key node, inorder-successor will be in that right-subtree, else
        the inorder successor will be in the path of the key node(the node just above keynode might be inorder successor.)
                                                                  O
                                                                 / \
                                                                O
                                                               / \
                                                                  O <-- potential-successor(potsuc)
                                                                 /
                                                               Key
    */
    Node *potsuc=NULL,*temp=root;
    while(temp!=NULL)
    {
        if(temp->data == key)
            break;
        else if(temp->data > key)
        {
            potsuc=temp;
            temp=temp->left;
        }
        else
            temp=temp->right;
    }

    if(temp->right == NULL)
        return potsuc;
    else
    {
        temp=temp->right;
        while(temp->left!=NULL)
            temp=temp->left;

        return temp;
    }
}
Node * getInorderPredecessor(Node *root, int key)
{
    /*
        If there exists any right subtree for key node, inorder-predecessor will be in that left-subtree, else
        the inorder predecessor will be in the path of the key node(the node just above keynode might be inorder predecessor.)
                                                                  O
                                                                 / \
                                                                O
                                                               / \
                                                                  O <-- potential-successor(potsuc)
                                                                   \
                                                                   key
    */
    Node *potpre=NULL,*temp=root;
    while(temp!=NULL)
    {
        if(temp->data == key)
            break;
        else if(temp->data < key)
        {
            potpre=temp;
            temp=temp->right;
        }
        else
            temp=temp->left;
    }

    if(temp->left==NULL)
        return potpre;
    else
    {
        temp=temp->left;
        while(temp->right!=NULL)
            temp=temp->right;

        return temp;
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
/*
100 98 102 96 99 N N N 97
               100
              /   \
            98    102
           /  \
         96    99
          \
           97
*/
