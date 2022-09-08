//! T.C.= O(n)          S.C.= O(1)
// In this approach  list is not modified.
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

bool detectLoop(Node *);
Node *detectCycle(Node *);

int main()
{
    /*           _______
                |       |
        1-->2-->3-->4-->5   start loop node: 3
    */
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    /* Create a loop for testing(5 is pointing to 3) */
    head->next->next->next->next->next = head->next->next;

    Node *found = detectCycle(head);
    if (found!=NULL)
        cout << "Loop Found, Loop starts at node: "<<found->data;
    else
        cout << "No Loop Found";
  return 0;
}

bool detectLoop(Node *head)
{
    Node *slow,*fast;
    slow=fast=head;
    //slow will move 1 step whereas fast while move 2 steps at once
    while(fast!=NULL && fast->next!=NULL)
    {
        fast=fast->next->next;
        slow=slow->next;

        if(slow==fast)       //if loop exists then definitely slow and fast will meet(maybe after some iterations) at any node
            return true;
    }
    return false;
}
Node *detectCycle(Node *head)   /// finds the intersection node if loop exists  or else NULL if no loop exists
{
    // If there is One OR no Node
    if (!head || !head->next || !head->next->next)
        return NULL;

    //slow pointer(tortoise) and a fast pointer(hare)
    Node *slow = head;
    Node *fast = head;

    //Cycle Detection
    while(fast != NULL && fast->next!=NULL){
        slow = slow ->next;
        fast = fast -> next ->next;
        if(slow == fast)
            break;
    }
    if( slow!= fast)  // If no Cycle
        return NULL;

    //Point any 1 of the two pointers to head again.
    //and where the slow == fast that is intersection point of cycle.
    fast = head;
    while(slow  != fast )
    {
        slow = slow -> next;
        fast = fast -> next;
    }
    return slow ;
}
