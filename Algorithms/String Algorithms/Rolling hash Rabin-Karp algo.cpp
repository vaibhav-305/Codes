// Rabin-Karp algo with Rolling hash
// Given two strings - a pattern pat and a text txt, determine if the pattern appears in the text and if it does, enumerate all its occurrences.
//! This implementation assumes that the input string contains only lower case latin letters ('a'-'z').
//! T.C.= O(|txt| + |pat|)
/// We use Rabin-karp when we have to do multiple comparisons for multiple strings and patterns and, In this, we only store the hash value of string and not the whole string in hashset, this also saves space too
/// Here we have implemented with 2 hash values to make hash stronger
#include <iostream>
#include <vector>
#include <string>
using namespace std;

void rabin_karp(string pat, string txt)  //! S.C.= O(1)
{
    const int p1 = 29;   //prime
    const int p2 = 31;      //prime
    const int m = 1e9 + 9;    //prime
    int patlen = pat.length();
    int txtlen = txt.length();
    int l, r;
    long long h_pat1=0, h_pat2=0; // hash value for pattern
    long long h_txt1=0, h_txt2=0; // hash value for txt
    long long highest_pow1=1, highest_pow2=1;

    // The value of highest_pow would be = pow(p, patlen-1) % m
    for (int i = 1; i <= patlen-1 ; i++){
        highest_pow1 = (highest_pow1 * p1) % m;
        highest_pow2 = (highest_pow2 * p2) % m;
    }

    // Calculate the hash value of pattern and first window of text
    l=r=0;
    for (r = 0; r < patlen; r++)
    {
        //hash is calculated as => pat[0]*pow(p,patlen-1) + pat[1]*pow(p,patlen-2) + pat[2]*pow(p,patlen-3) + ... + pat[patlen-1]*pow(p,0) whole sum modulo m
        h_pat1 = (p1 * h_pat1 + (pat[r]-'a'+1)) % m;
        h_pat2 = (p2 * h_pat2 + (pat[r]-'a'+1)) % m;

        h_txt1 = (p1 * h_txt1 + (txt[r]-'a'+1)) % m;
        h_txt2 = (p2 * h_txt2 + (txt[r]-'a'+1)) % m;
    }
    if(h_txt1==h_pat1 && h_txt2==h_pat2)
        cout<<"Pattern found at index "<< 0 <<endl;

    // right now l=0 and r=patlen
    while(r<txtlen)
    {
        // Calculate hash value for next window of text: Remove leading digit, add trailing digit
        h_txt1 = (p1*(h_txt1 - (txt[l]-'a'+1)*highest_pow1) + (txt[r]-'a'+1))%m;
        h_txt2 = (p2*(h_txt2 - (txt[l]-'a'+1)*highest_pow2) + (txt[r]-'a'+1))%m;
        if(h_txt1 < 0)       // h[l]*highest_pow - h_txt may be negative as we have taken modulo on h_txt values , so to avoid -ve we add m
            h_txt1+=m;
        if(h_txt2 < 0)
            h_txt2+=m;
        l++;

        // Check the hash values of current window of text and pattern. If the hash values match then only check for characters one by one
        if(h_txt1 == h_pat1 && h_txt2==h_pat2)
                cout<<"Pattern found at index "<< l <<endl;

        r++;
    }
}
int main()
{
    string pat,txt;
    cin>>txt>>pat;
    if(pat.length()<=txt.length())
        rabin_karp(pat,txt);
    else
        cout<<"Pat length is greater than txt length";
  return 0;
}
/**
skdbcjlyfdrzicflveffvpe belbfzuqpwlfvvee 257471541
skdbcjlyfdrzicflveffvp belbfzuqpwlfvve 911531348
The above pairs of strings have same hash-value for p=31 and m=1e9+9
so in such cases we hash it with 2 different p's (p=29 and p=31) and store it, and at checking time we check both hash values,
and if both are equal, then only we say strings are equal, this can reduce chance of getting wrong answer (see codeforces ques : Good substrings).
*/

/* Older: Implemented with only 1 hash:
void rabin_karp(string pat, string txt)  //! S.C.= O(1)
{
    //int M = strlen(pat);
    //int N = strlen(txt);
    const int p = 31;      //prime
    const int m = 1e9 + 9;    //prime
    int patlen = pat.length();
    int txtlen = txt.length();
    int l, r;
    long long h_pat = 0; // hash value for pattern
    long long h_txt = 0; // hash value for txt
    long long highest_pow = 1;

    // The value of highest_pow would be = pow(p, patlen-1) % m
    for (int i = 1; i <= patlen-1 ; i++)
        highest_pow = (highest_pow * p) % m;

    // Calculate the hash value of pattern and
    // first window of text
    l=r=0;
    for (r = 0; r < patlen; r++)
    {
        //hash is calculated as => pat[0]*pow(p,patlen-1) + pat[1]*pow(p,patlen-2) + pat[2]*pow(p,patlen-3) + ... + pat[patlen-1]*pow(p,0) whole sum modulo m
        h_pat = (p * h_pat + (pat[r]-'a'+1)) % m;
        h_txt = (p * h_txt + (txt[r]-'a'+1)) % m;
    }
    if(h_txt == h_pat)
    {
        bool flag=true;
        for(int i=0;i<=patlen-1;i++)
        {
            if(txt[i]!=pat[i]){
                flag = false;
            }
        }
        if(flag)
            cout<<"Pattern found at index "<< 0 <<endl;
    }

    // right now l=0 and r=patlen
    while(r<txtlen)
    {
        // Calculate hash value for next window of text: Remove leading digit, add trailing digit
        h_txt = (p*(h_txt - (txt[l]-'a'+1)*highest_pow) + (txt[r]-'a'+1))%m;
        if(h_txt < 0)       // h[l]*highest_pow - h_txt may be negative as we have taken modulo on h_txt values , so to avoid -ve we add m
            h_txt+=m;
        l++;

        // Check the hash values of current window of text and pattern. If the hash values match then only check for characters one by one
        if(h_txt == h_pat)
        {
            bool flag=true;
            for(int i=l;i<=r;i++)
            {
                if(txt[i]!=pat[i-l]){
                    flag = false;
                }
            }
            if(flag)
                cout<<"Pattern found at index "<< l <<endl;
        }

        r++;
    }
}*/
