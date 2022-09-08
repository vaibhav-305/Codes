//Link to 1st approach: https://www.youtube.com/watch?v=XmSOWnL6T_I   O(n*n) space
//Link to 2nd approach: https://www.youtube.com/watch?v=y2BD4MJqV20   O(1) space
#include <iostream>
#include <string>
#include <utility>
using namespace std;

string longest_palindromic_substring(string );                //! T.C.= O(n*n)    S.C.= O(n*n)
string longest_palindromic_substring_optimized(string );      //! T.C.= O(n*2n)   S.C.= O(1)

int main()
{
    string s;
    cin>>s;

    cout<<longest_palindromic_substring_optimized(s)<<"\n";
    cout<<longest_palindromic_substring(s);
  return 0;
}

pair<int,int> expandFromMiddle(string s, int left, int right)    //this runs in max T.C. of O(n)
{
    while(left>=0 && right<s.length() && s[left]==s[right])
        left--, right++;

    return make_pair(left+1,right-1);
}
string longest_palindromic_substring_optimized(string s)              //! T.C.= O(n*n)         S.C.= O(1)
{
    int n=s.length();
    if(n<2)
        return s;
    //take every point as center and iterate left and right to find max length
    //Do this for odd length and even length , store maximum length
    pair<int,int> oddlen,evenlen,tempmx;
    int l=0,r=0,maxlen=1;
    for(int i=1;i<n;i++)
    {
        oddlen= expandFromMiddle(s,i,i);
        evenlen= expandFromMiddle(s,i-1,i);

        if(oddlen.second-oddlen.first+1 < evenlen.second-evenlen.first+1)      // getting the max length pair out of the 2 pairs
            tempmx= evenlen;
        else
            tempmx=oddlen;

        if(maxlen < tempmx.second-tempmx.first+1){             // checking if maxlen is lesser than tempmx pair, if yes, this might be our longest palindromic substring
            maxlen = tempmx.second-tempmx.first+1;
            l=tempmx.first;
            r=tempmx.second;
        }
    }
    return s.substr(l,r-l+1);
}

string longest_palindromic_substring(string s)        //! T.C.= O(n*n)         S.C.= O(n*n)
{
    int n=s.length();
    int l=0,r=0,maxlen=1;   //we've initialized are palindromic string length as its first character with length 1.

    bool dp[n][n];        //an array to store length of longest palindromic substring

    //initializing the diagonal matrix with 1 as one sized length string will always be palindromic
    for(int i=0;i<n;i++)
        dp[i][i]=true;
    //initializing the diagonal ([0,1]-->[n-2,n-1]) above the main diagonal for substring of length 2
    for(int i=0;i<=n-2;i++){
        if(s[i]==s[i+1]){
            dp[i][i+1]=true;
            if(maxlen<2){//len: (i+1)-(i)+1=2
                maxlen=2;
                l=i,r=i+1;
            }
        }
        else
            dp[i][i+1]=false;
    }

    //for rest upper triangle of dp[][] matrix
    for(int y=2;y<n;y++)
    {
        int i=0,j=y;
        while(j<n)
        {
            if(s[i]==s[j] && dp[i+1][j-1]==true){
                dp[i][j]=true;
                if(maxlen<j-i+1){
                    maxlen=j-i+1;
                    l=i,r=j;
                }
            }
            else
                dp[i][j]=false;

            i++,j++;
        }
    }
    return s.substr(l,r-l+1);
}
/*
    All substrings of abccbc:-

                    end_indx
          _0_ _1__ __2__ __3___ __4____ ___5____
        0| a | ab | abc | abcc | abccb | abccbc |
 start  1|   |  b |  bc |  bcc |  bccb |  bccbc |   here matrix[start_index][end_index] -> s[start_indx]_ _ _s[end_indx]
  indx  2|   |    |   c |   cc |   ccb |   ccbc |    eg: matrix[1][4] = s[1]_ _ _s[4] (s[1]s[2]s[3]s[4])
    ↓   3| this part    |    c |    cb |    cbc |                     = bccb
        4|    of array is      |     b |     bc |
        5|___|____ useless_____|_______|______c_|

                 end indx->
         _0_ _1_ _2_ _3_ _4_ _5_
       0|_1_|_*_|↙__|↙__|↙__|↙__|   -> we'll initialize the main diagonal with 1(true) as every single length substring will be palindrome
       1|___|_1_|_*_|↙__|↙__|↙__|   -> Then we'll initialize the diagonal above the main diagonal (the * diagonal) by checking whether the 2-length adjacent substrings(see the above figure) are palindrome or not.
start  2|___|___|_1_|_*_|↙__|↙__|
indx   3|___|___|___|_1_|_*_|___|   -> Then we'll traverse the upper triangle diagonal by diagonal(above diagonal) and fill it by using the following
 ↓     4|___|___|___|___|_1_|_*_|                   s[i]_ _ _ _s[j]     if starting and ending character are same and the middle part is also palindrome then that string/substring will be palindrome
       5|___|___|___|___|___|_1_|      So basically we'll check if s[start_indx] == s[end_indx] and for the middle part , we'll see if arr[start_indx+1][end_indx-1] (basically left lower diagonal the element) is true (means inner inner part is palindrome) or false (not palindrome)
                                   if above condn is true then the string/substring s[start_indx.......end_indx] is palindrome and set the value in dp[][] as true (cause it'll be used for more sub-problems) or false if not palindrome

    So after filling the upper triangle matrix we can traverse the matrix and wherever the dp[i][j]=true , s[i...j] string/substring is palindrome.
*/
