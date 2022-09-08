#include <iostream>
#include <string>
using namespace std;

int myAtoi(string );
int StrStr(string , string );

int main()
{
    string s;
    cin>>s;

    cout<<myAtoi(s)<<"\n";

    string str,pat;          //find index of first occurrence of pattern in string (if not found return -1)
    cin>>str>>pat;
    cout<<StrStr(str, pat);
  return 0;
}

int StrStr(string s, string pat)
{
    //implementing KMP algorithm
    int slen=s.length(), patlen=pat.length();
    if(patlen==0)       //if s="" and pat=""  or   s="hajxhskxs" and pat=""
        return 0;
    else if(patlen>slen)        //if pat="asdfdjce"   s="sf" or s=""
        return -1;

    int i,j;

    //prefix array calculation
    int lps[patlen];
    lps[0]=0;
    i=0,j=1;
    while(j<patlen)
    {
        if(pat[i]==pat[j]){
            lps[j]=i+1;
            i++,j++;
        }
        else{
            if(i!=0)
                i=lps[i-1];
            else{
                lps[j]=0;
                j++;
            }
        }
    }

    //string matching
    i=0, j=0;       //i-->s   j-->pat
    while(i<slen){
        if(s[i]==pat[j])
            i++,j++;
        if(j==patlen)      //j==patlen means pat has been traversed completely
           return i-j;
        else if(i<s.length() && pat[j]!=s[i])
        {
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
    return -1;
}

bool isnum(char c)
{
    int n=c-'0';
    if(n>=0 && n<=9)
        return true;
    else
        return false;
}
int myAtoi(string s)
{
    long long int num=0,mx=2147483647,mn=-2147483648;    //length of INT_MAX or INT_MIN is 10
    int slen=s.length();
    int sign=1;
    int i;
    for(i=0;i<slen;i++){          //for avoiding all leading whitespaces
        if(s[i]!=' ')
            break;
    }

    if(i==slen || isalpha(s[i]) || s[i]=='.')
        return 0;
    else{
        if(s[i]=='-')
            sign= -1;
        else if(s[i]=='+')
            sign= 1;
        else{
            num+=(s[i]-'0');
        }
    }
    i++;
    while(i<slen){
        if(!isnum(s[i]))
            break;
        num = num*10 + (s[i]-'0');
        if(num>=mx)
            break;

        i++;
    }
    num=sign*num;

    if(num>=mx)
        return (int)mx;
    else if(num<=mn)
        return (int)mn;
    else
        return (int)num;
}
/*
"  0000000000012345678"
Ans: 12345678
*/
