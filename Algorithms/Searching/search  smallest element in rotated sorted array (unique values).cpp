//PROGRAM to find MIN element in a rotated sorted array
//Will work for unique values in array only.
#include <iostream>
using namespace std;

int index_of_min_element(int *arr,int n)
{
    int low=0, high=n-1;
    if(n==1)
        return arr[0];
    if(n==2)
        return min(arr[0],arr[1]);        //arr=[2,1]
    while(low<=high)     //"=" will be there (Test case:[2,3,1])
    {
        int mid=(low+high)/2;
        int prev=(mid-1+n)%n;
        int next=(mid+1)%n;

        ///Smallest element will always be in unsorted part

        if(arr[mid]<arr[next] && arr[mid]<arr[prev])
            return mid;

        // if left part is sorted
        else if(arr[low]<=arr[mid])  //"=" will come in both else if too (Test case: [7,8,1,2,3,4,5,6]
            low=mid+1;

        //right part is sorted
        else if(arr[mid]<=arr[high])
            high=mid-1;
    }
    return -1;
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
}
