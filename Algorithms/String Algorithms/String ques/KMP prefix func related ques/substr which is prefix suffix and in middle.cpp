//If exists, find  longest substring which is a prefix , a suffix and occurs in middle as well.
#include <iostream>
#include <string>
using namespace std;

string prefixSuffixMiddle(string s)
{
    int slen=s.length(),i,j;
    int lps[slen];            //Longest Prefix suffix array (aka longest suffix till i (0<=i<=n-1) which is also prefix)

    ///prefix array calculation
    i=0,j=1;
    lps[0]=0;
    while(j<slen)
    {
        if(s[i]==s[j])
        {
            lps[j]=i+1;
            i++;
            j++;
        }
        else        //if match fails
        {
            if(i!=0)
                i=lps[i-1];
            else{
                lps[j]=0;
                j++;
            }
        }
    }

    //for(int i:lps)
      //  cout<<i<<" ";
    //cout<<"\n";

    if(lps[slen-1]==0)
        return "No such string found";

    int mx=0;
    for(int i=0;i<slen-1;i++)
    {
        //lps[lps[slen]] (if not 0) is the smaller length of prefix which is called suffix, we can do lps[lps[lps...[slen]..]]] till its not equal to 0, it will give all lengths of prefix which are also suffix (see ques: https://cses.fi/problemset/task/1732/).
        if(lps[i]==lps[slen-1] || lps[i]==lps[lps[slen-1]-1])  //slen-1 because of 0 index
            mx=max(mx,lps[i]);
    }
    if(mx>0)
        return s.substr(0,mx);
    else
        return "No such string found";
}
int main()
{
    string s;
    cin>>s;

    cout<<prefixSuffixMiddle(s);
  return 0;
}
/*
cbcbcbcbc
Ans: cbcbc

abcabcabc
Ans: abc

abcdabc
Ans: No such string found
*/
