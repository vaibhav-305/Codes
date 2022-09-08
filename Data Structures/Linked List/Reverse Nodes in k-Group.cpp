#include <iostream>
#include <sstream>
#include <new>
using namespace std;
struct Node{
    int val;
    Node *next;
    Node(int x){
        val=x;
        next=NULL;
    }
};

Node *  create_ll(Node *head);
void printll(Node *head);
Node * reverse_nodes_Kgroup(Node *, int );

int main()
{
    Node *head=NULL;
    head=create_ll(head);
    printll(head);
    int k;
    cin>>k;    // 1 <= n <= size of linked list
    Node *res = reverse_nodes_Kgroup(head, k);
    printll(res);
  return 0;
}
Node *  create_ll(Node *head)
{
    string s;
    getline(cin,s);
    int data;

    Node *temp,*new_node;

    istringstream iss(s);
    while(iss>>data)
    {
        new_node=new Node(data);
        if(head==NULL)           //first node
        {
            head=temp=new_node;
        }
        else
        {
            temp->next=new_node;
            temp=new_node;
        }
    }
  return head;
}
void printll(Node *head)
{
    Node *temp=head;
    while(temp!=NULL){
        cout<<temp->val<<" ";
        temp=temp->next;
    }
    cout<<endl;
  return;
}
Node * reverse_ll(Node **start, Node **endi)
{
    Node *temp=*start,*prev_node=NULL,*next_node;
    while(temp!=(*endi))
    {
        next_node=temp->next;
        temp->next=prev_node;
        prev_node=temp;
        temp=next_node;
    }
    next_node=temp->next;
    temp->next=prev_node;          // After reverse : endi->....->start

    temp=*start;                   //swapping start and endi
    *start=*endi;
    *endi=temp;

    return next_node;
}
Node * reverse_nodes_Kgroup(Node *head, int k)
{
    if(k==1)
        return head;

    Node *new_head=NULL,*temp=head,*prev_node,*next_node;
    int cnt=k;
    while(temp!=NULL && temp->next!=NULL)
    {
        temp=temp->next;
        cnt--;
        if(cnt==1)
        {
            cout<<"&\n";
            next_node=reverse_ll(&head,&temp);    // temp->....->head  next_node->...
            cout<<head->val<<" "<<temp->val<<"\n";
            if(new_head==NULL){
                new_head=head;
                prev_node=temp;
            }
            else
            {
                cout<<prev_node->val<<"*\n";
                prev_node->next=head;
                prev_node=temp;
            }
            head=temp=next_node;
            cnt=k;
        }

    }
    if(prev_node!=NULL)
        prev_node->next=head;
    return new_head;
}
