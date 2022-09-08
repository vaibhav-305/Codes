//! T.C.= O(n*log(n)) for average and best cases(when elements are in randomized order) and  O(n^2) for worst cases(when array is almost sorted)
//! Extra space = O(1) (basically the stack space when recursion)
//It is NOT STABLE
#include <iostream>
#include <time.h>
using namespace std;

void Swap(int *a,int *b)
{
    int k=*a;
    *a=*b;
    *b=k;
}
int Partition(int *arr,int start,int endi)   //choses an element as pivot element and places that element in its right position in sorted array and then return its correct position
{
    int l,r,pivot;
    l=start;
    r=endi;
    pivot=arr[start];
    while(l<r)
    {
        //left part
        while(arr[l]<=pivot)     //loop goes till it finds an element bigger than pivot in left part
            l++;
        //right part
        while(arr[r]>pivot)      //loop goes till it finds an element smaller than pivot in right part
            r--;

        if(l<r)            //afterwards it swaps arr[l](element greater than pivot in left part) and arr[r](element smaller than pivot on right part
            Swap(&arr[l],&arr[r]);
    }
    Swap(&arr[start],&arr[r]);
  return r;
}
void quick_sort(int *arr,int start,int endi)
{
    if(start<endi)
    {
         int loc=Partition(arr,start,endi);    //finding partition
         //dividing both arrays
         quick_sort(arr,start,loc-1);         //left side of partition
         quick_sort(arr,loc+1,endi);          //right side of partition
    }
}
int main()
{
    //srand(time(0));
    int n;
    cout<<"Enter Array size: ";
    cin>>n;
    int arr[n];
    cout<<"Enter Elements:\n";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    quick_sort(arr,0,n-1);
    cout<<"The Sorted Array:-"<<endl;
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
  return 0;
}
//Let’s see the randomized version of the partition function :
int rand_partition( int arr[] ,int start ,int endi ) {
    //chooses position of pivot randomly by using rand() function .
     int random = start + rand( )%(endi-start +1 ) ;

      swap ( arr[random] , arr[start]) ;        //swap pivot with 1st element.
     return Partition(arr,start ,endi) ;       //call the above partition function
}
