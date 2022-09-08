#include <iostream>
using namespace std;

int No_of_ways_to_getTotal(int*,int,int);

int main()
{
    int n,sum;
    cin>>n>>sum;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<No_of_ways_to_getTotal(arr,n,sum);
  return 0;
}
int No_of_ways_to_getTotal(int arr[],int n,int sum)
{
    int dp[n+1][sum+1];
    for(int i=0;i<=n;i++)
        dp[i][0]=1;
    for(int j=1;j<=sum;j++)
        dp[0][j]=0;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            if(arr[i-1]<=j)
                dp[i][j]=dp[i-1][j]+dp[i][j-arr[i-1]];
            else
                dp[i][j]=dp[i-1][j];
        }
    }
    return dp[n][sum];
}
/*
 dp matrix:
                sum-->
           1 2 3 4 5 6 .... n
          _______________
         | 0 0 0 0 0 0 0
elements |1
 (index) |1
    |    |1
    |    |1
    V    |1
         |
*/
