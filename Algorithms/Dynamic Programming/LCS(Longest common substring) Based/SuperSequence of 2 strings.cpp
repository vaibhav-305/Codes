/*
Task: Given two strings str1 and str2, the task is to find the length
      of the shortest string that has both str1 and str2 as subsequences.

Solution:
    1) Find Longest Common Subsequence (lcs) of two given strings.
    2) Insert non-lcs characters (in their original order in strings) to
       the lcs found above, and return the result.

                 Length of the shortest supersequence
 = (Sum of lengths of given two strings) - (Length of LCS of two given strings)
*/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int SuperSequence(string ,string ,int ,int );

int main()
{
    string str1,str2;
    cin>>str1>>str2;
    cout<<SuperSequence(str1,str2,str1.length(),str2.length());
  return 0;
}
int SuperSequence(string s1,string s2,int n,int m)
{
    int dp[n+1][m+1];
    //Initialize first row and first column as zero
    for(int i=0;i<=n;i++)
        dp[i][0]=0;
    for(int j=1;j<=m;j++)
        dp[0][j]=0;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(s1[i-1]==s2[j-1])
                dp[i][j]=1+dp[i-1][j-1];

            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }

    /// To Print SuperSequence
    string superseq;
    int i=n,j=m;
    while(i>0 && j>0)
    {
        if(s1[i-1]==s2[j-1])
        {
            superseq.push_back(s1[i-1]);
            i--;
            j--;
        }
        else
        {
            if(dp[i-1][j]>dp[i][j-1])
            {
                superseq.push_back(s1[i-1]);
                i--;
            }
            else
            {
                superseq.push_back(s2[j-1]);
                j--;
            }
        }
    }
    while(i>0)
    {
        superseq.push_back(s1[i-1]);
        i--;
    }
    while(j>0)
    {
        superseq.push_back(s2[j-1]);
        j--;
    }
    reverse(superseq.begin(),superseq.end());
    cout<<superseq<<"\n";

    return (n+m-dp[n][m]);    //length of SuperSequence
}
/*
geek eke
o/p: 5  (geeke)

AGGTAB GXTXAYB
o/p: 9  ("AGXGTXAYB" OR "AGGXTXAYB")


*/
