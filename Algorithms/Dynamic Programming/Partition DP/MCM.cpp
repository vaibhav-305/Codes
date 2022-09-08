//T.C.= O(n^3)  S.C.=O(n^2)
#include<iostream>
#include <vector>
using namespace std;

int solve(vector<int>& arr,int i,int j,vector<vector<int>>& memo)
{
    if(i>=j)  //it means single element which does not makes sense as we need minimum 2 elements to represent matrix dimension
        return 0;
    if(memo[i][j]!=-1)
        return memo[i][j];

    int mn=1e9;
    for(int k=i;k<=j-1;k++){
        int steps = arr[i-1]*arr[k]*arr[j] + solve(arr,i,k,memo) + solve(arr,k+1,j,memo);
        mn=min(steps,mn);
    }
    return memo[i][j]=mn;
}
int MCM_memo(vector<int>& arr){
    int n=arr.size();
    vector<vector<int>> memo(n,vector<int>(n,-1));
    //we are gonna use [i-1][i] as matrix dimension
    return solve(arr,1,n-1,memo);
}
int MCM_tabl(vector<int>& arr){
    int n=arr.size();
    vector<vector<int>> dp(n,vector<int>(n));
    //base case
    for(int i=0;i<n;i++)
        dp[i][i]=0;

    for(int i=n-1;i>=1;i--){
        for(int j=i+1;j<n;j++){  //as j will always be on the right of i
            int mn=1e9;
            for(int k=i;k<j;k++){
                int steps = arr[i-1]*arr[k]*arr[j] + dp[i][k] + dp[k+1][j];
                mn=min(steps,mn);
            }
            dp[i][j]=mn;
        }
    }
    return dp[1][n-1];
}
int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    //cout<<MCM_memo(arr)<<"\n";
    cout<<MCM_tabl(arr);
  return 0;
}
/*
4
10 20 30 40
Ans: 18000
*/
