#include<bits/stdc++.h>
using namespace std;

void rabin_karp(string pat, string txt)
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
            cout<< 0 <<endl;
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
                cout<< l <<endl;
        }

        r++;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    string needle, haystack;
    while(cin>>n){    //identifies EOF (End of file) , if there is no character ahead -> cin>>n will return false -> loop will be terminated and program will be finished
        cin>>needle;
        cin>>haystack;
        if(needle.length()<=haystack.length())
            rabin_karp(needle,haystack);
        cout<<"\n";
    }
}
/*
2
na
banananobano
6
foobar
foo
9
foobarfoo
barfoobarfoobarfoobarfoobarfoo
*/
