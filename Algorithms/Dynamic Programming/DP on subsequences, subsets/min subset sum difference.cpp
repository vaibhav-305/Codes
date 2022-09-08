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
int minSubsetSumDifference(vector<int>& arr, int n)
{
    int sum=0;
    for(int i: arr)
        sum+=i;
    int targ=sum/2;
    cout<<targ<<" ";
    vector<vector<int>> memo(n,vector<int>(targ+1,-1));
    cout<<solve(n-1,targ,arr,memo)<<"\n";
    for(int i=0;i<n;i++){
        for(int j=1;j<=targ;j++)
            cout<<memo[i][j]<<" ";
        cout<<"\n";
    }
}
int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    minSubsetSumDifference(arr,n);
  return 0;
}
