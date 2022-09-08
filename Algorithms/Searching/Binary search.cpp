#include <iostream>
#include <stdlib.h>
using namespace std;

//for array sorted in increasing order
int binarySearch(int *arr,int start,int endi,int val)
{
    while(start<=endi)
    {
        int mid=start+(endi-start)/2;
        if(arr[mid]==val)
            return mid;
        else if(val<arr[mid])
            endi=mid-1;
        else
            start=mid+1;
    }
    return -1;   //if not found
}

//for array sorted in decreasing order
int dec_binarySearch(int arr[], int start, int endi, int val)
{
    while(start<=endi)
    {
        int mid=start+(endi-start)/2;
        if(arr[mid]==val)
            return mid;
        else if(val<arr[mid])
            start=mid+1;
        else
            endi=mid-1;
    }
    return -1;   //if not found
}
int main()
{
    int arr[20],n,i,val;
    cout<<"Enter No. of elements: ";
    cin>>n;
    cout<<"Enter values:";
    for(i=0;i<n;i++)
        cin>>arr[i];
    cout<<"Enter value to be searched:";
    cin>>val;
    int result=binarySearch(arr,0,n-1,val);
    cout<<"Index:"<<result;

    cout<<"\nEnter No. of elements: ";
    cin>>n;
    cout<<"Enter values in decreasing order:";
    for(i=0;i<n;i++)
        cin>>arr[i];
    cout<<"Enter value to be searched:";
    cin>>val;
    result=dec_binarySearch(arr,0,n-1,val);
    cout<<"Index:"<<result;
}
