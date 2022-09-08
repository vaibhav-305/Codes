#include <iostream>
using namespace std;

long long int maxSum(int *,int ,int );

int main()
{
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];

    cout<<maxSum(arr,n,k);
  return 0;
}

long long int maxSum(int arr[],int n,int k)
{
    long long int sum=0,Max;
    int i=0,j=k;

    for(int x=0;x<k;x++)
    {
        sum+=(long long int)arr[x];
    }

    Max=sum;

    while(j<n)
    {
        sum-=(long long int)arr[i];
        i++;

        sum+=(long long int)arr[j];
        j++;

        Max=max(Max,sum);
    }
    return Max;
}
