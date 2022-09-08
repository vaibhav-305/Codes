/*
Whenever we need to find leading digits , we use logarithm (of base 10)
*/
#include <iostream>
#include <math.h>
using namespace std;
using ll = long long;

ll findLeadingDigits(int a,int b,int M)
{
    ll firstM;

    double y = (double)b * log10(a * 1.0);

    // Extract the number after decimal
    y = y - floor(y);

    // Find 10 ^ y
    double temp = pow(10.0, y);

    // Move the Decimal Point M - 1 digits forward
    firstM = temp * pow(10, M - 1);

    return firstM;
}

int main()
{
    int a,b,M;
    cin>>a>>b>>M;
    cout<<findLeadingDigits(a,b,M);
  return 0;
}
