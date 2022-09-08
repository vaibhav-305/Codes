#include <iostream>
#include <vector>
using namespace std;

int solve(int i,vector<int>& arr,int k,vector<int>& memo){
    int n=arr.size();
    if(i==n)
        return 0;
    if(memo[i]!=-1)
        return memo[i];

    int len=0,mx=-1e9,ans=-1e9;
    for(int j=i;j<min(i+k,n);j++){
        len++;
        mx=max(mx,arr[j]);
        int sum = len*mx + solve(j+1,arr,k,memo);
        ans = max(ans,sum);
    }
    return memo[i]=ans;
}
int MaxPart_memo(vector<int>& arr,int k){
    int n=arr.size();
    vector<int> memo(n,-1);
    return solve(0,arr,k,memo);
}
int MaxPart_tabl(vector<int>& arr,int k){
    int n=arr.size();
    vector<int> dp(n+1);

    dp[n]=0;   //base case i==n => 0

    for(int i=n-1;i>=0;i--){
        int len=0,mx=-1e9,ans=-1e9;
        for(int j=i;j<min(i+k,n);j++){
            len++;
            mx=max(mx,arr[j]);
            int sum = len*mx + dp[j+1];
            ans = max(ans,sum);
        }
        dp[i]=ans;
    }
    return dp[0];
}
int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    //cout<<MaxPart_memo(arr,k);
    cout<<MaxPart_tabl(arr,k);
  return 0;
}
/*
7 3
1 15 7 9 2 5 10
Ans: 84
11 4
1 4 1 5 7 3 6 1 9 9 3
Ans: 83
*/
