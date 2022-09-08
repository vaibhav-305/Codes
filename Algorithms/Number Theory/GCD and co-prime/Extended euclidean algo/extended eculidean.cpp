//! T.C.= O(log(max(a,b)))
#include <iostream>
using namespace std;

int gcdExtended(int a, int b, int& x, int& y)
{
    //The recursive function above returns the GCD and the values of coefficients to x and y (which are passed by reference to the function).
    //This implementation of extended Euclidean algorithm produces correct results for negative integers as well.
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcdExtended(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);    //as integer division is already floor by default so no need to use floor()
    return d;
}
int main()
{
    int a,b,gcd,x,y;
    cout<<"a: ";
    cin>>a;
    cout<<"b: ";
    cin>>b;
    gcd = gcdExtended(a,b,x,y);
    printf("%d.(%d) + %d.(%d) = %d",a,x,b,y,gcd);
  return 0;
}
