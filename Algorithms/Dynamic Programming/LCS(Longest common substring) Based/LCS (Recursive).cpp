/// A subsequence is a sequence that appears in the same relative order, but not necessarily contiguous.
/// T.C.=O(2^n)
#include <iostream>
#include <string>
using namespace std;

int LCS(string ,string , int ,int );

int main()
{
    string str1,str2;
    cin>>str1>>str2;
    cout<<LCS(str1,str2,str1.length(),str2.length());
  return 0;
}
int LCS(string s1,string s2, int n,int m)
{
    if(n==0 || m==0)
        return 0;

    if(s1[n-1]==s2[m-1])     /// if last character of both strings are same
        return 1+LCS(s1,s2,n-1,m-1);

    else     /// if last char are not same then we remove last char from either strings and check for remaining
        return max(LCS(s1,s2,n-1,m),LCS(s1,s2,n,m-1));
}
/*
AGGTAB GXTXAYB       o/p=>4 (GTAB)
ABCDGH AEDFHR        o/p=>3 (ADH)
*/
