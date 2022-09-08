//! T.C. = S.C. = O(2*n)
#include <iostream>
#include <vector>
#include <climits>
using namespace std;
using ll = long long;
vector<vector<ll>> memo;

ll solve(int i,int flag,int arr[],int n)
{
    if(i>=n)
        return 0;
    if(memo[i][flag]!=INT_MIN)
        return memo[i][flag];

    //we have got 2 choices in are recursion tree, either take the arr[i] in subseq (with sign acc to its position) or leave it
    ll op1 = solve(i+1,flag,arr,n);    //choice when we are not taking arr[i]
    ll op2=0;

    //choice when we are taking arr[i]
    if(flag==1)    //flag 1 means it is a odd pos in suseq so we add
        op2+=arr[i];
    else           //flag 0 means it is a even pos in subseq so we subtract
        op2-=arr[i];
    op2+=solve(i+1,1-flag,arr,n);  //we have taken arr[i] so now we'll flip the sign as next pos will be even if prev is odd and vice a versa

    return memo[i][flag] = max(op1,op2);   //taking max as we have to find max sum sequence
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];

    memo.assign(n+1,vector<int>(2));
    for(int i=0;i<=n;i++)
        memo[i][0]=memo[i][1]=INT_MIN;
    cout<<solve(0,1,arr,n);
  return 0;
}
