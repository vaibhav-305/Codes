//For prob statement see Palindrome_partition(Recursive)
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int minPalPartion(string ,int , int, vector<vector<int>>& );

int main()
{
    string s;
    getline(cin, s);
    int slen=s.length();

    vector<vector<int>> memo(slen+1, vector<int>(slen+1,-1));
    cout<<minPalPartion(s,0,s.length()-1,memo);     //here we pass initial value of i=0 and j=s.length-1 as there are no arr[i-1] so we can pass i as 0
    for(int i=0;i<=slen;i++)
    {
        cout<<"\n";
        for(int j=0;j<=slen;j++)
            cout<<memo[i][j]<<" ";
    }
  return 0;
}

bool isPalindrome(string s, int i, int j)
{
    while(i < j)
    {
      if(s[i] != s[j])
        return false;
      i++;
      j--;
    }
    return true;
}

///T.C.=O(n*n*n)        S.C.=O(n*n)
int minPalPartion(string s,int i, int j, vector<vector<int>>& memo)    ///returns no. of min partitions in string to make all parts palindromic
{
    if(i>=j)     //i>j means array is empty; i==j means array single element is present; in both cases no partition is needed so return 0
        return 0;

    if(isPalindrome(s,i,j)==true)   //if string(s[i...j]) is already palindromic, no need for further partition, return 0
        return 0;

    if(memo[i][j]!=-1)
        return memo[i][j];

    int temp_ans, mn=INT_MAX;

    for(int k=i; k<=j-1; k++)
    {
        temp_ans = minPalPartion(s,i,k,memo) + minPalPartion(s,k+1,j,memo)+1;    //as it has entered the loop so that means atleast one partition will be done so ..+1

        if(temp_ans<mn)   //as we want to minimize the no. of partitions
            mn=temp_ans;
    }
    //Return minimum number of partitions
    memo[i][j] = mn;
    return mn;  //of memo[i][j] does'nt matter as both are same
}
/*
Dataset:

ababbbabbababa
answer: 3 (a|babbbab|b|ababa)

nitin
answer: 0 (already palindromic)

abcde
answer: 4 (a|b|c|d|e)

nitiu
answer: 3 (n|iti|u)
*/

