/** Idea:
    m: Length of str1 (first string)
    n: Length of str2 (second string)

    If last characters of two strings are same,
        1. We consider last characters and get count for remaining
           strings. So we recur for lengths m-1 and n-1.
        2. We can ignore last character of first string and
           recurse for lengths m-1 and n.
    else
    If last characters are not same,
    We ignore last character of first string and
    recurse for lengths m-1 and n.
*/
//! T.C.= S.C.= O(n*m)       where n,m are lengths of string and pattern
#include <bits/stdc++.h>
using namespace std;

int No_of_occurences_recursive(string ,int ,string ,int );
int No_of_occurences_DP(string ,int ,string ,int);

int main()
{
    string str,pat;    //we have to find no. of occurences of pat(pattern) in str.
    cin>>str>>pat;
    //cout<<No_of_occurences_recursive(str,str.length(),pat,pat.length());
    cout<<No_of_occurences_DP(str,str.length(),pat,pat.length());
  return 0;
}

///Recursive
int No_of_occurences_recursive(string s,int slen,string pat,int patlen){

    // If both first and second string is empty,
    // or if second string is empty, return 1
    if((slen==0 && patlen==0) || patlen==0)
        return 1;

    // If only first string is empty and second
    // string is not empty, return 0
    if(slen==0)
        return 0;

    // If last characters are same
    // Recur for remaining strings by
    // 1. considering last characters of both strings
    // 2. ignoring last character of first string
    if(s[slen-1]==pat[patlen-1])
    {
        return No_of_occurences_recursive(s,slen-1,pat,patlen-1)+No_of_occurences_recursive(s,slen-1,pat,patlen);
    }
    else
    {
        // If last characters are different, ignore
        // last char of first string and recur for remaining string
        return No_of_occurences_recursive(s,slen-1,pat,patlen);
    }

}

///DP
int No_of_occurences_DP(string s,int slen,string pat,int patlen)
{
    int dp[slen+1][patlen+1];

    // if pat=""
    for(int i=0;i<=slen;i++)
        dp[i][0]=1;
    //if s=""
    for(int j=1;j<=patlen;j++)
        dp[0][j]=0;

    for(int i=1;i<=slen;i++)
    {
        for(int j=1;j<=patlen;j++)
        {
            if(s[i-1]==pat[j-1])
                dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
            else
                dp[i][j]=dp[i-1][j];
        }
    }
    return dp[slen][patlen];
}
/*
codeforcodeforces codeforces
12

*/
