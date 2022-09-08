/*
We have two fractions a/b and c/d.
Let Y = (a/b - c/d)
  Ynum/Ydeno = (a*d - c*b)/(b*d) ==> Ynum = a*d - c*b
Now,
if Ynum > 0 then a/b > c/d
if Ynum = 0 then a/b = c/d
if Ynum < 0 then a/b < c/d
*/
#include <iostream>
using namespace std;

void compare(int nume1,int deno1,int nume2, int deno2)
{
    long long int Ynum = (1ll*nume1*deno2 - 1ll*nume2*deno1);
    char ans;
    if(Ynum>0ll)
        ans='>';
    else if(Ynum==0ll)
        ans='=';
    else
        ans='<';
    printf("%d/%d %c %d/%d",nume1,deno1,ans,nume2,deno2);
}
int main()
{
    int nume1,deno1,nume2,deno2;
    cin>>nume1>>deno1>>nume2>>deno2;
    compare(nume1,deno1,nume2,deno2);
  return 0;
}
