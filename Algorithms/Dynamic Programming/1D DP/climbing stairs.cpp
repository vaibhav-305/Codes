//Ques: There are n stairs, a person standing at the bottom wants to reach the top. The person can climb either 1 stair or 2 stairs at a time. Count the number of ways, the person can reach the top.
#include <iostream>
#include <cstring>
using namespace std;

///Recureence relation: f(n) = f(n-1) + f(n-2)  <-- similar as fibonacci
int countWays(int n,int memo[])    //! T.C.= S.C.= O(n)
{
    if(n==0)  //that means starting from nth stair, we have reached all the way to bottom
        return memo[n] = 1;
    if(n<0)
        return 0;

    if(memo[n]!=-1)
        return memo[n];

    memo[n] = countWays(n-1,memo)+countWays(n-2,memo);
    return memo[n];
}
int main()
{
    int n;  //no. of stairs
    cin>>n;

    int memo[n+1];
    memset(memo,-1,sizeof(memo));
    cout<<countWays(n,memo);

  return 0;
}
