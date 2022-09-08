///Sieve of Eratosthenes: works only if n is in INTEGER(2^32) range (better in range of 10^7) or else memory overflow(Segmentation fault) will be there.
/// T.C.= O(n*log(log(n)))         S.C.= O(n)
#include <iostream>
#include <cstring>
using namespace std;
using ll=long long;

void Sieve_of_Eratosthenes(int );

int main()
{
    ll n;
    cin>>n;

    Sieve_of_Eratosthenes(n);

  return 0;
}

void Sieve_of_Eratosthenes(int n)
{
    // Create a boolean array "prime[0..n]" and initialize
    // all entries it as true.A value in prime[i] will
    // finally be false if i is Not a prime, else true.
    bool isprime[n + 1];
    memset(isprime, true, sizeof(isprime));

    for(int i=2 ; i*i<=n ; i++)
    {
        // If prime[i] is not changed,then it is a prime
        if(isprime[i] == true)
        {
            // Update all multiples of i greater than or
            // equal to the square of it numbers which are multiple
            // of p and are less than i*i are already been marked.
            for(int j=i*i ; j<=n ; j+=i)
                isprime[j] = false;
        }
    }

    // Print all prime numbers
    for(int i = 2; i<=n; i++)
        if (isprime[i])
            cout<< i <<" ";
}
