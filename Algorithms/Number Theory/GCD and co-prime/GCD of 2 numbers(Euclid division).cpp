/*                                          { a            ,if b=0
Acc to Euclid gcd is defined as,  gcd(a,b)= {
                                            { gcd(b, a%b)  ,otherwise
Some properties of gcd:-
    -> gcd(a,0)= gcd(0, a)= a
    -> gcd(a,b)= gcd(b,a)
    -> gcd(a,b)= gcd(a-b, b)= gcd(a, b-a)

Example= gcd(12, 140)            running the recursive definition defined above
       =     140, 12
       =     12, 8          ( 140 % 12 = 8 )
       =     8, 4           ( 12 % 4 = 4)
       =     4, 0 -> Ans.   ( 8 % 4 = 0)

*/
//! T.C.= O(log(max(a,b)))     where a, b are 2 numbers whose gcd is to be found
#include <iostream>
using namespace std;

int GCD(int a, int b)            //written the Euclid definition in recursive form
{
    if(b==0)
        return a;
    else
        return GCD(b, a%b);
}
int main()
{
    int a,b;
    cin>>a>>b;

    cout<<GCD(a,b);
  return 0;
}
