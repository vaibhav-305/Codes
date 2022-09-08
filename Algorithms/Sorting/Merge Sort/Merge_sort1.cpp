//! time complexity of merge sort in worst as well as in best case is O(n*log(n)).
//! space complexity of merge sort is case of arrays is O(n).
//It is a STABLE Sort.
#include <iostream>
using namespace std;

void Merge(int *arr,int start,int mid,int endi)
{   //[start,..,..,..,mid]     [mid+1,..,..,..,endi]     <-These will be 2 parts of arr which we'll merge
    int i,j,k,sz;
    i=start;
    j=mid+1;
    sz=endi-start+1, k=0;   //for filling the temp array we have taken variable k
    int temp[sz];           //we will store the result of merged parts in temp array and later transfer it back to arr

    while(i<=mid && j<=endi)
    {

        if(arr[i]<=arr[j]){
            temp[k]=arr[i];
            i++,k++;
        }
        else
        {
            temp[k]=arr[j];
            j++,k++;
        }
    }
    while(i<=mid)
    {
        temp[k]=arr[i];
        i++, k++;
    }
    while(j<=endi)
    {
        temp[k]=arr[j];
        j++, k++;
    }

    //storing all the value back in arr to make it in-place
    for(k=0; k<sz; k++)
        arr[start+k]=temp[k];

    //nothing will be returned as we have done merging in input arr only
}
void merge_sort(int *arr,int start,int endi)
{
    if(start<endi)
    {
        int mid=start+(endi-start)/2;     //divides the current array in 2 parts

        merge_sort(arr,start,mid);        //Sort the 1st part
        merge_sort(arr,mid+1,endi);       //Sort the 2nd part

        Merge(arr,start,mid,endi);        // merge both parts by comparing elements of both parts
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
    merge_sort(arr,0,n-1);
    cout<<"The Sorted Array:-"<<endl;
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
  return 0;
}
