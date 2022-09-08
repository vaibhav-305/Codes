//Works for 64-bit numbers (long long int)
//! T.C. = O(log(n)*log(n))    excluding time required by largeMultiply()
//! S.C. = constant
#include <iostream>
using namespace std;
using llt = long long int;

llt largeMultiply(llt a, llt b, llt mod)
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

    return res % mod;
}

llt binpower(llt base, llt e, llt mod) {
    llt result = 1;
    base %= mod;
    while (e) {
        if (e & 1){
            result = largeMultiply(result,base,mod);
            //result = (uint_128)result * base % mod;
        }
        base = largeMultiply(base,base,mod);
        //base = (uint_128)base * base % mod;
        e >>= 1;
    }
    return result;
}

bool check_composite(llt n, llt a, llt d, int s) {
    llt x = binpower(a, d, n);
    if (x == 1 || x == n - 1)
        return false;
    for (int r = 1; r < s; r++) {
        //x = (uint_128)x * x % n;
        x = largeMultiply(x,x,n);
        if (x == n - 1)
            return false;
    }
    return true;
};

bool isPrime_MillerRabin(llt n) { // returns true if n is prime, else returns false.
    if (n < 2)
        return false;

    int r = 0;
    llt d = n - 1;
    while ((d & 1) == 0) {
        d >>= 1;
        r++;
    }

    for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
        if (n == a)
            return true;
        if (check_composite(n, a, d, r))
            return false;
    }
    return true;
}

int main()
{
    llt n;
    cin>>n;
    if(isPrime_MillerRabin(n))
        cout<<"Prime";
    else
        cout<<"Not Prime";
  return 0;
}
/*
1111111111111111111
Prime
59604644783353249
Prime
688846502588399
Prime
2305843009213693951
Prime
489133282872437279
Prime
1746860020068409
Prime

*/
