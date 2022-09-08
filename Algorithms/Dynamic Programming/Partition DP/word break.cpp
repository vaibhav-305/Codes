#include <iostream>
#include <set>
#include <vector>
using namespace std;

bool solve(int i,string word,set<string>& S,vector<int>& dp){
    if(i==word.length())
        return true;
    if(dp[i]!=-1)
        return dp[i];

    string temp="";
    for(int j=i;j<word.length();j++){
        temp.push_back(word[j]);

        if(S.find(temp)!=S.end() && solve(j+1,word,S,dp))
            return dp[i]=true;

    }
    return dp[i]=false;
}
bool isWordBreakPossible(string word,vector<string>& arr)
{
    int n=word.length();
    vector<int> dp(n,-1);
    set<string> S(arr.begin(),arr.end());
    return solve(0,word,S,dp);
}
int main()
{
    string word;
    cin>>word;
    int n;
    cin>>n;
    vector<string> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<isWordBreakPossible(word,arr);
  return 0;
}
/*
aaaaaaa
2
aaaa aaa
*/
