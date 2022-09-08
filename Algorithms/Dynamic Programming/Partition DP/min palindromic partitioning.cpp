//T.C.= O(n*n)*O(n)  for checking palindrome     S.C.= O(n)
#include <iostream>
#include <vector>
using namespace std;

bool isPalindrome(int i,int j,string& s){
    while(i<j){
        if(s[i]!=s[j])
            return false;
        i++,j--;
    }
    return true;
}
int solve(int i,string &s,vector<int>& memo){
    if(i==s.length())
        return 0;
    if(memo[i]!=-1)
        return memo[i];

    int temp,cuts=1e9;
    for(int k=i;k<s.length();k++){
        if(isPalindrome(i,k,s)){
            temp = 1 + solve(k+1,s,memo);
            cuts =  min(cuts,temp);
        }
    }
    return memo[i]=cuts;
}
int minPalPart_memo(string s){
    int n=s.length();
    vector<int> memo(n,-1);
    return solve(0,s,memo)-1;   //subtracting 1 because the code considers one partition on end of string , so to remove that one.
}
int minPalPart_tabl(string s){
    int n=s.length();
    vector<int> dp(n+1);

    dp[n]=0;   //base case i==n => 0

    for(int i=n-1;i>=0;i--){
        int temp,cuts=1e9;
        for(int k=i;k<s.length();k++){
            if(isPalindrome(i,k,s)){
                temp = 1 + dp[k+1];
                cuts =  min(cuts,temp);
            }
        }
        dp[i]=cuts;
    }
    return dp[0]-1;
}
int main()
{
    string s;
    cin>>s;
    //cout<<minPalPart_memo(s);
    cout<<minPalPart_tabl(s);
  return 0;
}
