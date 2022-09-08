#include <iostream>
#include <climits>
using namespace std;

int minEnergyReq(int heights[], int currIndx, int memo[])   //! T.C. = O(2*n) as we have 2 choices       S.C.= O(n)
{
    if(currIndx==0)  //that means starting from nth stair, we have reached all the way to bottom
        return 0;
    if(memo[currIndx]!=-1)
        return memo[currIndx];

    int jumpTwo = INT_MAX;
    int jumpOne= minEnergyReq(heights,currIndx-1,memo)+ abs(heights[currIndx]-heights[currIndx-1]);
    if(currIndx-2>=0)
        jumpTwo = minEnergyReq(heights,currIndx-2,memo)+ abs(heights[currIndx]-heights[currIndx-2]);

    return memo[currIndx]=min(jumpOne, jumpTwo);
}
int main()
{
    int n;
    cin>>n;
    int heights[n];
    for(int i=0;i<n;i++)
        cin>>heights[i];

    int memo[n];
    for(int i=0;i<n;i++)
        memo[i]=-1;

    cout<<minEnergyReq(heights,n-1,memo);
  return 0;
}
//General case : if 1,2,3....k step jumps are allowed then :
int minEnergyReqK(int heights[],int k,int indx,int memo[])      //! T.C. = O(n*k)     S.C. = O(n)
{
    if(indx==0)  //that means starting from nth stair, we have reached all the way to bottom
        return 0;
    if(memo[indx]!=-1)
        return memo[indx];

    int minsteps = INT_MAX;
    for(int j=1;j<=k;j++)
    {
        if(indx-j>=0){
            int jump = minEnergyReqK(heights,k,indx-j,memo) - abs(heights[indx]-heights[indx-j]);
            minsteps = min(minsteps,jump);
        }
    }
    return memo[indx] = minsteps;
}
/*
4
10 20 30 10
Ans: 20

3
10 50 10
Ans: 0

8
7 4 4 2 6 6 3 4
Ans: 7

6
4 8 3 10 4 4
Ans: 2
*/
