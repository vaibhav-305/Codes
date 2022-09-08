#include <iostream>
#include <sstream>
#include <vector>
using namespace std;
struct ListNode{
    int data;
    ListNode *next;

    ListNode(int x){
        data=x;
        next=nullptr;
    }
};

ListNode * makeList(string );
ListNode * findMid(ListNode *);

void Free(ListNode *start)
{
    ListNode *temp;
    while(start!=NULL)
    {
        //cout<<start->data<<" -> ";
        temp=start;
        start=start->next;
        delete temp;
    }
    //cout<<"NULL\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    getline(cin,s);
    ListNode *start = makeList(s);

    ListNode *mid = findMid(start);
    cout<<mid->data<<"\n";

    Free(start);
  return 0;
}
ListNode * findMid(ListNode *start)
{
    ListNode *slow,*fast;
    slow=start;
    fast=start->next;
    /* Advance 'fast' two nodes, and advance 'slow' one node */
    while(fast!=NULL)
    {
        fast=fast->next;
        if(fast!=NULL)
        {
            slow=slow->next;
            fast=fast->next;
        }
    }
  return slow;
}

ListNode * makeList(string s)
{
    ListNode *head=NULL,*temp,*prev;
    int data;
    istringstream iss(s);
    while(iss>>data)
    {
        temp=new ListNode(data);
        if(head==NULL)
            head=prev=temp;
        else{
            prev->next=temp;
            prev=temp;
        }
    }
    return head;
}
/*
1 2 3 4
*/
