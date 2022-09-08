//! T.C.= O(2*max(n,m)) where n and m are lengths of linked lists    S.C.=O(1)
//Here, the linked lists have retain their original structure after the function returns.
#include <iostream>
#include <new>
using namespace std;
struct Node {
    int data;
    struct Node* next;
    Node(int x){
        data=x;
        next=NULL;
    }
};

Node * getIntesectionNode(Node *, Node *);

int main()
{
    /*
        (3)->(6)->(9)->(15)->(30)
                        /
                 (10)__/
    */
    Node* newNode;
    struct Node* head1 = new Node(3);

    struct Node* head2 = new Node(10);

    newNode = new Node(6);
    head2->next = newNode;

    newNode = new Node(9);
    head2->next->next = newNode;

    newNode = new Node(15);
    head1->next = newNode;
    head2->next->next->next = newNode;

    newNode = new Node(30);
    head1->next->next = newNode;

    head1->next->next->next = NULL;

    Node *intersection_node=getIntesectionNode(head1, head2);
    if(intersection_node==NULL)
        cout<<"They don't intersect";
    else
        cout<<intersection_node->data;

  return 0;
}
Node * getIntesectionNode(Node *head1, Node *head2)
{
    int cnt1=0,cnt2=0, diff;
    Node *temp1=head1, *temp2=head2;

    //Finding lengths of both linked list in O(max(len1,len2))
    while(temp1!=NULL && temp2!=NULL)
    {
        cnt1++;
        cnt2++;
        temp1=temp1->next;
        temp2=temp2->next;
    }
    while(temp1!=NULL){
        cnt1++;
        temp1=temp1->next;
    }
    while(temp2!=NULL){
        cnt2++;
        temp2=temp2->next;
    }
    //cout<<cnt1<<" "<<cnt2<<endl;
    if(cnt1<=cnt2){
        temp1=head1;
        temp2=head2;
    }
    else{         // cnt1>cnt2  cond.
        temp1=head2;    //! we will always keep the temp1 pointing toward the smaller(or if equal then both same) length linked-list.
        temp2=head1;
    }
    diff=abs(cnt1-cnt2);
    while(diff!=0)
    {
        diff--;
        temp2=temp2->next;
    }
    //cout<<temp2->data<<" "<<temp1->data<<"\n";
    while(temp1!=NULL && temp2!=NULL)
    {
        if(temp1==temp2)
            break;
        temp1=temp1->next;
        temp2=temp2->next;
    }
    return temp1;       //as both will be pointing to same node (or NULL if no intersection found)
}
