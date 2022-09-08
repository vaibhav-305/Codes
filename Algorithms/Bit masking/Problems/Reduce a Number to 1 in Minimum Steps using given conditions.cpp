/*
Q- You are given a positive number N. You have to find the minimum number of operations required to convert N into 1.
    Operations allowed :
      (i)  If n is even, you have to replace n with n/2.
      (ii) If n is odd, you can replace n with either n-1 or n+1.
  Sample Input:
  8
  Sample Output:
  3
*/
#include <iostream>
using namespace std;

int main()
{
    int n,steps=0,temp;
    cin>>n;

    while(n>1)
    {
        if(n&1)       //if n&1==1  that means no. is odd
        {
            if(n==3)
                n=n-1;
            else if(n%4==1)    //it can be represented as 4x+1
            {
                n=n-1;
            }
            else if(n%4==3)         //it is in the form 4x+3
            {
                n=n+1;
            }
        }
        else
            n=n/2;

        steps++;
    }
    cout<<steps<<endl;
  return 0;
}
/*
        4x+1                  4x+3
      -/    \+              -/    \+
      4x    4x+2          4x+2    4x+3
      |      |              |      |
      2x    2x+1          2x+1    2x+2
      |    -/  \+        -/  \+    |
      x    2x  2x+2      2x  2x+2  x+1
      :    |    |        |    |    :
     x+1   x   x+1       x    x+1  x

from above we can conclude:
    if 4x+1 --> -
    if 4x+3 --> +
                  as it will give both x and x+1 (as per need) in min. steps possible
EXCEPTION:
    only 3 is exception as tho 3 can be expressed in form of 4x+3, still minus will be done.
                      3
                    -/ \+
                    2   4
                    |   |
                    1   2
          (2 steps)     | (3 steps)
                        1
*/
