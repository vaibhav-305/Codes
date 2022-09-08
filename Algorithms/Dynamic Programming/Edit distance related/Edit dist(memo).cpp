//T.C.= O(n*n) S.C. = O(n*n)+O(n)
#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long int llt;

int fun(string s1,string s2,int i1,int i2,vector<vector<int>>& memo)
{
    if(i1==0)
        return i2;
    if(i2==0)
        return i1;
    if(memo[i1][i2]!=-1)
        return memo[i1][i2];

    if(s1[i1-1]==s2[i2-1])
        return memo[i1][i2]=fun(s1,s2,i1-1,i2-1,memo);
    else{
        int ins=1+fun(s1,s2,i1,i2-1,memo);
        int del=1+fun(s1,s2,i1-1,i2,memo);
        int upd=1+fun(s1,s2,i1-1,i2-1,memo);
        return memo[i1][i2]=min(ins,min(del,upd));
    }

}
int solve(string s1,string s2)
{
    int n1=s1.length(),n2=s2.length();
    vector<vector<int>> memo(n1+1,vector<int>(n2+1,-1));
    return fun(s1,s2,n1,n2,memo);

}

int main()
{
    string s1,s2;
    //s1-->s2
    cin>>s1>>s2;
    cout<<solve(s1,s2);
}
/*
Anshuman
Antihuman
Ans: 2
*/
