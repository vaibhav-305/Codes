/// T.C.= S.C.= O(n*m)
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int LCS(string,string,int,int);

int main()
{
    string str1,str2;
    cin>>str1>>str2;

    cout<<LCS(str1,str2,str1.length(),str2.length());
  return 0;
}
int LCS(string s1,string s2,int n,int m)
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

    ///For Printing LCS
    string lcs;
    int i=n,j=m;
    // Start from the right-most-bottom-most corner and one by one store characters in dp[]
    while(i>0 && j>0)
    {
        // If current character in s1 and s2 are same, then
        // current character is part of lcs(string)
        if(s1[i-1]==s2[j-1])
        {
            lcs.push_back(s1[i-1]);
            i--;
            j--;
        }
        // If not same, then find the larger of two and
        // go in the direction of larger value(Direction is either up([i-1][j]) or left([i][j-1])
        else
        {
            if(dp[i-1][j]>dp[i][j-1])
                i--;
            else
                j--;
        }
    }
    reverse(lcs.begin(),lcs.end()); //reverse the lcs( as we have gone from bottom to up)
    cout<<lcs<<"\n";

    return dp[n][m];  //returning length
}
/*
AGGTAB GXTXAYB       o/p=>4 (GTAB)
ABCDGH AEDFHR        o/p=>3 (ADH)
*/
