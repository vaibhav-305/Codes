//! T.C.= O(n*log(k))  k->no. of elements in search space [max(arr), sum(arr)]
//! S.C.= O(1)
#include <iostream>
using namespace std;

int allocatePages(int *,int ,int );

int main()
{
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];            //input may or may not be sorted

    cout<<allocatePages(arr,n,k);
  return 0;
}
bool isValidDistribution(int arr[],int n,int k,int target)
{
    int student=1,sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
        if(sum>target)
        {
            student++;
            sum=arr[i];
        }

        if(student>k)
            return false;
    }
    return true;
}
int allocatePages(int arr[],int n,int k)  //it will give the maximum one student will read
{
    if(n<k)              //if no. of students are more than the no. of books
        return -1;

    int mx=INT_MIN,sum=0;
    for(int i=0;i<n;i++)
    {
        mx=max(mx,arr[i]);
        sum+=arr[i];
    }

    int low=mx;
    int high=sum;
    int mid,ans=-1;

    while(low<=high)
    {
        mid=low+(high-low)/2;

        if(isValidDistribution(arr,n,k,mid))
        {
            ans=mid;
            high=mid-1;
        }
        else
            low=mid+1;
    }
    return ans;
}
