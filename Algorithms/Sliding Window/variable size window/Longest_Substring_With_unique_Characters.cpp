#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

int longest_substring_uique(string );

int main()
{
    string s;
    cin>>s;
    cout<<longest_substring_uique(s);
  return 0;
}

int longest_substring_uique(string str)
{
    int i=0,j=0,mx=0, starting_index=-1;
    unordered_set<char> S;

    while(j<str.length())
    {
        if(S.find(str[j])==S.end()){      //if char not found in hashset
            S.insert(str[j]);
            j++;

            //answer calculation
            if(mx<(int)S.size())           //typecasting S.size() to int (necessary)
            {
                mx=S.size();
                starting_index=i;
            }
        }
        else                      //if found
        {
            //removing calulations (for i)
            while(S.find(str[j])!=S.end())        //remove until str[i] is in the hashset
            {
                S.erase(str[i]);
                i++;
            }
            S.insert(str[j]);
            j++;
        }
    }
    cout<<"Starting index: "<<starting_index<<endl;

    return mx;
}
