#include <iostream>
using namespace std;

int peak(int arr[],int n){
    if(n==1)
        return 0;

    int low=0,high=n-1,mid;
    while(low<=high)
    {
        mid=(high+low)/2;
        if(mid>0 && mid<n-1)   //if not corner elements of array
        {
            if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1])
                return mid;
            else if(arr[mid]<arr[mid-1])
                high=mid-1;
            else   //(arr[mid]<arr[mid+1])
                low=mid+1;
        }
        else if(mid==n-1){
            if(arr[n-1]>arr[n-2])
                return n-1;
            else
                return n-2;
        }
        else{      //mid==0
            if(arr[0]>arr[1])
                return 0;
            else
                return 1;
        }
    }
    return -1;     //this means array not bitonic
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<"Index: "<<peak(arr,n);

  return 0;
}
