//Given a string of length n, print the size of the longest possible substring that has exactly k unique characters.
//T.C.= O(n)      S.C.= O(1)
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int longest_substring(string , int );

int main()
{
    string s;
    cin>>s;
    int k;
    cin>>k;

    cout<<longest_substring(s,k);
  return 0;
}

int longest_substring(string s, int k)
{
    unordered_map<char,int> M;
    int i=0,j=0,mx=-1, starting_index=-1;

    while(j<s.length())
    {
        M[s[j]]++;

        if(M.size()<k)
            j++;

        else if(M.size()==k)
        {
            if(mx<j-i+1)
            {
                mx=j-i+1;
                starting_index=i;
            }
            j++;
        }

        else  ///M.size() > k
        {
            while(M.size() > k)
            {
                M[s[i]]--;
                if(M[s[i]]==0)
                    M.erase(s[i]);
                i++;
            }
            j++;
        }
    }
    cout<<"Starting index: "<<starting_index<<endl;

    return mx;
}
/*
aabacbebebe
3
Ans: 7

aaaa
2
Ans: -1 (There's no substring with K distinct characters.)
*/
