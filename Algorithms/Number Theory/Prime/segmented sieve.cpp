//! works for r <= 10^12   ans r-l <= 10^6
#include <iostream>
#include <vector>
#include <math.h>
#include <cstring>
using namespace std;
typedef long long int llt;

void printPrimesInRange(llt l,llt r);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    llt l,r;     // find all primes between l and r (both inclusive)
    cin>>l>>r;
    printPrimesInRange(l,r);
    return 0;
}
vector<int> sievePrimes(int n)
{
    bool isprime[n+1];
    memset(isprime,true,sizeof(isprime));
    for(int i=2;i*i<=n;i++)
    {
        if(isprime[i])
        {
            for(int j=i*i;j<=n;j+=i)
                isprime[j]=false;
        }
    }
    vector<int> primes;
    for(int i=2;i<=n;i++)
    {
        if(isprime[i])
            primes.push_back(i);
    }
    return primes;
}
void printPrimesInRange(llt l,llt r)
{
    if(l==1)
        l++;
    if(r<2){
        cout<<"no primes in given range";
        return ;
    }

    /// Step1: generate all primes till sqrt(r)
    vector<int> primeTillSqrt=sievePrimes(sqrt(r));

    /// Step2: create a array of size r-l+1 and initialize it to true
    bool isprime[r-l+1];
    memset(isprime,true,sizeof(isprime));

    /// Step3: for all prime numbers generated in step 1, mark its multiples as false
    for(int pr:primeTillSqrt)
    {
        llt firstMultiple = (l/pr) * pr;    //its basically floor(l/pr) * pr
        if(firstMultiple < l)
            firstMultiple+=pr;

        for(llt j=max(firstMultiple,(llt)(pr*pr));j<=r;j+=pr)
            isprime[j-l]=false;
    }

    /// Step4: get all primes
    for(llt i=l;i<=r;i++)
    {
        if(isprime[i-l])
            cout<<i<<" ";
    }
}
