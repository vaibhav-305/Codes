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
Node * remove_Nth_node_from_back(Node *, int );

int main()
{
    Node *head=NULL;
    head=create_ll(head);
    printll(head);
    int n;
    cin>>n;    // 1 <= n <= size of linked list
    Node *res = remove_Nth_node_from_back(head, n);
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
Node * remove_Nth_node_from_back(Node *head, int n)
{
    Node *temp=head,*prev=NULL;
    //calculating length of linked list;
    int len=0,position_from_start;
    while(temp!=NULL)
    {
        len++;
        temp=temp->next;
    }
    position_from_start=len-n+1;
    temp=head;
    if(position_from_start==1)     //that means first node needs to deleted
    {
        head=head->next;
        delete temp;
        return head;
    }

    while(position_from_start!=1)
    {
        prev=temp;
        temp=temp->next;
        position_from_start--;
    }
    prev->next=temp->next;
    delete temp;

    return head;
}
