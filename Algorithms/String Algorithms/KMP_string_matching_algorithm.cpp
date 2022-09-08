/*
The basic idea behind KMP's algorithm is: whenever we detect a mismatch (after some matches), we already know some of the characters in the text of the next window.
We take advantage of this information to avoid matching the characters that we know will anyway match.
whenever there is a mismatch, we go just before mismatch and find prefix which is also a suffix (before mismatch). Refer: BacktoBack SWE Yutube channel   
*/
/// T.C. = O(n+m)     S.C. = O(m)       where n=length of given string. m=length of pattern
#include <iostream>
#include <string>
using namespace std;

void KMP_string_matching(string , string );

int main()
{
    string s,pat;
    getline(cin, s);
    cin>>pat;

    KMP_string_matching(s,pat);
  return 0;
}
void KMP_string_matching(string s, string pat)     //returns starting index if match found, else -1
{
    //cout<<s<<"\n"<<pat<<"\n";
    int patlen=pat.length(),i,j;
    int lps[patlen];            //Longest Prefix suffix array (aka longest suffix till i (0<=i<=n-1) which is also prefix)

    ///prefix array calculation
    i=0,j=1;
    lps[0]=0;
    while(j<patlen)
    {
        if(pat[i]==pat[j])
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
    for(int i:lps)
        cout<<i<<" ";
    cout<<"\n";

    ///string pattern matching
    i=j=0;    //i--> s      j-->pat
    while(i<(int)s.length())
    {
        if(s[i]==pat[j])
        {
            i++;
            j++;
        }
        if(j==patlen)       //j==patlen means pat has been traversed completely
        {
            cout<<"Found pattern at index: "<<i-j<<endl;
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
    cout<<"hehe boi";
}
/*
AABAACAADAABAABA
AABA
Output: Pattern found at index 0
        Pattern found at index 9
        Pattern found at index 12
*/
