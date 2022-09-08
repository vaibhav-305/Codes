/*
You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.
Return the single element that appears only once.
*/
//! T.C.= O(log(n))           S.C.= O(1)
#include <iostream>
using namespace std;

int find_unique(int *, int );

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];

    cout<<find_unique(arr,n);

    return 0;
}
int find_unique(int arr[], int n)
{
    int low=0;
    int high=n-1;
    int mid;

    while(low<=high)
    {
        int mid = low+(high-low)/2;

        if(mid+1<n && arr[mid]==arr[mid+1])
        {
            if( (mid&1)==0 && ((mid+1)&1)==1)
                low=mid+2;
            else            // eg: 1 2 2
                high=mid-1;
        }
        else if(mid-1>=0 && arr[mid]==arr[mid-1])
        {
            if( ((mid-1)&1)==0 && (mid&1)==1 )    //eg: 1 1 2
                low=mid+1;
            else
                high=mid-2;
        }
        else                    //eg: 1 1 2 3 3
            return arr[mid];        //if u wanna return the index just return mid
    }

    return -1;     //array is not sorted or no such element existed
}
