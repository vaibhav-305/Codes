/* Problem:
You are given two numbers A and B. You are given two more numbers left and right, representing a range [left,right].
You have to set bits in B which are set in A lying in the above mentioned range and leave the remaining as it is.  Print the updated number B.
ex: A= 10 -> 10101010101  [3,7] range
                 ^   ^
    B= 13 -> 10010011001

        ans: 10011011101 -> 15
             🡡     🡡🡡🡡🡡
            11   ...4321    numbering
*/
#include <iostream>
#include <math.h>
using namespace std;
using ll=long long;

int main()s
{
    ll A, B, r, l;
    cin>>A>>B>>l>>r;
    ///we will make a mask ..00111100.. where in [left, right] all bits will be 1 rest all zero and then do AND operation with A to get final-mask and then do OR with B to get answer.
    ll mask=(1<<(r-l+1))-1;    //generate 1..1111
    mask = (mask<<(l-1));        //we make mask like  1111...1000..0
    mask = (mask & A);

    //cout<<mask<<endl;

    cout<<(B | mask);     //answer

  return 0;
}
