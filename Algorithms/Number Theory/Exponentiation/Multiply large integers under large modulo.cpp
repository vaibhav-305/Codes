/*
Since a and b may be very large numbers, if we try to multiply directly then it will definitely overflow. Therefore we use the basic approach of multiplication i.e.,
a * b = a + a + … + a (b times)
So we divide the above repeated steps of a in simpler way i.e.,
    If b is even then
        a * b = 2 * a * (b / 2),
    otherwise
        a * b = a + a * (b - 1)

To compute (a * b) % mod
  multiply(a,  b, mod)
  1)  ll res = 0; // Initialize result
  2)  a = a % mod.
  3)  While (b > 0)
        a) If b is odd, then add 'a' to result.
               res = (res + a) % mod
        b) Multiply 'a' with 2
           a = (a * 2) % mod
        c) Divide 'b' by 2
           b = b/2
  4)  Return res
*/
//! T.C.= O(log(b))      S.C.= O(1)
/// works for a,b,c <= 10^18
#include <iostream>
using namespace std;
using llt = long long int;

llt mulmod(llt a, llt b, llt mod)
{
    llt res = 0; // Initialize result
    a = a % mod;
    while (b > 0)
    {
        if(b % 2 == 1)    // If b is odd, add 'a' to result
            res = (res + a) % mod;

        a = (a * 2) % mod;  // Multiply 'a' with 2
        b /= 2;      // Divide b by 2
    }
    // Return result
    return res % mod;
}

int main()
{
    llt a,b,mod;
    cin>>a>>b>>mod;
    cout<<mulmod(a,b,mod);
  return 0;
}
/*
9223372036854775807 9223372036854775807 100000000000
Ans: 84232501249
*/
