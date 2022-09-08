//problem link: https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1
//! T.C.=O(m*n)         S.C.= O(1)
#include <iostream>
using namespace std;
struct Node{
    int data;
    Node *next,*down;
    Node(int x){
        data=x;
        next=down=NULL;
    }
};

Node * flatten(Node *);

int main()
{
    /* Let us create the following linked list
        5 -> 10 -> 19 -> 28
        ↓    ↓     ↓     ↓
        7    20    22    35
        ↓          ↓     ↓
        8          50    40
        ↓                ↓
        30               45
    */
    Node *head;

    head=new Node(5);
    head->down=new Node(7);
    head->down->down=new Node(8);
    head->down->down->down=new Node(30);

    head->next=new Node(10);
    head->next->down=new Node(20);

    head->next->next=new Node(19);
    head->next->next->down=new Node(22);
    head->next->next->down->down=new Node(50);

    head->next->next->next=new Node(28);
    head->next->next->next->down=new Node(35);
    head->next->next->next->down->down=new Node(40);
    head->next->next->next->down->down->down=new Node(45);

    /*Node *temp=head,*temp1;
    while(temp!=NULL)
    {
        temp1=temp;
        while(temp1!=NULL)
        {
            cout<<temp1->data<<" ";
            temp1=temp1->down;
        }
        cout<<"\n";
        temp=temp->next;
    }*/
    Node *start=flatten(head);
    while(start!=NULL)
    {
        cout<<start->data<<" ";
        start=start->down;
    }
  return 0;
}
Node * merge_ll(Node *head1, Node *head2)
{
    Node *new_head=NULL,*temp,*prev_node;
    while(head1!=NULL && head2!=NULL)
    {
        if(head1->data <= head2->data)
        {
            temp=head1;
            head1=head1->down;
        }
        else
        {
            temp=head2;
            head2=head2->down;
        }

        if(new_head==NULL)
            new_head=prev_node=temp;
        else{
            prev_node->down=temp;
            prev_node=temp;
        }
    }
    while(head1!=NULL)
    {
        prev_node->down=head1;
        prev_node=head1;
        head1=head1->down;
    }
    while(head2!=NULL)
    {
        prev_node->down=head2;
        prev_node=head2;
        head2=head2->down;
    }
    return new_head;
}
Node * flatten(Node *root)
{
   if(root==NULL || root->next==NULL)
        return root;

   Node *temp=root;
   root=root->next;
   while(root!=NULL)
   {
       temp=merge_ll(temp,root);
       root=root->next;
   }
   return temp;
}
