#include <iostream>
#include <cstring>
using namespace std;
using ll=long long;

void optimized_primeFact(int n);
void naive_primeFact(int n);

int main()
{
    ll n;
    cin>>n;

    //naive_primeFact(n);
    optimized_primeFact(n);

  return 0;
}

void optimized_primeFact(int n)                  /// T.C.=O(sqrt(n))
{
    int cnt=0;

    for(int i=2; i*i<=n; i++)
    {
        if(n%i==0)
        {
            cnt=0;
            while(n%i==0)
            {
                cnt++;
                n=n/i;
            }
            cout<<i<<"^"<<cnt<<endl;
        }
    }
    //if no. is prime
    if(n>1)
        cout<<n<<"^"<<1<<endl;
}
void naive_primeFact(int n)                      ///Worst case(if no. is prime) T.C.=O(n)
{
    int cnt=0;

    for(int i=2; i<=n; i++)
    {
        if(n%i==0)
        {
            cnt=0;
            while(n%i==0)
            {
                cnt++;
                n=n/i;
            }
            cout<<i<<"^"<<cnt<<endl;
        }
    }
}
