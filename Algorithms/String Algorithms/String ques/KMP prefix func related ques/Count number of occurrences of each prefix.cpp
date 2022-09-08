#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> no_of_occurences_of_each_prefix(string s);

int main()
{
    string s;
    cin>>s;
    vector<int> occ=no_of_occurences_of_each_prefix(s);
    for(int i=1;i<=s.length();i++)
        cout<<occ[i]<<" ";
  return 0;
}
vector<int> no_of_occurences_of_each_prefix(string s)
{
    int slen=s.length();

    /// step1: calculating prefix function
    int lps[slen];
    lps[0]=0;
    int i=0,j=1;
    while(j<slen)
    {
        if(s[i]==s[j]){
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

    /// step2: counting occurences of each prefix
    vector<int> occ(slen + 1);

    // Count all the suffixes that are also prefix
    for (i = 0; i < slen; i++)
        occ[lps[i]]++;

    // Add the occurences of i to smaller prefixes
    for (i = slen - 1;i > 0; i--)
        occ[lps[i - 1]] += occ[i];

    // Adding 1 to all occ[i] for all the orignal prefix
    for(int i = 0; i <= slen; i++)
        occ[i]++;

    return occ;
}
