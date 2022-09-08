//Problem: Find the count of all numbers which have same no. of set bits as of n but are smaller than n.
#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
using ll = long long;

ll no_of_numbers(ll );

int main()
{
    ll n;
    cin>>n;
    cout<<no_of_numbers(n);
  return 0;
}

ll C(int n,int r)
{
    if(r>n)
    {
        cout<<"error"<<endl;
        return -1;
    }
    if(n==r)
        return 1;

    if(r>(n/2))
        r=n-r;
    long long nn=1,nr=1,m;
    while(r>0)
    {
        nn*=(long long int)n;
        nr*=(long long int)r;

        m = __gcd(nn, nr);
        nn /= m;
        nr /= m;

        n--,r--;
    }
    return nn/nr;
}
int num_size(ll n)
{
    int cnt=0;              //0-->0(binary) has size 1 for representation
    while(n!=0)
    {
        n=(n>>1);
        cnt++;
    }
    return cnt;
}
pair<ll,int> util(ll n)
{
    ll lsb,rsb;
    int cnt=0;
    while(n!=0)
    {
        lsb=n;
        rsb=(n & -n);
        n=n-rsb;
        cnt++;
    }
    return {lsb, cnt};
}
ll no_of_numbers(ll n)
{
    pair<ll,int> p=util(n);        //{lsb, cnt}
    if(p.second==0 || ((p.first<<1)-1==n) )
        return 0;
    //cout<<p.first<<" - "<<p.second<<" = "<<num_size(p.first)<<" & "<<C(num_size(p.first)-1,p.second)<<endl;
    return no_of_numbers(n-p.first)+C(num_size(p.first)-1,p.second);
}
