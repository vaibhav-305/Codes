//PROGRAM to find MIN element in a rotated sorted array
//Will work for duplicates also.
#include <iostream>
using namespace std;

int index_of_min_element(int *arr,int n)
{
    int low=0, high=n-1;
    if(n==1)
        return arr[0];
    if(n==2)
        return min(arr[0],arr[1]);
    while(low < high)
    {
        int mid = low + (high - low)/2;
        if (arr[mid] == arr[high])
            high--;
        else if(arr[mid] > arr[high])
            low = mid + 1;
        else
            high = mid;
    }
    return high;
}

int main()
{
    int arr[20],n,i,val;
    cout<<"Enter No. of elements: ";
    cin>>n;
    cout<<"Enter values:\n";
    for(i=0; i<n; i++)
        cin>>arr[i];
    int result=index_of_min_element(arr,n);
    cout<<"Index of min element:"<<result;
  return 0;
}
