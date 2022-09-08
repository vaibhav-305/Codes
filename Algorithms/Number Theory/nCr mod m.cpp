#include <iostream>
using namespace std;
const int mod=1e9+7;

int fastPow(int n,int p)
{
    int ans=1;
    while(p)
    {
        if(p%2==0)
        {
            n=(1ll*n*n)%mod;
            p/=2;
        }
        else
        {
            ans=(1ll*ans*n)%mod;
            p--;
        }
    }
    return ans;
}
int modinv(int n)
{
    return fastPow(n,mod-2);
}
int nCr(int n, int r)
{
    int fact[1000+1];
    fact[0]=1;
    fact[1]=1;
    for(int i=2; i<=1000; i++)
    {
        fact[i]=(1ll*i*fact[i-1])%mod;
    }
    return ( 1ll* ((1ll*fact[n]*modinv(fact[r]))%mod) * modinv(fact[n-r]) )%mod;
}
int main()
{
    int n,r;
    cin>>n>>r;
    cout<<nCr(n,r);
  return 0;
}
