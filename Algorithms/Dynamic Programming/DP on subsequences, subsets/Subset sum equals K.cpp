#include <iostream>
#include <vector>
using namespace std;

bool solve(int n,int k,vector<int>& arr,vector<vector<int>>& memo){
    if(k==0)
        return true;
    if(n==0)
        return (arr[n]==k);
    if(memo[n][k]!=-1)
        return memo[n][k];
    bool notTaken = solve(n-1,k,arr,memo);
    bool taken=false;
    if(arr[n]<=k){
        taken = solve(n-1,k-arr[n],arr,memo);
     }
    memo[n][k]= (notTaken | taken);
    return memo[n][k];
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<vector<int>> memo(n,vector<int>(k+1,-1));
    return solve(n-1,k,arr,memo);
}
int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<subsetSumToK(n,k,arr);
  return 0;
}
