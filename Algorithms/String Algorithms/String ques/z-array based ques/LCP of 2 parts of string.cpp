/* Link: https://www.codechef.com/problems/INSQ15_A
PROBLEM
    You are given a string S of length L and Q queries in form of a index P.
    You need to calculate LCP(Longest Common Prefix) of the two parts ie first part is [0,P-1] and second part is [P,L-1].
SOL:
    First we will see the solution using Z-Algorithm.
    This algorithm takes a string[0,L-1] as an input and gives a array called Z-array[0,L-1] as output.
    Z[p] (where p varies from 1 to L-1) gives the value of the longest possible prefix of the string[p,L-1] which is also the prefix of the string[0,L-1].
    In other words we can say that Z[p] calculates longest common prefix of the string[0,L-1] and the string [p,L-1].

    In this question it was asked to calculate longest common prefix of the string [0,p-1] and string [p,L-1] (1<=p<=L-1).

    For any query p, if length of first part(length of first part is p) is less than or equal to Z[p] then answer will always be equal to the length of the first part i.e. p.
    If length of first part is greater than or equal to Z[p] then answer will always be equal to the value of Z[p].
    Briefly, for any query, we get a index p as input then answer for that query will be:
    ans = min( p , Z[p] ).
This can also be done by Binary Search + string hashing in O(N + Q*log(N)) time complexity (see rabin-karb based ques folder)*/
//! Complexity is O(N + Q) time. Construction of Z-array is in O(N) and each query is answered in O(1) time hence N+Q
#include <iostream>
#include <string>
using namespace std;

void Z_array(string str, int Z[], int n)
{
    int L, R, k;

    // [L,R] make a window which matches with prefix of s
    L = R = 0;
    for (int i = 1; i < n; i++)               //i will start with 1 as index zero value(Z[0]) makes no sense in algorithm
    {
        // if i>R nothing matches so we will calculate.
        // Z[i] using naive way.
        if (i > R)
        {
            L = R = i;

            // R-L = 0 in starting, so it will start checking from 0'th index. For example,for "ababab" and i = 1, the value of R
            // remains 0 and Z[i] becomes 0. For string "aaaaaa" and i = 1, Z[i] and R become
            while (R<n && str[R-L] == str[R])
                R++;

            Z[i] = R-L;
            R--;
        }
        else
        {
            // k = i-L so k corresponds to number which
            // matches in [L,R] interval.
            k = i-L;

            // if Z[k] is less than remaining interval then Z[i] will be equal to Z[k].
            // For example, str = "ababab", i = 3, R = 5 and L = 2
            //i.e. If value does not streches till the right bound
            if (Z[k] < R-i+1)
                Z[i] = Z[k];

            // For example str = "aaaaaa" and i = 2, R is 5,
            // L is 0
            else
            {
                // else start from R and check manually
                L = i;
                while (R<n && str[R-L] == str[R])
                    R++;

                Z[i] = R-L;
                R--;
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin>>s;
    int Z[s.length()];
    Z_array(s, Z,s.length());
    int Q,p;
    cin>>Q;
    while(Q--){
        cin>>p;
        cout<<min(p , Z[p])<<"\n";
    }
  return 0;
}

/*
Input:
abababa
4
1
2
3
6

Output:
0
2
0
1
*/
