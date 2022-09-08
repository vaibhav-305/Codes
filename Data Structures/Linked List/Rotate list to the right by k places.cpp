// Given the head of a linked list, rotate the list to the right by k places.
// Input: head = [1,2,3,4,5], k = 2       Output: [4,5,1,2,3]
//! T.C.= O(n)          S.C.= O(1)
#include <iostream>
#include <sstream>
#include <new>
using namespace std;
struct Node
{
    int val;
    Node *next;
    Node(int x)
    {
        val=x;
        next=NULL;
    }
};

Node *  create_ll(Node *head);
void printll(Node *head);
Node* rotateRight(Node* head, int );

int main()
{
    Node *head=NULL;
    head=create_ll(head);
    printll(head);
    int k;
    cin>>k;
    Node *rr=rotateRight(head,k);
    printll(rr);
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
    while(temp!=NULL)
    {
        cout<<temp->val<<" ";
        temp=temp->next;
    }
    cout<<endl;
    return;
}
Node* rotateRight(Node* head, int k)
{
    if(head==NULL || head->next==NULL)
        return head;

    Node *endi=head, *temp=head;
    int n=1;
    while(endi->next!=NULL)
    {
        n++;            // calculating length of linked list
        endi=endi->next;
    }
    k=n-(k%n);     //as it is singly linked list so we can't shift right (as no back pointer) so we actually calculate k for left shift.

    if(k==n)
        return head;
    //cout<<n<<" "<<k;
    while(k)
    {
        temp=head;
        head=head->next;
        endi->next=temp;
        endi=temp;
        k--;
    }
    endi->next=NULL;
    return head;
}
