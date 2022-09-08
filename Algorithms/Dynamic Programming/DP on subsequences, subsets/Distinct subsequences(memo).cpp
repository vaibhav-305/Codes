//We are given two strings, s and pat. We have to calculate the no. of subsequences of s, which are equal to pat
///T.C.= O(n*n)    S.C.=O(n*n)+O(n)
#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long int llt;

int fun(string s,string pat,int is,int ip,vector<vector<int>>& memo){
    if(ip<0)
        return 1;
    if(is<0)
        return 0;
    if(memo[is][ip]!=-1)
        return memo[is][ip];

    if(s[is]==pat[ip]){
        return memo[is][ip]=fun(s,pat,is-1,ip-1,memo)+fun(s,pat,is-1,ip,memo);
    }else{
        return memo[is][ip]=fun(s,pat,is-1,ip,memo);
    }
}
int solve(string s,string pat)  //memo
{
    int ls=s.length(),lpat=pat.length();
    vector<vector<int>> memo(ls,vector<int>(lpat,-1));
    return fun(s,pat,ls-1,lpat-1,memo);
}

int main()
{
    string s,pat;
    //s1-->s2
    cin>>s>>pat;
    cout<<solve(s,pat);
}
/*
brootgroot
brt
Ans: 3
*/
