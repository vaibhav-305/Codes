//ques link: https://codeforces.com/gym/101466/problem/E (Text Editor , codeforces)
//! T.C.= O((slen + patlen)*log(patlen))   Binary search + KMP search         S.C. = O(patlen)
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> lps;

void LPScalc(string pat)
{
    int patlen=pat.length(),i,j;
    lps.assign(patlen,-1);            //Longest Prefix suffix array (aka longest suffix till i (0<=i<=n-1) which is also prefix)

    ///prefix array calculation
    i=0,j=1;
    lps[0]=0;
    while(j<patlen)
    {
        if(pat[i]==pat[j]){
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
}
bool kmpSearch(string &s,string &pat,int patEndIndx,int k){
    int i=0,j=0;    //i--> s      j-->pat
    int cnt=0;
    while(i<s.length())
    {
        if(s[i]==pat[j])
        {
            i++;
            j++;
        }
        if(j==patEndIndx+1)       //means pat has been traversed completely
        {
            cnt++;
            j=lps[j-1];
        }
        else if(i<s.length() && pat[j]!=s[i])
        {
            if (j != 0)
                j = lps[j - 1];              //Update j as Lps of last matched character
            else
                i = i + 1;
        }
    }
    if(cnt>=k)
        return true;
    else
        return false;
}
string longestPrefix(string& s,string& pat,int k)
{
    LPScalc(pat);
    int l=0,r=pat.length()-1,mid;
    int ansindx=-1;
    while(l<=r)
    {
        mid=(l+r)/2;
        if(kmpSearch(s,pat,mid,k)){
            ansindx = mid;
            l=mid+1;
        }
        else
            r=mid-1;
    }
    if(ansindx==-1)
        return "IMPOSSIBLE";
    else
        return pat.substr(0,ansindx+1);
}
int main()
{
    string s,pat;
    getline(cin,s);
    getline(cin,pat);
    int k;
    cin>>k;
    cout<<longestPrefix(s,pat,k);
  return 0;
}
/*
aaaaa
aaa
4
Ans: aa

Hello World!
H W
5
Ans: IMPOSSIBLE

Solution:
An initial idea to solve this problem is to find the number of times it appears for each of the prefixes of the pattern
(of length m) in the text (of length n), however, for the worst case this solution is of complexity O(m*n2) so it did not enter
time. The solution can be improved using a string matching algorithm such as KMP, in which case the complexity drops to O((n+m)*n),
however it is still a time-inefficient solution.

Now we can see that if a prefix A of the pattern is in the text, then also all the prefixes of A are in the text and also that
the prefixes of A are prefixes of the pattern, that is, the number of times that a prefix of the pattern appears in the text is
a non-decreasing function when the prefix length decreases (or non-increasing when the prefix length increases) so we can use binary
search to find the largest prefix length in which prefix is found in the text atleast k times, in case that length was 0
the result was "IMPOSSIBLE". Worst case complexity O((n + m) log n)
*/
