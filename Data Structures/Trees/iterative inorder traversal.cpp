/*
1) Create an empty stack S.
2) Initialize current node as root
3) Push the current node to S and set current = current->left until current is NULL
4) If current is NULL and stack is not empty then
     a) Pop the top item from stack.
     b) Print the popped item, set current = popped_item->right
     c) Go to step 3.
5) If current is NULL and stack is empty then we are done.
*/
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
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

Node * createTree(string );
void Free(Node *);

void iterativeTraversal(Node* root)
{
    stack<Node*> S;
    Node *curr=root;

    while (curr != NULL || !S.empty())
    {
        //Reach the left most Node of the curr Node
        while (curr !=  NULL)
        {
            // place pointer to a tree node on the stack before traversing the node's left subtree
            S.push(curr);
            curr = curr->left;
        }
        /* Current must be NULL at this point */
        curr = S.top();
        S.pop();

        cout << curr->data << " ";

        // we have visited the node and its left subtree.  Now, it's right subtree's turn
        curr = curr->right;
    }
}
int main()
{
    string s;
    getline(cin,s);
    Node *root=createTree(s);

    iterativeTraversal(root);
    Free(root);
    return 0;
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
/*
              1
            /   \
          2      3
        /  \
      4     5
1 2 3 4 5
*/
