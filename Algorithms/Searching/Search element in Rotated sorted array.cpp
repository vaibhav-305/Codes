//T.C. = O(log(n)) only 1 traversal done
#include <iostream>
using namespace std;

int Find_element(int *,int ,int );

int main()
{
    int n,val;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<"Enter value to be searched: ";
    cin>>val;
    cout<<Find_element(arr,n,val);
  return 0;
}
int Find_element(int arr[],int n,int val)
{
    int left=0,right=n-1,mid;

    while(left<=right)
    {
        mid=(left+right)/2;

        if(arr[mid]==val)
            return mid;
        else if(arr[mid]>=arr[left])   //Uniform increasing left part
        {
            if(val<=arr[mid] && val>=arr[left])
                right=mid-1;
            else
                left=mid+1;
        }
        else      //Uniform increasing right part
        {
            if(val>=arr[mid] && val<=arr[right])
                left=mid+1;
            else
                right=mid-1;
        }
    }
    return -1;
}
