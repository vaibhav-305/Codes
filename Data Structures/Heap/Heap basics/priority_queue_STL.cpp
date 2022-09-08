/*
STL priority_queue is the implementation of Heap Data-structure
.By default, it’s a max heap.

T.C.:-
push:O(log(n))
pop: O(log(n))
top: O(1)
search: O(n)

so when you need insert and delete more than search in tree
then use heap otherwise use binary tree

*/
#include <iostream>
#include <queue>
using namespace std;

void showQ(priority_queue<int> Q)
{
    while(!Q.empty())
    {
        cout<<Q.top()<<" ";
        Q.pop();
    }
    cout<<"\n";
}
void showmQ(priority_queue<int,vector<int>,greater<int>> Q)
{
    while(!Q.empty())
    {
        cout<<Q.top()<<" ";
        Q.pop();
    }
    cout<<"\n";
}
int main()
{
    priority_queue<int> Q;  //! by default MAX heap would be implemented
    Q.push(2);
    Q.push(10);
    Q.push(30);
    Q.push(5);
    Q.push(15);
    cout<<Q.size()<<" "<<Q.top()<<"\n";
    showQ(Q);
    Q.pop();
    showQ(Q);
    cout<<"Min Heap"<<endl;
    priority_queue<int,vector<int>,greater<int>> pQ; //! MIN heap implementation using priority Queues
    pQ.push(2);
    pQ.push(10);
    pQ.push(30);
    pQ.push(5);
    pQ.push(15);
    showmQ(pQ);
    pQ.pop();
    pQ.push(6);
    showmQ(pQ);
  return 0;
}
