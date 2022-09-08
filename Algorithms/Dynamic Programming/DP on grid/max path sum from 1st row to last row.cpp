/*Find the maximum sum that can be obtained from a path starting from any cell in the first row to any cell in the last row.
  From a particular cell (row, col), we can move in three directions i.e.
    Down: (row+1,col)
    Down left diagonal: (row+1,col-1)
    Down right diagonal: (row+1, col+1)
*/
//! T.C.= O(r*c)      S.C.= O(r*c) + O(r){stack space}
#include <iostream>
#include <vector>
using namespace std;

int solve(vector<vector<int>>& arr,int r,int c,int i,int j,vector<vector<int>>& memo){
    if(j>=c || j<0){
        return -1e9;   //-INF as we have to find max path
    }
    if(i==r-1){
        return arr[i][j];
    }
    if(memo[i][j]!=-1)
        return memo[i][j];

    int down = solve(arr,r,c,i+1,j,memo);
    int downLeftDiag = solve(arr,r,c,i+1,j-1,memo);
    int downRightDiag = solve(arr,r,c,i+1,j+1,memo);
    memo[i][j]= arr[i][j]+max(down,max(downLeftDiag,downRightDiag));
    return memo[i][j];
}
int maxSumPathR2R(vector<vector<int>>& arr){
    int r=arr.size(),c=arr[0].size();
    vector<vector<int>> memo(r,vector<int>(c,-1));
    int mx=-1e9;
    for(int j=0;j<c;j++){
        mx=max(mx,solve(arr,r,c,0,j,memo));
    }
    return mx;
}
int main()
{
    int r,c;
    cin>>r>>c;
    vector<vector<int>> arr(r,vector<int>(c));
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            cin>>arr[i][j];
    cout<<maxSumPathR2R(arr);
  return 0;
}
/*
4 4
1 2 10 4
100 3 2 1
1 1 20 2
1 2 2 1
Ans: 25

3 3
10 2 3
3 7 2
8 1 5
Ans: 25
*/
