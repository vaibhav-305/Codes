/// T.C.= S.C.= O(n*m)
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int LCS(string ,string , int ,int,vector<vector<int>> );

int main()
{
    string str1,str2;
    cin>>str1>>str2;
    int n=str1.length(),m=str2.length();

    //We declare a matrix of [n+1][m+1] and initialize it to -1
    vector<vector<int>> memo(n+1,vector<int>(m+1,-1));

    cout<<LCS(str1,str2,str1.length(),str2.length(),memo);
  return 0;
}

int LCS(string s1,string s2, int n,int m,vector<vector<int>> memo)
{
    if(n==0 || m==0)
        return 0;

    if(memo[n][m]!=-1)
        return memo[n][m];

    if(s1[n-1]==s2[m-1]){     /// if last character of both strings are same
        memo[n][m]= 1+LCS(s1,s2,n-1,m-1,memo);
        return memo[n][m];
    }

    else{     /// if last char are not same then we remove last char from either strings and check for remaining
        memo[n][m]= max(LCS(s1,s2,n-1,m,memo),LCS(s1,s2,n,m-1,memo));
        return memo[n][m];
    }
}
/*
AGGTAB GXTXAYB       o/p=>4 (GTAB)
ABCDGH AEDFHR        o/p=>3 (ADH)
*/
/** optimal substructure:

                       lcs("AXYT", "AYZX")
                       /                \
         lcs("AXY", "AYZX")             lcs("AXYT", "AYZ")
            /          \                    /            \
lcs("AX","AYZX")   lcs("AXY","AYZ")   lcs("AXY","AYZ")   lcs("AXYT", "AY")
                            |_________________|
                                    |
                Same problem repeated, so thats why we memoize.  (repeatation happens when both last characters are removed from both strings in the 2 subproblems)
*/
