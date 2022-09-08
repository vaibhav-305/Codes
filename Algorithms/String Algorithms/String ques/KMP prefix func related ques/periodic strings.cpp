// solution link: https://www.youtube.com/watch?v=lumwBLJOQpk
/* Defn: A character string is said to have period k if it can be formed by concatenating one or more repetitions of another string of length k.
     A repeated substring is a non-trivial rotation of itself, that means if the string is periodic in nature that means after n rotations
    (n<slen) the rotated string will be equal to the original string with smallest period n-1, This is the idea behind solution.
      Eg: aabbaaabba  (period -> aabba)
      first rotation:  abbaaabbaa    (Doing anti-clockwise/right rotation)
      second rotation: bbaaabbaaa
      Third rotation:  baaabbaaab
      Fourth rotation: aaabbaaabb
      Fifth rotation:  aabbaaabba  <- same as original string
      period = s.substr(0,n)  (n=5 in this case) => aabba
*/
//! T.C.= O(n)
#include <iostream>
#include <vector>
#include <string>
using namespace std;

string smallest_periodic_substr_hash(string );
string smallest_periodic_substr_KMP(string );

int main()
{
    string s;
    cin>>s;
    cout<<smallest_periodic_substr_hash(s)<<"\n";
    cout<<smallest_periodic_substr_KMP(s);
  return 0;
}
string smallest_periodic_substr_hash(string s)       //Using Rabin-Karp string hashing
{
    int slen=s.length();
    long long p1=31,p2=29,m=1e9+9,highest_pow1=1,highest_pow2=1;  //! p=31,29 only works for all small letters or all capital letters only.
    long long h_s1=0,h_s2=0,finalh_s1,finalh_s2;

    for(int i=1;i<slen;i++){
        highest_pow1 = (highest_pow1 * p1)%m;
        highest_pow2 = (highest_pow2 * p2)%m;
    }
    for(int i=0;i<slen;i++)
    {
        h_s1 = (h_s1*p1 + (s[i]-'a'+1)) % m;
        h_s2 = (h_s2*p2 + (s[i]-'a'+1)) % m;
    }
    finalh_s1=h_s1;
    finalh_s2=h_s2;

    for(int i=0;i<slen/2;i++)    //we need to traverse till floor(slen/2) length only
    {
        h_s1 = (p1*(h_s1-(s[i]-'a'+1)*highest_pow1)+ (s[i]-'a'+1))%m;
        h_s2 = (p2*(h_s2-(s[i]-'a'+1)*highest_pow2)+ (s[i]-'a'+1))%m;

        if(h_s1<0)
            h_s1+=m;
        if(h_s2<0)
            h_s2+=m;

        if(h_s1==finalh_s1 && h_s2==finalh_s2 && slen%(i+1)==0)
            return s.substr(0,i+1);
    }
    //if no period found that means string is not periodic , so return whole string
    return s;
}
string smallest_periodic_substr_KMP(string s)
{
    int slen=s.length();

    //Prefix function of s
    int lps[slen];
    int i=0,j=1;
    lps[0]=0;
    while(j<slen){
        if(s[i]==s[j]){
            lps[j]=i+1;
            i++,j++;
        }
        else{        //if match fails
            if(i!=0)
                i=lps[i-1];
            else{
                lps[j]=0;
                j++;
            }
        }
    }

    /// Now make a string s'=s+s.substr(0,slen/2) and search for s in s' excluding the first character in s'
    /// eg: if s="abcdabd"  then search for s in "bcdabdabc" (s+s except the first and last character in it)
    string temps=s.substr(1)+s.substr(0,slen/2);  //s' string

    //string pattern matching
    i=j=0;    //i--> temps      j-->s
    while(i<temps.length())
    {
        if(temps[i]==s[j])
        {
            i++;
            j++;
        }
        if(j==slen)       //j==patlen means pat has been traversed completely
        {
            //cout<<"Found pattern at index: "<<i-j<<endl;
            if(slen%(i-j+1)==0)
                return s.substr(0,i-j+1);
            j=lps[j-1];
        }
        else if(i<temps.length() && s[j]!=temps[i])
        {
            if (j != 0)
                j = lps[j - 1];              //Update j as Lps of last matched character
            else
                i = i + 1;
        }
    }
    //if no period found that means string is not periodic , so return whole string
    return s;
}
/*
aabbaaabba -> aabba
aaaaaabbbbbb -> not periodic
abbaabbaabba -> abba
abcabcabcabc -> abc
*/
