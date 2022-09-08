#include <iostream>
#include <math.h>
using namespace std;

void Heap_sort(int *,int);
void make_maxHeap(int *,int&);
int delete_from_heap(int *,int&);

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    Heap_sort(arr,n);
    for(int i:arr)
        cout<<i<<" ";
    cout<<"\n";
  return 0;
}
void Heap_sort(int *arr,int n)
{
    int heapsize=1,val;
    for(int i=1;i<n;i++)
    {
        make_maxHeap(arr,heapsize);
    }
    while(heapsize>1)
    {
        val=delete_from_heap(arr,heapsize);
        arr[(heapsize-1)+1]=val;
    }
}
void make_maxHeap(int *arr,int& hpsz)
{
    hpsz++;
    int indx=hpsz-1,parent,temp;
    while(indx>0)
    {
        parent=floor((indx-1)/2.0);
        if(arr[parent]<arr[indx])
        {
            temp=arr[parent];
            arr[parent]=arr[indx];
            arr[indx]=temp;
            indx=parent;
        }
        else
            break;
    }
}
int targetChild(int *arr,int hpsz,int indx)
{
    int Lchildindx=-1,Rchildindx=-1;
    if((2*indx)+1<hpsz)
        Lchildindx=(2*indx)+1;
    if((2*indx)+2<hpsz)
        Rchildindx=(2*indx)+2;
    if(Lchildindx!=-1 && Rchildindx!=-1)
    {
        if(arr[Lchildindx]>=arr[Rchildindx])
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
int delete_from_heap(int *arr,int& hpsz)
{
    int top,indx=0,child,temp;
    top=arr[0];
    arr[0]=arr[hpsz-1];
    hpsz--;
    while(true)
    {
        child=targetChild(arr,hpsz,indx);
        if(child==-1 || arr[child]<arr[indx])
            break;
        temp=arr[indx];
        arr[indx]=arr[child];
        arr[child]=temp;
        indx=child;
    }
    return top;
}
/*
8
4 3 5 3 6 0 -1 5
*/
