/* problem: https://www.geeksforgeeks.org/a-linked-list-with-next-and-arbit-pointer/
• Basically here we make new nodes having same values the given list, and insert them like following:

    node1-->Newnode1-->node2-->Newnode2-->node3-->Newnode->NULL     (the length of list will always be even as we just duplicated the values in new nodes so 2*n.

• Now we will traverse the linked list node by skipping one node in between (basically traversing on our original nodes, and find their random pointers,
  after that we basically shift one stem (node->next= Newnode , random->next=random pointer for Newnode) and assign random pointers to our new nodes.
• After we traverse again to seperate the original Linkedlist  and new duplicated linked list and return the duplicated one.
*/
//! T.C.= O(n)  3 iterations        S.C.= O(1) (no extra space taken besides the space for making clone linkedlist)
#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next,*random;
    Node(int x)
    {
        data = x;
        next = random = NULL;
    }
};

Node * clone(Node *);

void print(Node *head)
{
    Node *temp = head;
    int randomData;
    while (temp != NULL)
    {
        Node *random = temp->random;
        randomData = (random != NULL)? random->data: -1;
        cout << "Data = " <<temp->data<< ", ";
        cout << "Random Data = " <<randomData << endl;
        temp = temp->next;
    }
    cout << endl;
}
int main()
{
    /*    _____>____   ____>_____
         |          | |          |
        (1)-->(2)-->(3)-->(4)-->(5)
         |_<__| |          |_>__| |
                |_______<_________|
    */
    Node* start = new Node(1);
    start->next = new Node(2);
    start->next->next = new Node(3);
    start->next->next->next = new Node(4);
    start->next->next->next->next = new Node(5);

    // 1's random points to 3
    start->random = start->next->next;

    // 2's random points to 1
    start->next->random = start;

    // 3's and 4's random points to 5
    start->next->next->random = start->next->next->next->next;
    start->next->next->next->random = start->next->next->next->next;

    // 5's random points to 2
    start->next->next->next->next->random = start->next;

    Node *cloned_list = clone(start);
    cout << "Original list : \n";
    print(start);

    cout << "\nCloned list : \n";
    print(cloned_list);

  return 0;
}
Node * clone(Node *head)
{
    Node *new_head=NULL,*next_node,*temp=head,*newtemp,*randomptr;

    while(temp!=NULL)
    {
        newtemp=new Node(temp->data);
        if(new_head==NULL)
            new_head=newtemp;

        next_node=temp->next;
        temp->next=newtemp;
        newtemp->next=next_node;
        temp=next_node;
    }

    temp=head;
    while(temp!=NULL)
    {
        randomptr=temp->random;

        newtemp=temp->next;
        if(randomptr!=NULL)
            newtemp->random=randomptr->next;

        temp=temp->next->next;
    }

    temp=head, newtemp=new_head;
    while(temp!=NULL)
    {
        temp->next=temp->next->next;
        temp=temp->next;         //Make sure that last element of original->next is NULL

        if(temp!=NULL){
            newtemp->next=temp->next;
            newtemp=newtemp->next;
        }
    }

    return new_head;
}
