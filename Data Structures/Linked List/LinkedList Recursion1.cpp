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
void print_in_Reverse(Node *);   //Recursive
void check_pallindrome(Node *, Node **, bool *);

int main()
{
    Node *head=NULL;
    head=create_ll(head);
    printll(head);
    print_in_Reverse(head);   //recursive

    bool check=true;
    Node *temp=head;
    check_pallindrome(head, &temp, &check);
    if(check)
        cout<<"\nPallindrome";
    else
        cout<<"\nNot Pallindrome";

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
void print_in_Reverse(Node *head)
{
    if(head==NULL)
        return ;

    print_in_Reverse(head->next);

    cout<<head->val<<" ";
}
void check_pallindrome(Node *head, Node **head1, bool *check)   //! in T.C.= O(n)    S.C.= O(1) Uses only call-stack of recursion
{
    if(head==NULL)
        return ;

    check_pallindrome(head->next,head1,check);

    if((head->val)!=((*head1)->val))
        *check=false;

    *head1=(*head1)->next;
}
