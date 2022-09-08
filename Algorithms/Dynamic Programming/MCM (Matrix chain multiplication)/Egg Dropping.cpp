#include <iostream>
#include <vector>
using namespace std;

int solve(int e,int f,vector<vector<int>>& dp)
{
    if(f==0 || f==1)
        return f;
    if(e==1)
        return f;    //trying every floor starting from bottom till egg breaks
    if(dp[e][f]!=-1)
        return dp[e][f];

    int minAttempts = 1e9;
    for(int k=1;k<=f;k++){
        int temp = 1+max(solve(e-1,k-1,dp),solve(e,f-k,dp));
        //solve(e-1,k-1) --> egg breaks at kth floor, so we'll look at floors below k(=>k-1) and as as egg broken so remaining eggs = e-1
        //solve(e,f-k) --> egg didnt break so we'll look for floors above k (=> f-k)  and egg can be reused as egg didnt break so remaining eggs = e
        // max -> worst case (critical floor is on top)

        minAttempts = min(minAttempts,temp);  //here min -> min no of attempts (as asked by ques)
    }
    return dp[e][f]=minAttempts;
}
int main()
{
    int e,f;
    cin>>e>>f;
    vector<vector<int>> dp(e+1,vector<int>(f+1,-1));
    cout<<solve(e,f,dp);
  return 0;
}
/*
2 10
Ans: 4
*/
