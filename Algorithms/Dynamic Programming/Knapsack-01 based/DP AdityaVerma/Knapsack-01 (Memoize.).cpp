//T.C.=O(n*W)
//S.C.=O(N*W).The use of 2D array data structure for storing intermediate states
#include <iostream>
#include <vector>
using namespace std;

int knapsack(int *,int *,int ,int ,vector<vector<int>>);

int main()
{
    int n,W;
    cin>>n>>W;
    int cost[n],wt[n];
    for(int i=0;i<n;i++)
        cin>>wt[i];
    for(int i=0;i<n;i++)
        cin>>cost[i];
    //We declare a matrix of [n+1][W+1] and initialize it to -1
    vector<vector<int>> memo(n+1,vector<int>(W+1,-1));

    int maxprofit=knapsack(wt,cost,n,W,memo);
    cout<<maxprofit;
  return 0;
}

int knapsack(int wt[],int cost[],int n,int W,vector<vector<int>> memo)
{
    if(n==0 || W==0)
        return 0;

    if(memo[n][W]!=-1)
        return memo[n][W];

    if(wt[n-1]<=W)
    {
        memo[n][W]=max((cost[n-1]+knapsack(wt,cost,n-1,W-wt[n-1],memo)),knapsack(wt,cost,n-1,W,memo));
        return memo[n][W];
    }
    else
    {
        memo[n][W]=knapsack(wt,cost,n-1,W,memo);
        return memo[n][W];
    }
}
