//The method used is Kernighans Algo
#include <iostream>
using namespace std;

int main()
{
    int n, cnt=0,rsb;
    cin>>n;
    /* The idea is to use the concept of rsb(rightmost set bit).
       Everytime we calculate the rsb-->increase count by 1-->unset the current rsb--> repeat the same until number becomes zero
    */
    while(n!=0)
    {
        rsb=n & -n;
        n=n-rsb;
        cnt++;
    }
    cout<<cnt;
  return 0;
}
