//T.C.= O(n*n)    S.C.=O(n*n) for tablutaion    and S.C.=O(n) for space optimization
#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long int llt;

int solve(string s,string pat)  //Tabulation
{
    int ls=s.length(),lpat=pat.length();
    vector<vector<int>> dp(ls+1,vector<int>(lpat+1,-1));

    for(int is=0;is<=ls;is++)
        dp[is][0]=1;
    for(int ip=1;ip<=lpat;ip++)   //dp[0][0]=1  as s=""  pat="" , cnt of pat in s is 1
        dp[0][ip]=0;

    for(int is=1;is<=ls;is++){
        for(int ip=1;ip<=lpat;ip++){
            if(s[is-1]==pat[ip-1])
                dp[is][ip]=dp[is-1][ip-1]+dp[is-1][ip];
            else
                dp[is][ip]=dp[is-1][ip];
        }
    }
    return dp[ls][lpat];
}
int solve_opt(string s,string pat)  //space opt
{
    int ls=s.length(),lpat=pat.length();
    vector<int> dp(lpat+1,0); //as is==0 => dp[0][ip]=0
    vector<int> temp(lpat+1);

    dp[0]=1;  //as s=""  pat="" , cnt of pat in s is 1

    for(int is=1;is<=ls;is++){
        temp[0]=1; //as ip==0 => dp[is][0]=1
        for(int ip=1;ip<=lpat;ip++){
            if(s[is-1]==pat[ip-1])
                temp[ip]=dp[ip-1]+dp[ip];
            else
                temp[ip]=dp[ip];
        }
        dp=temp;
    }
    return dp[lpat];
}
int main()
{
    string s,pat;
    //s1-->s2
    cin>>s>>pat;
    cout<<solve_opt(s,pat);
}
/*
brootgroot
brt
Ans: 3
*/
