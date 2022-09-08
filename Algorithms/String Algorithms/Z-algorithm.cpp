/* THIS ALGO IS USED WHEN WE HAVE TO DEAL WITH PREFIX LENGTHS  of strings/substrings (length of the longest substring starting from any index (> 0 for same string) which is also a prefix of string).
This algorithm finds all occurrences of a pattern in a text in linear time.
In this algorithm, we construct a Z array.

What is Z Array?
For a string str[0..n-1], Z array is of same length as string. An element Z[i] of Z array stores length of the longest substring starting from str[i] which is also a prefix of str[0..n-1].
The first entry of Z array is meaning less as complete string is always prefix of itself.
    Example:
    Index            0   1   2   3   4   5   6   7   8   9  10  11
    Text             a   a   b   c   a   a   b   x   a   a   a   z
    Z values         X   1   0   0   3   1   0   0   2   2   1   0

• The idea is to concatenate pattern and text, and create a string “P$T” where P is pattern, $ is a special character should not be present in pattern and text, and T is text. Build the Z array for concatenated string. In Z array, if Z value at any point is equal to pattern length, then pattern is present at that point.
    Example:
    Pattern P = "aab",  Text T = "baabaa"

    The concatenated string is = "aab$baabaa"
					      a  a  b  $  b  a  a  b  a  a
    Z array for above concatenated string is {x, 1, 0, 0, 0, 3, 1, 0, 2, 1}.
    Since length of pattern is 3, the value 3 in Z array indicates presence of pattern.
*/
//! T.C. = O(m+n)        S.C.= O(m+n)
#include <iostream>
#include <string>
using namespace std;

void z_algorithm(string , string );

int main()
{
    string str,pat;
    getline(cin,str);
    getline(cin,pat);

    z_algorithm(str, pat);
  return 0;
}

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
void z_algorithm(string str, string pat)
{
    string concat = pat + "$" + str;
    int l = concat.length();

    // Construct Z array
    int Z[l];
    Z_array(concat, Z,l);

    // now looping through Z array for matching condition
    for (int i = 0; i < l; ++i)
    {
        // if Z[i] (matched region) is equal to pattern length we got the pattern
        if (Z[i] == pat.length())
            cout << "Pattern found at index "<< i - pat.length()-1 << endl;
    }
}
