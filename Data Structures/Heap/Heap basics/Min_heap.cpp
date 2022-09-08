#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

void insert_into_heap(int);
int delete_from_heap();
void display();

vector<int> min_heap;

int main()
{
    int inp,n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>inp;
        insert_into_heap(inp);
    }
    //display();
    cout<<delete_from_heap()<<"\n";
    cout<<delete_from_heap()<<"\n";
    //display();
    cout<<delete_from_heap()<<"\n";
    insert_into_heap(-1);
    display();
    while(min_heap.size()!=0)
        cout<<delete_from_heap()<<" ";
  return 0;
}
void insert_into_heap(int val)
{
    min_heap.push_back(val);
    int indx=min_heap.size()-1,parent,temp;
    if(min_heap.size()==1)
        return ;
    while(indx>0)
    {
        parent=floor((indx-1)/2.0);
        if(min_heap[parent]>min_heap[indx])
        {
            temp=min_heap[parent];
            min_heap[parent]=min_heap[indx];
            min_heap[indx]=temp;
            indx=parent;
        }
        else
            break;
    }
}
int targetChild(int indx)
{
    int Lchildindx=-1,Rchildindx=-1;
    if((2*indx)+1<min_heap.size())
        Lchildindx=(2*indx)+1;
    if((2*indx)+2<min_heap.size())
        Rchildindx=(2*indx)+2;
    if(Lchildindx!=-1 && Rchildindx!=-1)
    {
        if(min_heap[Lchildindx]<=min_heap[Rchildindx])
            return Lchildindx;
        else
            return Rchildindx;
    }
    else if(Lchildindx==-1 && Rchildindx!=-1)
        return Rchildindx;
    else if(Lchildindx!=-1 && Rchildindx==-1)
        return Lchildindx;
    else
        return -1;
}
int delete_from_heap()
{
    int top,indx=0,child,temp;
    if(min_heap.size()==0)
    {
        cout<<"Heap is empty"<<"\n";
        return -1;
    }
    top=min_heap[0];
    min_heap[0]=min_heap[min_heap.size()-1];
    min_heap.pop_back();
    while(true)
    {
        child=targetChild(indx);
        if(child==-1 || min_heap[child]>min_heap[indx])
            break;
        temp=min_heap[indx];
        min_heap[indx]=min_heap[child];
        min_heap[child]=temp;
        indx=child;
    }
    return top;
}
void display()
{
    for(int i:min_heap)
        cout<<i<<" ";
    cout<<"\n";
}
/*
7
5 4 7 3 1 10 6
*/
