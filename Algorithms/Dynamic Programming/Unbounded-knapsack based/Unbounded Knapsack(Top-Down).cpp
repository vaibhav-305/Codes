#include <iostream>
#include <vector>
using namespace std;

int knapsack(int *,int *,int ,int );

int main()
{
    int n,W;
    cin>>n>>W;
    int val[n],wt[n];
    for(int i=0;i<n;i++)
        cin>>wt[i];
    for(int i=0;i<n;i++)
        cin>>val[i];

    int maxprofit=knapsack(wt,val,n,W);
    cout<<maxprofit;
  return 0;
}
int knapsack(int wt[],int val[],int n,int W)
{
    //Declare a matrix of [n+1][W+1] and initialize its first row and column to zero
    vector<vector<int>> dp(n+1,vector<int>(W+1,0));

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=W;j++)
        {
            if(wt[i-1]<=j)
            {
                dp[i][j]=max(val[i-1]+dp[i][j-wt[i-1]],dp[i-1][j]);
            }
            else
                dp[i][j]=dp[i-1][j];
        }
    }
    return dp[n][W];
}
int unboundedKnapsack(int wt[],int val[],int n,int W)
{
    // dp[i] is going to store maximum value
    // with knapsack capacity i.
    int dp[W+1];
    fill(dp,dp+(W+1),0);

    // Fill dp[] using above recursive formula
    for (int i=0; i<=W; i++)
      for (int j=0; j<n; j++)
         if (wt[j] <= i)
            dp[i] = max(dp[i], dp[i-wt[j]] + val[j]);

    return dp[W];
}
