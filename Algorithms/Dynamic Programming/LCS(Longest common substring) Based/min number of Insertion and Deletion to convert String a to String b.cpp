/*         if s1-->s2
 Min no. of Deletions= len(s1)-len(lcs)
 Min no. of Insertions= len(s2)-len(lcs)

 len=length
 lcs=LCS of s1 and s2
*/
#include <iostream>
#include <string>
using namespace std;

void min_steps_to_convert(string ,string ,int ,int );

int main()
{
    string str1,str2;
    cin>>str1>>str2;
    min_steps_to_convert(str1,str2,str1.length(),str2.length());
  return 0;
}

void min_steps_to_convert(string s1,string s2,int n,int m)
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
    cout<<"Minimum Deletion: "<<n-dp[n][m]<<"\n";
    cout<<"Minimum Insertion: "<<m-dp[n][m]<<"\n";

    return;
}
/*
geeksforgeeks geeks
o/p: Minimum Deletion = 8
     Minimum Insertion = 0

heap pea
o/p: Minimum Deletion = 2
     Minimum Insertion = 1
*/
