//prob link: https://leetcode.com/problems/unique-paths-ii/
/// Only downward and leftward movement allowed
//! T.C.= O(r*c)              S.C.=O(r*c)+O(r)(recurs. stack space)
#include <iostream>
#include <vector>
using namespace std;

int memoSolve(int r,int c,vector<vector<int>> &arr,vector<vector<int>>& memo){
    if(r==0 && c==0)
        return 1;
    if(r<0 || c<0 || arr[r][c]==1)  //1-> blockd
        return 0;
    if(memo[r][c]!=-1)
        return memo[r][c];

    int up=memoSolve(r-1,c,arr,memo);
    int left=memoSolve(r,c-1,arr,memo);
    memo[r][c]=(up+left);
    return memo[r][c];
}
int main()
{
    int row,col;
    cin>>row>>col;
    vector<vector<int>> arr(row, vector<int>(col));
    for(int i=0;i<row;i++)
        for(int j=0;j<col;j++)        // 1->obstacle
            cin>>arr[i][j];           // 0->empty space

    //Memoize approch
    vector<vector<int>> memo(row,vector<int>(col, -1));
    cout<<memoSolve(row-1,col-1,arr,memo);

  return 0;
}
/*
5 9
0 1 0 0 1 0 0 0 0
1 0 0 0 0 1 1 0 0
0 0 0 1 1 0 0 0 0
1 0 1 0 0 0 0 0 1
1 0 0 0 0 0 1 1 0
Ans: 0

8 6
0 0 1 0 0 0
1 0 0 0 1 0
0 0 0 0 0 0
0 1 0 0 0 0
1 1 0 1 1 0
0 0 1 1 0 0
0 0 0 1 0 0
0 0 1 0 1 0
Ans: 11
*/
