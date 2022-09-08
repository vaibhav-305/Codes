//! T.C.= O(n)        S.C.= O(1)
// In this the Linked list is altered.
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

int main()
{
    /*           _______
                |       |
        1-->2-->3-->4-->5
    */
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    /* Create a loop for testing(5 is pointing to 3) */
    head->next->next->next->next->next = head->next->next;

    bool found = detectLoop(head);
    if (found)
        cout << "Loop Found";
    else
        cout << "No Loop Found";
  return 0;
}
bool detectLoop(Node *head)
{
    Node *temp = new Node(-1);    //Create a temporary node (storing any random value)
    Node *next_node;

    while(head!=NULL)
    {
        // This condition is for the case when there is no loop
        if(head->next==NULL)
            return false;

        // Check if next is already pointing to temp
        if(head->next==temp)     //this current node is where the loop starts (ex: 3 in our inp.)
            return true;

        next_node=head->next;   // Store the pointer to the next node in order to get to it in the next step
        head->next=temp;        // Make next point to temp
        head=next_node;         // Get to the next node in the list
    }

    return false;
}
