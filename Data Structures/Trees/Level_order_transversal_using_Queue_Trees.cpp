#include <iostream>
#include <queue>
#include <new>
using namespace std;

typedef struct binarytreenode
{
    int data;
    struct binarytreenode *left,*right;
}Node;

Node * create_btree();
void level_order_series(Node *);
void level_order_lvlBylvl(Node *);

int main()
{
    Node *root;
    root=create_btree();
    level_order_series(root);
    cout<<endl;
    level_order_lvlBylvl(root);
}
Node * create_btree()
{
    int inp;
    cout<<"Enter data: ";
    cin>>inp;
    if(inp==-1)
        return NULL;
    Node *new_node=new Node;
    new_node->data=inp;
    cout<<"Enter for Left Child:-\n";
    new_node->left=create_btree();
    cout<<"Enter for Right Child:-\n";
    new_node->right=create_btree();
    return new_node;
}
void level_order_series(Node *root)
{
    queue<Node*> q;
    q.push(root);
    Node *l,*r;
    while(q.size()!=0)
    {
        cout<<q.front()->data<<" ";
        l=q.front()->left;
        r=q.front()->right;
        q.pop();
        if(l!=NULL)
        q.push(l);
        if(r!=NULL)
        q.push(r);

    }
}
void level_order_lvlBylvl(Node *root)
{
    queue<Node*> q;
    q.push(root);
    Node *l,*r;
    while(q.size()!=0)
    {
        int i=q.size();
        while(i>0)
        {
            cout<<q.front()->data<<" ";
            l=q.front()->left;
            r=q.front()->right;
            q.pop();
            if(l!=NULL)
                q.push(l);
            if(r!=NULL)
                q.push(r);
            i--;
        }
        cout<<endl;
    }
}
