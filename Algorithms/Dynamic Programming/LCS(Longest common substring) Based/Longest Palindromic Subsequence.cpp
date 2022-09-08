#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int Longest_palindromic_subsequence(string ,int );

int main()
{
    string str;
    cin>>str;
    cout<<Longest_palindromic_subsequence(str,str.length());
  return 0;
}

int Longest_palindromic_subsequence(string s,int n)
{
    string s2=s;
    reverse(s2.begin(),s2.end());

    ///LCS of s and reverse(s)
    int dp[n+1][n+1];
    //Initialize first row and first column as zero
    for(int i=0;i<=n;i++)
        dp[i][0]=0;
    for(int j=1;j<=n;j++)
        dp[0][j]=0;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(s[i-1]==s2[j-1])
                dp[i][j]=1+dp[i-1][j-1];

            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    /// To print the pallindromic  sequence
    string lps;
    int i,j;
    i=j=n;
    while(i>0 && j>0)
    {
        if(s[i-1]==s2[j-1])
        {
            lps.push_back(s[i-1]);
            i--;
            j--;
        }
        else
        {
            if(dp[i-1][j]>dp[i][j-1])
                i--;
            else
                j--;
        }
    }
    cout<<lps<<"\n" ;  //no need to reverse paddindromic sequence

    return dp[n][n];
}
/*
AABDCACB
o/p: 5 (BCACB)

*/
