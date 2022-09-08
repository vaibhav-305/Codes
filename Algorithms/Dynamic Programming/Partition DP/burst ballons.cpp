//T.C.= O(n^3)    S.C.=O(n^2)
#include <iostream>
#include <vector>
using namespace std;

int solve(int i,int j,vector<int>& arr,vector<vector<int>>& memo){
    if(i>j)
        return 0;
    if(memo[i][j]!=-1)
        return memo[i][j];

    int mx=-1e9;
    for(int k=i;k<=j;k++){
        int cost = (arr[i-1]*arr[k]*arr[j+1]) + solve(i,k-1,arr,memo) + solve(k+1,j,arr,memo);
        mx=max(mx,cost);
    }
    return memo[i][j]=mx;
}
int burstBall_memo(vector<int>& arr){
    int n=arr.size();
    arr.insert(arr.begin(),1);
    arr.push_back(1);

    vector<vector<int>> memo(n+1,vector<int>(n+1,-1));

    return solve(1,n,arr,memo);
}
int burstBall_tabl(vector<int>& arr){
    int n=arr.size();
    arr.insert(arr.begin(),1);
    arr.push_back(1);

    vector<vector<int>> dp(n+2,vector<int>(n+2,0));
    for(int i=n;i>=1;i--){
        for(int j=1;j<=n;j++){
            if(i>j)
                continue;

            int mx=-1e9;
            for(int k=i;k<=j;k++){
                int cost = (arr[i-1]*arr[k]*arr[j+1]) + dp[i][k-1] + dp[k+1][j];
                mx=max(mx,cost);
            }
            dp[i][j]=mx;
        }
    }

    return dp[1][n];
}
int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    //cout<<burstBall_memo(arr);
    cout<<burstBall_tabl(arr);
  return 0;
}
/*
4
3 1 5 8
Ans: 167    [3,1,5,8] --> [3,5,8] --> [3,8] --> [8] --> []
*/
