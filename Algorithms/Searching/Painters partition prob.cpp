//Ques similar to book(page) allocation prob
//! T.C.= O(n*log(k))  k->no. of elements in search space [max(arr), sum(arr)]
//! S.C.= O(1)
#include <iostream>
using namespace std;

long long int paint(int *,int ,int );

int main()
{
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];            //input may or may not be sorted

    cout<<paint(arr,n,k);
  return 0;
}
bool isValidDistribution(int arr[],int n,int k,long long int target)
{
    int student=1;
    long long int sum=0;
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
long long int paint(int arr[],int n,int k)
{
    int mx=INT_MIN;
    long long int sum=0;
    for(int i=0;i<n;i++)
    {
        mx=max(mx,arr[i]);
        sum+=arr[i];
    }
    if(n<=k)
        return mx;
    if(n==1)
        return sum;

    long long int low=mx;
    long long int high=sum;
    long long int mid,ans=-1;

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
/*
5 6
762 798 592 899 329
*/
