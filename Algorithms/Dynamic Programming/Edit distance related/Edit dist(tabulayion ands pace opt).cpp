//T.C.= O(n*n)    tabl:S.C.=O(n*n)   space opt:S.C.=O(n)
#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long int llt;

int solve(string s1,string s2)  //Tabulation
{
    int n1=s1.length(),n2=s2.length();
    vector<vector<int>> dp(n1+1,vector<int>(n2+1));
    for(int i2=0;i2<=n2;i2++)
        dp[0][i2]=i2;       //i1==0
    for(int i1=0;i1<=n1;i1++)
        dp[i1][0]=i1;       //i2==0
    for(int i1=1;i1<=n1;i1++){
        for(int i2=1;i2<=n2;i2++)
        {
            if(s1[i1-1]==s2[i2-1])
                dp[i1][i2]=dp[i1-1][i2-1];
            else{
                int ins=1+dp[i1][i2-1];
                int del=1+dp[i1-1][i2];
                int upd=1+dp[i1-1][i2-1];
                dp[i1][i2]=min(ins,min(del,upd));
            }

        }
    }
    return dp[n1][n2];
}
int solve_opt(string s1,string s2){   //Space optimization
    int n1=s1.length(),n2=s2.length();
    vector<int> dp(n2+1);
    for(int i2=0;i2<=n2;i2++)
        dp[i2]=i2;       //i1==0
    vector<int> temp(n2+1);

    for(int i1=1;i1<=n1;i1++){
        fill(temp.begin(),temp.end(),0);
        temp[0]=i1;
        for(int i2=1;i2<=n2;i2++)
        {
            if(s1[i1-1]==s2[i2-1])
                temp[i2]=dp[i2-1];
            else{
                int ins=1+temp[i2-1];
                int del=1+dp[i2];
                int upd=1+dp[i2-1];
                temp[i2]=min(ins,min(del,upd));
            }
        }
        dp=temp;
    }
    return dp[n2];
}
int main()
{
    string s1,s2;
    //s1-->s2
    cin>>s1>>s2;
    cout<<solve_opt(s1,s2);
}
/*
Anshuman
Antihuman
Ans: 2
*/
