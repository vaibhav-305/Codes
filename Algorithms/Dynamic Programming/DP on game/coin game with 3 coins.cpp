//In this as n<=1e6 so in memoization segmentation fault is there due to big recurs. stack, so prefer tabulation
#include <iostream>
#include <vector>
using namespace std;

int WillFirstWin(int n, int x, int y)
{
    bool dp[n + 1];

    // Initial values
    dp[0] = false;
    dp[1] = true;

    // Computing other values.
    for (int i = 2; i <= n; i++) {

        // If A losses any of i-1 or i-x
        // or i-y game then he will
        // definitely win game i
        if (i - 1 >= 0 and !dp[i - 1])
            dp[i] = true;
        else if (i - x >= 0 and !dp[i - x])
            dp[i] = true;
        else if (i - y >= 0 and !dp[i - y])
            dp[i] = true;

        // Else A loses game.
        else
            dp[i] = false;
    }

    // If dp[n] is true then A will
    // game otherwise  he losses
    return dp[n];
}
int main()
{
    int n,x,y;
    cin>>n>>x>>y;
    cout<<WillFirstWin(n,x,y);
    return 0;
}
/*
1000000 576 756
*/
