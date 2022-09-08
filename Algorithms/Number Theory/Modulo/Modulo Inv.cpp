/// Works when a and m are co-prime
//! T.C. = O(log(m))
#include <iostream>
#include <algorithm>  //for __gcd()
using namespace std;

// Function for extended Euclidean Algorithm
int gcdExtended(int a, int m, int& x, int& y)
{
    //The recursive function above returns the GCD and the values of coefficients to x and y (which are passed by reference to the function).
    //This implementation of extended Euclidean algorithm produces correct results for negative integers as well.
    if (m == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcdExtended(m, a % m, x1, y1);
    x = y1;
    y = x1 - y1 * (a / m);    //as integer division is already floor by default so no need to use floor()
    return d;
}
int modulo_inverse(int a, int m)
{
	int x, y;
	int g = gcdExtended(a,m,x,y);
	if (g != 1){
		cout << "Inverse doesn't exist";
		return -1;
	}
	else
	{
		// m is added to handle negative x
		int res = (x % m + m) % m;
		return res;
	}
}
int main()
{
    int a,m;
    cin>>a>>m;
    printf("%d^-1 (mod %d) = %d",a,m,modulo_inverse(a,m));     //pow(a,m-2) % m
  return 0;
}
