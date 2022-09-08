/*
Prob Statement:
Given a string, a partitioning of the string is a palindrome partitioning if every substring of the partition is a palindrome.
For example, “aba|b|bbabb|a|b|aba” is a palindrome partitioning of “ababbbabbababa”. Determine the fewest cuts needed for a
palindrome partitioning of a given string.
For example, minimum of 3 cuts are needed for “ababbbabbababa”. The three cuts are “a|babbbab|b|ababa”.
If a string is a palindrome, then minimum 0 cuts are needed. If a string of length n containing all different characters, then minimum n-1 cuts are needed.
*/
///Approach:  T.C.(Recur.)= exponential
/* i is the starting index and j is the ending index. i must be passed as 0 and j as n-1
minPalPartion(str, i, j) = 0 if i == j. // When string is of length 1.
minPalPartion(str, i, j) = 0 if str[i..j] is palindrome.

-> If none of the above conditions is true, then minPalPartion(str, i, j) can be
-> calculated recursively using the following formula.
    minPalPartion(str, i, j) = Min { minPalPartion(str, i, k) + minPalPartion(str, k+1, j)+1 }
                           where k varies from i to j-1
*/
#include <iostream>
#include <string>
using namespace std;

int minPalPartion(string ,int , int );

int main()
{
    string s;
    getline(cin, s);

    cout<<minPalPartion(s,0,s.length()-1);     //here we pass initial value of i=0 and j=s.length-1 as there are no arr[i-1] so we can pass i as 0
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
int minPalPartion(string s,int i, int j)    ///returns no. of min partitions in string to make all parts palindromic
{
    if(i>=j)     //i>j means array is empty; i==j means array single element is present; in both cases no partition is needed so return 0
        return 0;

    if(isPalindrome(s,i,j)==true)   //if string(s[i...j]) is already palindromic, no need for further partition, return 0
        return 0;

    int temp_ans, mn=INT_MAX;

    for(int k=i; k<=j-1; k++)
    {
        temp_ans = minPalPartion(s,i,k)+minPalPartion(s,k+1,j)+1;    //as it has entered the loop so that means atleast one partition will be done so ..+1

        if(temp_ans<mn)   //as we want to minimize the no. of partitions
            mn=temp_ans;
    }
    //Return minimum number of partitions
    return mn;
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
