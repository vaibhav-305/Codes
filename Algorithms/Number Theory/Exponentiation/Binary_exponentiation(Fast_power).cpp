///T.C. = O(log(n))         S.C.= O(1)         --for all 3 func.
#include <iostream>
#define MOD 1000000007
using namespace std;
using ll=long long;

ll fast_pow(ll ,int );
ll fast_pow_modulo(ll , int );
double fast_power(double , int );        //works for -ve powers too

int main()
{
    int a,b;
    cin>>a>>b;

    cout<<fast_pow(a,b)<<endl;         //a^b
    cout<<fast_pow_modulo(a,b)<<endl;  // (a^b)%m
    cout<<fast_power(a,b)<<endl;    //a^b  where b can be -ve too
  return 0;
}

ll fast_pow(ll a,int b)
{
    ll result=1 ;

    while(b)
    {
        if(b&1)       ///if power is odd i.e. n%2!=0
        {
            result*=a;
            b--;
        }
        else          ///if power is even => 2^50 = 4^25  so by reducing power to half we have reduced traversal from 50 to 25(by half)
        {
            a*=a;
            b=(b>>1);     //! equivalent n=n/2
        }
    }
    return result;
}
ll fast_pow_modulo(ll a, int b)
{
    ll result=1 ;

    while(b)
    {
        if(b&1)       ///if number is odd i.e. n%2!=0
        {
            result=(result * a)%MOD;
            b--;
        }
        else          ///if power is even => 2^50 = 4^25  so by reducing power to half we have reduced traversal from 50 to 25(by half)
        {
            a=(a*a)%MOD;
            b=(b>>1);     //! b=b/2
        }
    }
    return result;
}
double fast_power(double x, int y)
{
    double temp;
    if( y == 0)
        return (double)1;
    temp = fast_power(x, y/2);
    if (y%2 == 0)
        return temp*temp;
    else
    {
        if(y > 0)
            return x * temp * temp;
        else
            return (temp * temp) / x;   //For -ve y
    }
}
