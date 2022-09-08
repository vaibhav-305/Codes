#include <iostream>
#include <algorithm>
#include <cstring>
#include <math.h>
#include <vector>
//#include <vector>
//#define MOD 1000000007 //1e9 + 7
using namespace std;
using llt = long long int;
vector<int> primes;

void sievePrimes(int n)
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
    for(int i=2;i<=n;i++)
    {
        if(isprime[i])
            primes.push_back(i);
    }

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T,indx;
    cin>>T;
    llt l,r,sz;
    sievePrimes(sqrt(1000000000));
    bool isPrime[100000];
    while(T--){
        cin>>l>>r;
        if(l==1)
            l++;
        if(r<2){
            cout<<"\n";
            continue;
        }
        indx=upper_bound(primes.begin(),primes.end(),sqrt(r))-primes.begin();
        indx--;
        sz=r-l+1;
        for(llt i=0;i<sz;i++)
            isPrime[i]=true;
        for(int i=0;i<=indx;i++)
        {
            llt firstMultiple = (l/primes[i]) * primes[i];    //its basically floor(l/pr) * pr
            if(firstMultiple < l)
                firstMultiple+=primes[i];

            for(llt j=max(firstMultiple,(llt)(primes[i]*primes[i]));j<=r;j+=primes[i])
                isPrime[j-l]=false;
        }
        for(llt i=l;i<=r;i++)
        {
            if(isPrime[i-l])
                cout<<i<<"\n";
        }
        cout<<"\n";
    }
return 0;
}
