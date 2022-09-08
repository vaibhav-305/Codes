// calculate pow(a,1/n) => a^(1/n)
//! T.C.= O( log(n*pow(10,d)) * log(m) )     where log(n * pow(10,d)) will be Time taken in Nth_pow binary searching (pow(10,d) for approximation and log(m) will time taken in fast_pow.
#include <iostream>
#include <iomanip>
using namespace std;

double Nth_pow(int a, int n);

int main()
{
    int a,n;
    cin>>a>>n;

    cout << fixed << setprecision(5);     // printing till 5 places after decimal
    cout<<Nth_pow(a,n);
  return 0;
}
double fast_pow(double x, int n)
{
    double res=1.0;
    while(n)
    {
        if(n&1){     //n is odd
            res=res*x;
            n--;
        }
        else{
            x=x*x;
            n=(n>>1);       // n=n/2
        }
    }
    return res;
}
double Nth_pow(int a, int n)
{
    double low=1;
    double high=(double)a;
    double epsilon=1e-6;         //approximation up-till 5 places after decimal
    double temp;

    while((high-low)>epsilon)             //calculate till 5 places after decimal
    {
        double mid = (high+low)/2.0;
        temp=fast_pow(mid,n);

        if(temp==a)
            return mid;
        else if(temp < a )
            low=mid;
        else
            high=mid;
    }

    cout<<low<<" "<<high<<"\n";

    return low;      //can return high too as both have same value
}
