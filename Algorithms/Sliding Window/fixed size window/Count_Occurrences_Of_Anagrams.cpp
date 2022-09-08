/*
Given a word pat and a text 'txt. Return the count of the occurences of anagrams of the word in the text.
Note: An anagram is a word or phrase that's formed by rearranging the letters of another word or phrase. For example, the letters that make up “A decimal point” can be turned into the anagram “I’m a dot in place.”
For example:
txt = forxxorfxdofr
pat = for
Output: 3
Explanation: for, orf and ofr appears
in the txt, hence answer is 3.

txt = aabaabaa
pat = aaba
Output: 4
Explanation: aaba is present 4 times
in txt.
*/
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int no_of_occurences(string , string );

int main()
{
    string txt,pat;
    cin>>txt>>pat;

    cout<<"\n"<<no_of_occurences(txt,pat);
  return 0;
}

int no_of_occurences(string txt, string pat)
{
    unordered_map<char, int> M;
    int lenM=0, cnt=0,i,j, patlen=pat.length();   //patlen will be the window size
    i=0,j=patlen;
    for(char c:pat)
        M[c]++;

    lenM=M.size();

    //first window
    for(int x=0;x<patlen;x++)
    {
        if(M.find(txt[x])!=M.end())
        {
            M[txt[x]]--;
            if(M[txt[x]]==0)
                lenM--;
        }
    }
    if(lenM==0)
    {
        cout<<i<<" ";
        cnt++;
    }

    //sliding the window
    while(j<txt.length())          //before loop run, i=0, j=patlen
    {
        if(M.find(txt[i])!=M.end()){
            if(M[txt[i]]==0)
                lenM++;
            M[txt[i]]++;
        }
        i++;

        if(M.find(txt[j])!=M.end()){
            M[txt[j]]--;
            if(M[txt[j]]==0)
                lenM--;
        }
        j++;

        if(lenM==0){
            cout<<i<<" ";   //prints starting index of found anagram in txt
            cnt++;
        }
    }

    return cnt;
}
