//time complexity of insertion sort in worst case(i.e. when array is already sorted in descending order)is O(n*n).
//space complexity of insertion sort is O(1) i.e. const. space.
//It is a STABLE Sort.
#include <iostream>
using namespace std;

void Swap(int *a,int *b)
{
    int k;
    k=*a;
    *a=*b;
    *b=k;
}
void insertion_sort(int *arr,int n)
{
    for(int i=1;i<n;i++)
    {
        int temp=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>temp)
        {
            arr[j+1]=arr[j]; //swapping
            j--;
        }
        arr[j+1]=temp;
    }
}
int main()
{
    int n;
    cout<<"Enter Array size: ";
    cin>>n;
    int arr[n];
    cout<<"Enter Elements:\n";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    insertion_sort(arr,n);
    cout<<"The Sorted Array:-"<<endl;
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
  return 0;
}

