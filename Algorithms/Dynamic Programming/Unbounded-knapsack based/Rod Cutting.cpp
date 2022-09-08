#include <iostream>
#include <vector>
using namespace std;

int max_profit(int *,int *,int ,int );

int main()
{
    int n, rod_length;
    cin>>n>>rod_length;
    int len[n],profit[n];
    for(int i=0;i<n;i++)
        cin>>len[i];
    for(int i=0;i<n;i++)
        cin>>profit[i];

    cout<<max_profit(len, profit, n, rod_length);
  return 0;
}
int max_profit(int len[],int profit[],int n,int rod_length)
{
    int dp[n+1][rod_length+1];

    for(int i=0;i<=n;i++)
        dp[i][0]=0;

    for(int j=1;j<=rod_length;j++)
        dp[0][j]=0;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=rod_length;j++)
        {
            if(len[i-1]<=j)
                dp[i][j]=max(profit[i-1]+dp[i][j-len[i-1]],dp[i-1][j]);
            else
                dp[i][j]=dp[i-1][j];
        }
    }
    return dp[n][rod_length];
}
