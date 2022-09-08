/* Problem:
Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.
A palindrome string is a string that reads the same backward as forward.
    Example:
        Input: s = "aab"
        Output: [["a","a","b"],["aa","b"]]
*/
//! T.C.= exponential
#include <iostream>
#include <vector>
#include <string>
using namespace std;

void pallpart(string ,int ,vector<vector<string>>& , vector<string> );

int main()
{
    string s;
    cin>>s;
    vector<vector<string>> pall;
    pallpart(s,0,pall,{});
    for(vector<string> i:pall)
    {
        cout<<"[";
        for(string j:i)
            cout<<j<<", ";
        cout<<"]\n";
    }
    return 0;
}
bool isPallindrome(string s,int start, int endi)
{
    while(start<=endi){
        if(s[start++]!=s[endi--])
            return false;
    }
    return true;
}
void pallpart(string s,int indx,vector<vector<string>>& ans, vector<string> v)
{
    if(indx==s.length())
    {
        ans.push_back(v);
        return ;
    }

    for(int i=indx;i<s.length();i++)
    {
        if(isPallindrome(s,indx,i))
        {
            v.push_back(s.substr(indx, i-indx+1));
            pallpart(s,i+1,ans,v);
            v.pop_back();
        }
    }
}
/*
7 15
10 2 5 3 15 5 7 7 6 1 18 4 3 1

Ans: 55.33
*/
