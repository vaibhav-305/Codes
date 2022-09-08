#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int max_sum_BitSeq(int *,int );

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];

    cout<<max_sum_BitSeq(arr,n);
  return 0;
}
int max_sum_BitSeq(int arr[],int n)
{
    int dp1[n],dp2[n];
    for(int i=0;i<n;i++)
        dp1[i]=dp2[i]=arr[i];

    for(int i1=1,i2=n-2 ; i1<n,i2>=0 ; i1++,i2--)
    {
        for(int j1=0,j2=n-1 ; j1<i1,j2>i2 ; j1++,j2--)
        {
            if(arr[i1]>=arr[j1] && dp1[i1]<=dp1[j1]+arr[i1]){
                dp1[i1]=dp1[j1]+arr[i1];
            }
            if(arr[i2]>=arr[j2] && dp2[i2]<=dp2[j2]+arr[i2])
                dp2[i2]=dp2[j2]+arr[i2];
        }
    }
    int mx=INT_MIN;
    for(int i=0;i<n;i++){
        cout<<dp2[i]<<" ";
            if(dp1[i]-arr[i]!=0 && dp2[i]-arr[i]!=0)
                mx=max(mx,dp1[i]+dp2[i]-arr[i]);
    }
    cout<<"\n";
    return mx;
}
