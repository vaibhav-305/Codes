//time complexity of selection sort is O(n*n).
//space complexity of selection sort is O(1) i.e. const. space.
//It is a UNSTABLE Sort.
#include <iostream>
using namespace std;

void Swap(int *a,int *b)
{
    int k;
    k=*a;
    *a=*b;
    *b=k;
}
void selection_sort(int *arr,int n)
{
    for(int i=0;i<n-1;i++)//we will pass index till (n-2)th as (n-1)th will automatically get sorted
    {
        int iMin=i;//ith post: elements from i till n-1 are candidates
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<arr[iMin])
                iMin=j; //update index of minimum element
        }
        Swap(&arr[i],&arr[iMin]);
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
    selection_sort(arr,n);
    cout<<"The Sorted Array:-"<<endl;
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
  return 0;
}
