#include <iostream>
#include <math.h>
using namespace std;

int no_of_set_bits(int );

int main()
{
    int n;
    cin>>n;

    cout<<no_of_set_bits(n);
  return 0;
}

int highestPowerOf2inRange(int n) //This is basically length of equvialent binary string representation(of n) minus 1
{
    int x=0;

    while((1<<x)<=n){
        x++;
    }

    return x-1;
}
int no_of_set_bits(int n)
{
    if(n==0)
        return 0;

    int p = highestPowerOf2inRange(n);

    return (p*pow(2,p-1))+(n-pow(2,p)+1)+no_of_set_bits(n-pow(2,p));
}
