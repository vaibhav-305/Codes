/* article link: https://www.geeksforgeeks.org/find-power-power-mod-prime/
We have to find a^(b^c) % M       where M = prime no.
convert b^c = x*(M-1)+y
because by fermat theorm : a^(M-1) ≡ 1 (% M)  which means a^(M-1) % M =1

so a^(b^c) = a^(x.(M-1) + y) = a^((M-1).x)  *  a^y
                             This part = 1     We have to find y and only evaluate a^y

we only need to find two things as:-
1. y = (B ^ C) % (M - 1)
2. Ans = (A ^ y) % M

y = (b^c)%(M-1)   (as dividend = quo*divisor +rem)
                          b^c  =  x * (M-1)  + y   thus, y is remainder of b^c % M-1
*/
//! T.C. = O(log(B) + log(C))       S.C.= O(1)
#include <iostream>
#define M 1e9+7
using namespace std;

int ApowBpowC(int a,int b,int c);

int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    cout<<ApowBpowC(a,b,c);
  return 0;
}
int fast_pow_modulo(int a, int b,int MOD)
{
    int result=1 ;

    while(b)
    {
        if(b&1)       ///if number is odd i.e. n%2!=0
        {
            result=(1ll*result * a)%MOD;
            b--;
        }
        else          ///if power is even => 2^50 = 4^25  so by reducing power to half we have reduced traversal from 50 to 25(by half)
        {
            a=(1ll*a*a)%MOD;
            b=(b>>1);     //! b=b/2
        }
    }
    return result;
}
int ApowBpowC(int a,int b,int c)
{
    int y = fast_pow_modulo(b,c,M-1);  // (b^c) % M-1
    int ans = fast_pow_modulo(a,y,M);
    return ans;
}
/*
8 4 0
Ans: 8
427077162 725488735 969284582
Ans: 464425025
690776228 346821890 923815306
Ans: 534369328
*/
