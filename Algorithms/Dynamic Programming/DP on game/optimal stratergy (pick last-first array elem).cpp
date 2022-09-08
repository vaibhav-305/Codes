//T.C.= O(n*n)      S.C.=O(n*n)
#include <iostream>
#include <vector>
using namespace std;

int solve(int i,int j,vector<int>& arr,vector<vector<int>>& dp)
{
    if(i==j)
        return arr[i];
    if(i>j)
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];

    //A[i..j] | remaining coins after pick: a[i+1...j]
    int pickFirst = arr[i] + min(solve(i+2,j,arr,dp),solve(i+1,j-1,arr,dp));
    //A[i..j] | remaining coins after pick: a[i...j-1]
    int pickLast = arr[j] + min(solve(i,j-2,arr,dp),solve(i+1,j-1,arr,dp));

    return dp[i][j] = max(pickFirst,pickLast);
}
int maxCoins(vector<int>& arr){
    int n=arr.size();
    vector<vector<int>> dp(n,vector<int>(n,-1));
    return solve(0,n-1,arr,dp);
}
int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<maxCoins(arr);
  return 0;
}
/*
4
5 3 7 10
Ans: 15

4
8 15 3 7
Ans: 22
*/
