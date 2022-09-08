/*Link: https://cses.fi/problemset/task/1733
PROBLEM:
    A period of a string is a prefix that can be used to generate the whole string by repeating the prefix. The last repetition
    may be partial. For example, the periods of abcabca are abc, abcabc and abcabca.
    Your task is to find all period lengths of a string.
SOL:
    link: https://www.youtube.com/watch?v=WJMkyBj_D_w
*/
#include <iostream>
using namespace std;

void Z_array(string str, int Z[], int n)
{
    int L, R, k;

    L = R = 0;
    for (int i = 1; i < n; i++){
        if (i > R){
            L = R = i;
            while (R<n && str[R-L] == str[R])
                R++;

            Z[i] = R-L;
            R--;
        }
        else{
            k = i-L;
            if (Z[k] < R-i+1)
                Z[i] = Z[k];
            else{
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
    string s;
    cin>>s;
    int slen = s.length();

    int Z[slen];   // Construct Z array
    Z_array(s, Z,slen);

    for(int i=0;i<slen;i++){
        if(Z[i]+i==slen)
            cout<<i<<" ";
    }
    cout<<slen<<endl;
  return 0;
}
/*
abcabca
Ans: 3 6 7   (abc, abcabc, abcabca)

*/
