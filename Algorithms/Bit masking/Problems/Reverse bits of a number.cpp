#include <iostream>
#include <math.h>
#include <cmath>         //log2() is in this header file
using namespace std;

int main()
{
    int n;
    cin>>n;
    int rsbindx=log2(n & -n);
    cout<<rsbindx<<endl;

    n=(n>>rsbindx);
    cout<<n<<"\n";
    int rev=0,cnt=0;
    while(n!=0)
    {
        if(1&n)        //if 1
        {
            rev=(rev<<cnt);
            rev=(rev | 1);
            cnt=0;
        }

        cnt++;
        n=(n>>1);
    }
    cout<<rev;
  return 0;
}
