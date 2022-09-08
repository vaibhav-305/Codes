/*
a^(p-1) ≡ 1 (mod p)      In general this theorem doesn't hold for composite numbers

Chose 'a' where
 2 <= a <= p-2     and calculate res = a^(p-1)

if res==1
    P is known as probable prime
else
    P is composite, In this case we call the base 'a' is Fermat witness for the compositeness of p.

The test will be repeated multiple times with random choices for a. If we find no witness for the compositeness, it is very likely that the number is in fact prime.
We use Binary Exponentiation to efficiently compute the power a^(p−1).

Note: There exist some composite numbers where a^(n−1) ≡ 1 (mod n) holds for all a coprime to n, for instance for the number 561=3*11*17. Such numbers are called Carmichael numbers
      The Fermat primality test can identify these numbers only, if we have immense luck and choose a base a with gcd(a,n)≠1.
The Fermat test is still be used in practice, as it is very fast and Carmichael numbers are very rare. E.g. there only exist 646 such numbers below 109.
*/
//! T.C.= O(iter * log(n))  where iter = number pf iterations           S.C.= O(1)
#include <iostream>
using namespace std;
using llt = long long int;

llt mulmod(llt a, llt b,llt mod){
    llt res = 0;
    a=a%mod;
    while(b > 0){
        if(b%2 == 1)
            res = (res+a)%mod;

        a = (a*2LL)%mod;        //2LL -> 2 in long long, this is done so that overflow doesn't occur
        b /= 2;
    }
    return res%mod;
}

llt FastPow(llt a , llt n , llt mod)
{
	llt res = 1;

	while(n)
	{
		if(n & 1)
		res = mulmod(res , a , mod);

		n >>= 1;
		a = mulmod(a , a , mod);          //we will use mulmod() because a can be very large , so a*a might overflow
	}

	return res % mod;
}
bool isPrimeFermat(llt n , int iterations = 5)
{
	if(n <= 4)
	return n == 2 || n == 3;

	for(int i=1;i<=iterations;i++)
	{
		llt a = 2 + rand() % (n - 3);
		llt res = FastPow(a , n - 1 , n);

		if(res != 1) return false;
	}

	return true;
}

int main()
{
    llt n;
    cin>>n;
    if(isPrimeFermat(n))
        cout<<"Prime";
    else
        cout<<"Not Prime";
  return 0;
}
