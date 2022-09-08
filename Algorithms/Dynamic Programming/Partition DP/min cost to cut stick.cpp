//T.C.= O(n^3)   S.C.= O(n^2)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solve(int i,int j,vector<int>& arr,vector<vector<int>>& memo){
    if(i>j)
        return 0;
    if(memo[i][j]!=-1)
        return memo[i][j];

    int mn=1e9;
    for(int k=i;k<=j;k++){
        int cost = (arr[j+1]-arr[i-1]) + solve(i,k-1,arr,memo) + solve(k+1,j,arr,memo);
        mn=min(mn,cost);
    }
    return memo[i][j]=mn;
}
int min_cost_memo(int len,vector<int>& arr){
    int n=arr.size();

    arr.push_back(len);
    arr.push_back(0);
    sort(arr.begin(),arr.end());

    vector<vector<int>> memo(n+1,vector<int>(n+1,-1));

    return solve(1,n,arr,memo);
}
int min_cost_tabl(int len,vector<int>& arr){
    int n=arr.size();

    arr.push_back(len);
    arr.push_back(0);
    sort(arr.begin(),arr.end());

    vector<vector<int>> dp(n+2,vector<int>(n+2,0));  //initializing matrix with 0

    for(int i=n;i>=1;i--){
        for(int j=1;j<=n;j++){
            if(i>j)
                continue;

            int mn=1e9;
            for(int k=i;k<=j;k++){
                int cost = (arr[j+1]-arr[i-1]) + dp[i][k-1] + dp[k+1][j];
                mn=min(mn,cost);
            }
            dp[i][j]=mn;
        }
    }
    return dp[1][n];
}
int main()
{
    int n,len;
    cin>>len>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    //cout<<min_cost_memo(len,arr);
    cout<<min_cost_tabl(len,arr);
  return 0;
}
/*
10 4
1 3 4 7
Ans: 23
*/
