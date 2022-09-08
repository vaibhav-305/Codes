/*Problem : Hackerrank - Gift boxes : https://www.hackerrank.com/contests/womens-codesprint-5/challenges/gift-boxes/problem
 basically we have to find occurrences of pat in string s , and if found increase the count and remove the pattern form s, and search again till no occurences are found. (see test cases to understand more
 Intuition : This question is somewhat a general form of number of valid parenthesis where valid paranthesis is defined as a pattern of string */
//! T.C.= O(slen+patlen)     S.C. = O(slen) + O(patlen)  (stack and LPS array)
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int No_of_gifts(string s,string giftpat)
{
    int patlen=giftpat.length(),slen=s.length(),i,j,cnt=0;
    int lps[patlen];
    i=0,j=1;
    lps[0]=0;
    while(j<patlen)
    {
        if(giftpat[i]==giftpat[j])
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
    /*for(int i:lps)
        cout<<i<<" ";
    cout<<"\n";*/
    stack<pair<char,int>> St;        //stack to store the index till the pat is matched
    i=j=0;    //i--> s      j-->giftpat
    while(i<slen)
    {
        if(s[i]==giftpat[j])
        {
            St.push(make_pair(s[i],j));    //storing the characters and the index of pat till matched
            i++;
            j++;
        }
        if(j==patlen)       //j==patlen means giftpat has been traversed completely
        {
            cnt++;
            for(int k=1;k<=patlen;k++)     //removing the found pattern from stack
                St.pop();

            if(St.empty())
                j=0;
            else
                j=St.top().second+1;    // as St.top() already has the index till pat is matched, so we'll start matching from next character
        }
        else if(i<s.length() && giftpat[j]!=s[i])
        {
            if (j != 0)
                j = lps[j - 1];              //Update j as Lps of last matched character
            else{
                St.push(make_pair(s[i],-1));  //if no prefix matches , the we push -1 which means start matching from beginning.
                i = i + 1;
            }
        }
    }
    return cnt;
}
int main()
{
    string giftpat,s;
    getline(cin, giftpat);
    getline(cin, s);

    cout<<No_of_gifts(s,giftpat);
  return 0;
}
/*
ab
abab
Ans: 2

ab
aabb
Ans: 2

abc
aabcbcaabbabc
Ans: 3

abcd
abababcdzabcdcdcd
Ans: 2

can be done by string hashing as well
*/
