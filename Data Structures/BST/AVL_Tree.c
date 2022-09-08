#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
/*  dataset:40 20 10 25 30 22 50  ( best to see multiple rotations)
           :9 5 10 0 6 11 -1 1 2  (delete: 10,11 for imbalance balancing)
*/
typedef struct AVLnode
{
    int data;
    struct AVLnode *left,*right;
    int height;
}Node;
Node * newNode(int val)
{
    Node *node=(Node *)malloc(sizeof(Node));
    node->data=val;
    node->height=1; //new node initially added to leaf
    node->left=NULL;
    node->right=NULL;
  return node;
}

Node * create_AVL(Node *,int);
Node * deleteNode(Node *,int );
Node * searchAVL(Node *,int);

int max(int a,int b)
{
    if(a>b)
        return a;
    else
        return b;
}
int Height(Node *node)
{
    if(node==NULL)
        return 0;
    return node->height;
}
int getBalanceFactor(Node *node)
{
    if(node==NULL)
        return 0;
    return Height(node->left)-Height(node->right);
}
void showAVL(Node *root)
{
    if(root!=NULL)
    {
        showAVL(root->left);
        printf("%d  ",root->data);
        showAVL(root->right);
    }
}
void Preorder(Node *root)
{
    if(root!=NULL)
    {
        printf("%d  ",root->data);
        Preorder(root->left);
        Preorder(root->right);
    }
}
int main()
{
    Node *root=NULL;
    int n;
    printf("Enter no. of nodes: ");
    scanf("%d",&n);
    printf("Enter data: \n");
    int inp;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&inp);
        root=create_AVL(root,inp);
    }
    printf("\n");
    showAVL(root);
    printf("\n");
    Preorder(root);
    /*Node *temp=searchAVL(root,7);
    if(temp==NULL)
        printf("\nNOT FOUND");
    else
        printf("\nFOUND");*/
    int num;
    printf("\nEnter no. of nodes to be deleted: ");
    scanf("%d",&num);
    printf("Enter nodes: ");
    for(int i=0;i<num;i++)
    {
        scanf("%d",&inp);
        root=deleteNode(root,inp);
    }
    printf("\n");
    showAVL(root);
    printf("\n");
    Preorder(root);
  return 0;
}


Node * RightRotation(Node *z)
{
    Node *y,*x,*T3;
    y=z->left;
    T3=y->right;
    // x=y->left;  //no need(just for info, refer to AVL Rotations Doc)

    y->right=z;//Transformation
    z->left=T3;//Transformation

    z->height=1+max(Height(z->left),Height(z->right));//Height computation
    y->height=1+max(Height(y->left),Height(y->right));//Height computation (order of code is imp

    return y;
}
Node * LeftRotation(Node *z)
{
    Node *x,*y,*T2;
    y=z->right;
    T2=y->left;
    // x=y->right;

    y->left=z;    //Transformation
    z->right=T2;  //Transformation

    z->height=1+max(Height(z->left),Height(z->right));//Height computation (order of code is important)
    y->height=1+max(Height(y->left),Height(y->right));//Height computation

    return y;
}
Node * create_AVL(Node *root,int val)
{
    if(root==NULL)
        return newNode(val);
    if(root->data>val)
        root->left=create_AVL(root->left,val);
    else if(root->data<val)
        root->right=create_AVL(root->right,val);
    else //for handling duplicates (as no duplicates are allowed in BST
        return root;

    root->height=1+max(Height(root->left),Height(root->right)); //The '1+' is for updating height
    int balance=getBalanceFactor(root);

    /**    If an insertion causes T to become unbalanced, we
           travel up the tree from the newly created node until
           we find the first node x such that its grandparent z is
           unbalanced node.
    */
    //!   X,Y,Z will be ancestors of inserted node
    if(balance>1)
    {
        //this means either LL or LR

        if(val<root->left->data)  //LL
            return RightRotation(root);
        if(val>root->left->data)  //LR
        {
            root->left=LeftRotation(root->left);
            return RightRotation(root);
        }
    }
    else if(balance<-1)
    {
        //this means either RR or RL

        if(val>root->right->data)  //RR
            return LeftRotation(root);
        if(val<root->right->data)  //RL
        {
            root->right=RightRotation(root->right);
            return LeftRotation(root);
        }
    }

    return root;
}
Node *Inorder_Successor(Node *root)
{
    Node *temp=root;
    while(temp->left!=NULL)
        temp=temp->left;
    return temp;
}
Node * deleteNode(Node *root,int val)
{
    if(root==NULL)
        return root;
    if(root->data>val)
        root->left=deleteNode(root->left,val);
    else if(root->data<val)
        root->right=deleteNode(root->right,val);
    else
    {
        if(root->left==NULL && root->right==NULL)
        {
            free(root);
            return NULL;
        }
        else if(root->left==NULL)
        {
            Node *temp=root;
            root=root->right;
            free(temp);
        }
        else if(root->right==NULL)
        {
            Node *temp=root;
            root=root->left;
            free(temp);
        }
        else
        {
            Node *temp=Inorder_Successor(root->right);
            root->data=temp->data;
            root->right=deleteNode(root->right,temp->data);
        }
    }

    root->height=1+max(Height(root->left),Height(root->right));
    int balance=getBalanceFactor(root);
    /**  Let z be the first unbalanced node encountered while
         travelling up the tree from w. Also, let y be the child
         of z with the larger height, and let x be the child of y
         with the larger height
    */
    //!  Z will be ancestor of deleted node, But not always true for Y,X
    if(balance>1)
    {
        //this means either LL or LR

        if(getBalanceFactor(root->left)>=0)  //LL
            return RightRotation(root);
        if(getBalanceFactor(root->left)<0)  //LR
        {
            root->left=LeftRotation(root->left);
            return RightRotation(root);
        }
    }
    else if(balance<-1)
    {
        //this means either RR or RL

        if(getBalanceFactor(root->right)<=0)  //RR
            return LeftRotation(root);
        if(getBalanceFactor(root->right)>0)  //RL
        {
            root->right=RightRotation(root->right);
            return LeftRotation(root);
        }
    }

    return root;
}
Node* searchAVL(Node* root, int val)
{
    if (root == NULL || root->data == val)
       return root;
    if (root->data > val)
       return searchAVL(root->left, val);
    else
       return searchAVL(root->right, val);
}
