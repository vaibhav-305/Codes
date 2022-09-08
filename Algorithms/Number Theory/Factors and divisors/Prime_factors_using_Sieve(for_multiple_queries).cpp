//! works only for numbers till 10^6
/// Key idea: Our idea is to store the Smallest Prime Factor(SPF) for every number. Then to calculate the prime factorization of the given number by dividing the given number recursively with its smallest prime factor till it becomes 1.
#include <iostream>
#include <cstring>
using namespace std;

int sieve[1000001];

void primeFact_sieve()              ///pre-computation (takes O(n*log(log(n))) time)
{
    int maxN=1000001;

    for(int i=1;i<=maxN;i++)
        sieve[i]=i;

    for(int i=2;i*i<=maxN;i++)
    {
        if(sieve[i]==i)             //arr[i]=i means smallest factor is the number itself i.e. no. is prime.
       {
            for(int j=i*i;j<=maxN;j+=i)
            {
                if(sieve[j]==j)
                    sieve[j]=i;
            }
        }
    }
}

void find_prime_factors(int x)                  ///finding factors take O(log(num)) time i.e. depends on number
{
    while(x!=1)
    {
        cout<<sieve[x]<<" ";                      //factors will always be printed in ascending order
        x=x/sieve[x];
    }
    cout<<endl;
}
int main()
{
    int no_of_queries;
    cin>>no_of_queries;
    int query;
    primeFact_sieve();
    while(no_of_queries--)
    {
        cin>>query;
        find_prime_factors(query);
    }
  return 0;
}
