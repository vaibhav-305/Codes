/* An efficient solution for a fixed size +ve integer (say 64 bits) is to one by one set bits, then add 1 so that only the bit after
   MSB is set. Finally right shift by 1 and return the answer. This solution does not require any condition checking.*/
/// T.C.= S.C.= O(1)
#include <iostream>
#include <math.h>
using namespace std;
using llt=long long int;

llt leftsetBitNumber(llt n)
{
    // Below steps set bits after
    // MSB (including MSB)

    // Suppose n is 273 (binary
    // is 100010001). It does following
    // 100010001 | 010001000 = 110011001
    n |= n >> 1;

    // This makes sure 4 bits
    // (From MSB and including MSB)
    // are set. It does following
    // 110011001 | 001100110 = 111111111
    n |= n >> 2;

    n |= n >> 4;
    n |= n >> 8;
    n |= n >> 16;
    n |= n >> 32;

    // Increment n by 1 so that
    // there is only one set bit
    // which is just before original
    // MSB. n now becomes 1000000000
    n = n + 1;

    // Return original MSB after shifting.
    // n now becomes 100000000
    return (n >> 1);
}

// Driver code
int main()
{
    llt n;
    cin>>n;
    cout << log2(leftsetBitNumber(n));
    return 0;
}
