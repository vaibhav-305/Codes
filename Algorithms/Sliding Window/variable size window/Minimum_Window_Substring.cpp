/*
Given two strings s and t(including duplicates), return the minimum window in s which will contain all the characters in t. If there is no such window in s that covers all characters in t, return the empty string "".
Note that If there is such a window, it is guaranteed that there will always be only one unique minimum window in s.
*/
#include <iostream>
#include <string>
#include <unordered_map>
#include <string.h>
using namespace std;

string min_window_substr(string , string );

int main()
{
    string s,t;
    cin>>s>>t;

    cout<<min_window_substr(s,t);
  return 0;
}
string min_window_substr(string s, string t)
{
    int i=0,j=-1,mn=INT_MAX,starting_index=-1,Mlen;
    unordered_map<char,int> M;

    for(char c: t)
        M[c]++;

    Mlen=M.size();

    while(j<(int)s.length())
    {
        //cout<<"i##j "<<i<<" "<<j<<endl;
        if(Mlen>0)
        {
            j++;
            if(M.find(s[j])!=M.end())
            {
                M[s[j]]--;
                if(M[s[j]]==0)
                    Mlen--;
            }
            //j++;
        }
        if(Mlen==0)
        {
            //cout<<"i^j "<<i<<" "<<j<<endl;
            if(mn>j-i+1)
            {
                mn=j-i+1;
                starting_index=i;
            }
            while(Mlen==0)
            {
                //cout<<"i j "<<i<<" "<<j<<endl;
                if(mn>j-i+1)
                {
                mn=j-i+1;
                starting_index=i;
                }
                if(M.find(s[i])!=M.end())
                {
                    M[s[i]]++;

                    if(M[s[i]]==1)
                        Mlen++;
                }
                i++;
            }
        }
    }
    cout<<"starting_index: "<<starting_index<<endl;
    cout<<"length: "<<mn<<endl;
    if(starting_index==-1)
        return "";

    return s.substr(starting_index,mn);
}
