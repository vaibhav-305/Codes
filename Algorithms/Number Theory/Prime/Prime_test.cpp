//Problem: Check wether a number is prime or not (valid for n <= 10^12 )
//! T.C. = O(sqrt(n))       S.C. = O(1)
#include <iostream>
using namespace std;
using ll=long long;

bool isPrime(ll );

int main()
{
    ll n,cnt=0;
    cin>>n;
    if(isPrime(n))
        cout<<"Prime"<<endl;
    else
        cout<<"Not Prime"<<endl;

  return 0;
}

bool isPrime(ll n)
{
    if(n==1)
        return false;

    for(ll i=2 ; i*i<=n ; i++)
    {
        if(n%i==0)
            return false;
    }

    return true;
}
