/** Longest palindromic substring cannot  be done by this method as cases will fail
  Eg:   otafsngqvoijxuvqbztv
        vtzbqvuxjiovqgnsfato    (the above string in reverse order)
    Ans: o (basically a one length substring)
    But by using this code it will print "qs"  which is wrong.
*/
#include <iostream>
#include <string>
using namespace std;

int LCSubstring_Iterative(string ,string ,int ,int );
//int LCSubstring_Memoize(string , string ,int ,int );

int main()
{
    string str1,str2;
    cin>>str1>>str2;
    cout<<LCSubstring_Iterative(str1,str2,str1.length(),str2.length());
  return 0;
}
/*int LCSubstring_Memoize(string s1,string s2, int n1, int n2)
{

}
int lcs(int i, int j, int count)
{

    if (i == 0 || j == 0)
        return count;

    if (X[i - 1] == Y[j - 1]) {
        count = lcs(i - 1, j - 1, count + 1);
    }
    count = max(count,
                max(lcs(i, j - 1, 0),
                    lcs(i - 1, j, 0)));
    return count;
}*/

int LCSubstring_Iterative(string s1,string s2,int n,int m)
{
    int maxlen=0,endi;     // To store length of the longest common substring
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
            if(s1[i-1]==s2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
                //maxlen=max(maxlen,dp[i][j]);
                if(maxlen < dp[i][j]){
                    maxlen = dp[i][j];
                    endi = i;    //storing the end post. of Longestcommon substring
                }
            }
            else
                dp[i][j]=0;         //! imp part
        }
    }

    //printing Longest common substring
    cout<< s1.substr(endi-maxlen,maxlen)<<"\n";

    //at last we have to return the max value in the matrix i.e result and not t[m][n]
    return maxlen;
}
/*
GeeksforGeeks
GeeksQuiz
O/P: 5 (Geeks)

LRBBMQBHCDARZOWKKYHIDDQSCDXRJMOWFRXSJYBLDBEFSARCBYNECDYGGXXPKLORELLNMPAPQFWKHOPKMCO
QHNWNKUEWHSQMGBBUQCLJJIVSWMDKQTBXIXMVTRRBLJPTNSNFWZQFJMAFADRRWSOFSBCNUVQHFFBSAQXWPQCAC
*/
