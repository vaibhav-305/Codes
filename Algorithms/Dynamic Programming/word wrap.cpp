/*T.C.= O(n*k)   S.C.= O(n*k)
1. We recur for each word starting with first word, and remaining length of the line (initially k).
2. The last word would be the base case:
    We check if we can put it on same line:
        if yes, then we return cost as 0.
        if no, we return cost of current line based on its remaining length.
3. For non-last words, we have to check if it can fit in the current line:
    if yes, then we have two choices i.e. whether to put it in same line or next line.
        if we put it on next line: cost1 = square(remLength) + cost of putting word on next line.
        if we put it on same line: cost2 = cost of putting word on same line.
        return min(cost1, cost2)
    if no, then we have to put it on next line:
        return cost of putting word on next line
4. We use memoization table of size n (number of words) * k (line length), to keep track of already visited positions.
*/
#include <iostream>
#include <vector>
using namespace std;

int solve(int i,int curspace,vector<int>& arr,int k,vector<vector<int>>& dp){
    if(i==arr.size()-1){
        if(curspace>arr[i])
            return 0;
        else
            return (curspace*curspace);
    }
    if(dp[i][curspace]!=-1)
        return dp[i][curspace];

    if(curspace>arr[i]){     //as words have to be separated by space (not counted in cost), thats why we need to have curspace >= wordLength+1
        int sameLine = solve(i+1,curspace-arr[i]-1,arr,k,dp);
        int nextLine = (curspace*curspace) + solve(i+1,k-arr[i],arr,k,dp);
        return dp[i][curspace] = min(sameLine,nextLine);
    }
    else
        return dp[i][curspace] = (curspace*curspace) + solve(i+1,k-arr[i],arr,k,dp);
}
int minCost(vector<int>& arr,int k){
    int n=arr.size();
    if(n<2)
        return 0;

    vector<vector<int>> dp(n,vector<int>(k+1,-1));
    return solve(1,k-arr[0],arr,k,dp);   //placing first word in first line
}
int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<minCost(arr,k);
  return 0;
}
/*
4 6
3 2 2 5
Ans: 10
*/
