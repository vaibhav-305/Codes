#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//here we are going from (r-1,c-1) to (0,0) thats why right->left and down->up. Answer will be in memo[r-1][c-1].
int memoSolve(int r,int c,vector<vector<int>>& arr,vector<vector<int>>& memo){
    if(r==0 && c==0)
        return arr[r][c];

    if(r<0 || c<0)
        return 1e9;   //INFINITY

    if(memo[r][c]!=-1)
        return memo[r][c];

    int left=memoSolve(r-1,c,arr,memo);
    int up=memoSolve(r,c-1,arr,memo);
    memo[r][c] = arr[r][c]+min(left,up);
    return memo[r][c];
}
int minSumPath(vector<vector<int>>& arr){
    int r=arr.size(),c=arr[0].size();
    vector<vector<int>> memo(r,vector<int>(c,-1));
    int ans=memoSolve(r-1,c-1,arr,memo);

    //printing path
    vector<pair<int,int>> path;
    int i=r-1,j=c-1,up,left;
    while(i!=0 || j!=0){
        path.push_back(make_pair(i,j));
        if(i-1>=0 && j-1>=0){
            if(memo[i-1][j]<=memo[i][j-1]){
                i=i-1;
                j=j;
            }
            else{
                i=i;
                j=j-1;
            }
        }
        else if(i-1>=0){
            i=i-1;
            j=j;
        }
        else if(j-1>=0){
            i=i;
            j=j-1;
        }
    }
    path.push_back(make_pair(0,0));
    reverse(path.begin(),path.end());
    for(pair<int,int> p:path)
        cout<<"("<<p.first<<", "<<p.second<<")";
    cout<<"\n";

    return ans;
}
int main()
{
    int r,c;
    cin>>r>>c;
    vector<vector<int>> arr(r,vector<int>(c));
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            cin>>arr[i][j];
    cout<<minSumPath(arr);
  return 0;
}
/*
2 3
5 9 6
11 5 2
Ans:  21

3 3
1 2 3
4 5 4
7 5 9
Ans: 19
*/
