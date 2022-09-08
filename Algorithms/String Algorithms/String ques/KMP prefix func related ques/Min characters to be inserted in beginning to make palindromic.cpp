/* Problem: Given a string str we need to tell minimum characters to be added at front of string to make string palindrome.
        eg:  ABC
         ans: 2  (CB + ABC)
        eg: AAAACBCAA
            ans: 5  (AACBC + AAAACBCAA)
 So the naive approch will be to find the longest palindromic prefix ( s[0...i] (i<n) is palindrome) the remaining characters (which are not in longest palindromic prefix) will be the answer and will be added in front in reverse order.
 The naive approach will take T.C.= O(n*n).
 We can optimize this by using the concept of prefix array of KMP for finding longest palindromic prefix.

 The idea is to concatenate string and its reverse, and create a string “S$R” where S is given string, $ is a special character should not be present in string and , and R is reverse of string.
 Build the prefix array for concatenated string.

 For string = AACECAAAA
 Concatenated String = AACECAAAA$AAAACECAA
 LPS array will be {0, 1, 0, 0, 0, 1, 2, 2, 2, 0, 1, 2, 2, 2, 3, 4, 5, 6, 7}
Here we are only interested in the last value of this lps array because it shows us the largest suffix of the reversed string that matches the prefix of the original string i.e these many characters already satisfy the palindrome property.
Finally minimum number of character needed to make the string a palindrome is length of the input string minus last entry of our lps array
*/
//! T.C.= O(n+n)         S.C.= O(n+n)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int min_char_insert(string );

int main()
{
    string s;
    cin>>s;

    cout<<min_char_insert(s);
  return 0;
}
int min_char_insert(string S)
{
    string R=S;
    reverse(R.begin(), R.end());     //reversing the given string

    string concat= S+"$"+R;

    //computing lps array for concat
    int lps[concat.length()];
    int i=0,j=1;
    lps[0]=0;
    while(j<concat.length())
    {
        if(concat[i]==concat[j])
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

    // By subtracting last entry of lps vector from
    // string length, we will get our result
    int res= S.length() - lps[concat.length()-1];

    //for printing characters which are to be added
    cout<<R.substr(0,res)<<"\n";

  return res;
}
