/*
let a number be x
then -x will be the 2's complement of x
to find 2's complement
  first do ~x
  then add 1 in it
so 2's complement of x=-x=(~x)+1
*/
#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    //int mask=-n;
    int rsb=n & -n; //rsb=rightmost set bit
    cout<<rsb;  //prints the number which in which the only set bit is the rsb of n
  return 0;
}
