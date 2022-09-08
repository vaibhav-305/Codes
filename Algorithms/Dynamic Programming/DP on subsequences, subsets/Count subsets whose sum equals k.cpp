#include <iostream>
#include <vector>
using namespace std;

int solve(int n,int targ,vector<int>& arr,vector<vector<int>>& memo){
    /*if(targ==0)    //if we use this then it will ignore zeros eg: [0,0,3] k=3, ans should be 4, but because of this condn ans is 1
        return 1;*/  // so we would check base condn when we reach i=0;
    if(n==0){
        if(arr[0]==0 && targ==0)  return 2;
        else if(arr[0]==targ || targ==0)  return 1;
        else return 0;
    }
    if(memo[n][targ]!=-1)
        return memo[n][targ];
    int notTaken=solve(n-1,targ,arr,memo);
    int taken=0;
    if(arr[n]<=targ)
        taken=solve(n-1,targ-arr[n],arr,memo);
    return memo[n][targ]=notTaken+taken;
}
int CountsubsetSumToK(int targ,vector<int>& arr){
    int n=arr.size();
    vector<vector<int>> memo(n,vector<int>(targ+1,-1));
    return solve(n-1,targ,arr,memo);
}
int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<CountsubsetSumToK(k,arr);
  return 0;
}
