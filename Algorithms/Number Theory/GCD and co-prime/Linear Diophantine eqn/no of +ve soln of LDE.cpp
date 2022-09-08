//for popviciu formula: a,b,c must be +ve and a,b should be co-prime
#include <iostream>
#include <algorithm>
#include <math.h>
#define ll long long
using namespace std;

int numOfPositiveSol(int a,int b,int c);

int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    cout<<numOfPositiveSol(a,b,c);
  return 0;
}
// Function for extended Euclidean Algorithm
int gcdExtended(int a, int m, int& x, int& y)
{
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
    int res = (x % m + m) % m;
    return res;
}
int numOfPositiveSol(int a,int b,int c)
{
    if(a<0 || b<0 || c<0)  //invalid condn for popviciu
        return -1;

    int g=__gcd(a,b);
    if(c%g!=0)    //condn of integral soln of LDE
        return 0;

    //making a,b co-prime by dividing both by their gcd
    a=a/g;
    b=b/g;
    c=c/g;

    int aDash = modulo_inverse(a,b);
    int bDash = modulo_inverse(b,a);

    ll up = c - (1LL * bDash * c % a) * b - (1LL * aDash * c % b) * a + 1LL * a * b;
    ll down = 1LL * a * b;
    int ans = up / down;     //fraction calc of formula
    //cout<<up<<" "<<down<<" ";
    return ans;
}
