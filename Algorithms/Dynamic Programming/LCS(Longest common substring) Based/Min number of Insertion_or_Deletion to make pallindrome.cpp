//! Number of insertion = Number of Deletion
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void min_steps_to_make_pallindromic(string ,int );

int main()
{
    string str;
    cin>>str;
    min_steps_to_make_pallindromic(str,str.length());
  return 0;
}
void min_steps_to_make_pallindromic(string s,int n)
{
    /*Steps
        1. Find length of  longest pallindromic sequence(lps)
        2. Number_of_inserion = No_of_deletion = n-len(lps)
    */
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
    cout<<"No. of Insertion: "<<n-dp[n][n]<<"\n";
    cout<<"No. of Deletion: "<<n-dp[n][n];
}
/*
AABDCACB
o/p: 5 (BCACB)
*/
