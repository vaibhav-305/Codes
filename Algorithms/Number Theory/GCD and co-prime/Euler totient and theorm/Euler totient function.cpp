/* Euler’s Totient function phi(n) for an input n is the count of numbers in {1, 2, 3, …, n} that are relatively prime to n, i.e.,
   the numbers whose GCD (Greatest Common Divisor) with n is 1
*/
#include <iostream>
using namespace std;

long long euler_totient1(long long ) ;

int main()
{
    long long n;
    cin>>n;
    cout<<euler_totient1(n);
  return 0;
}
long long euler_totient1(long long n)          //! T.C.= O(sqrt(n))      S.C.= O(1)         Used when n is large ( n > 1e6 )
{
    long long res=n;
    for(long long i=2;i*i<=n;i++){
        if(n%i==0){
            res=res/i;
            res=res*(i-1);
            while(n%i==0)
                n=n/i;
        }
    }
    if(n>1){
        res=res/n;
        res=res*(n-1);
    }
    return res;
}
