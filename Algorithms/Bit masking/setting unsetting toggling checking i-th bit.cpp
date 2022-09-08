/*
Given a number, print
    ->the number produced on setting i-th bit
    ->the number produced on unsetting i-th bit
    ->the number produced on toggling i-th bit
Also check if the i-th bit is on or off
*/
#include <iostream>
using namespace std;

int main()
{
    int n,i;
    cin>>n>>i;
    //for on/setting i-th bit we use OR with ...000100... where 1 is on i-th position
    //for off/unsetting i-th bit we use AND with ...111011... where 0 is on i-th position
    //for toggling i-th bit we use XOR with ...0001000... where 1 is on i-th position
    //for checking i-th bit we can use AND with ...0001000... where 1 is on i-th position
    /// The number of bits for all the 3 masks/numbers above = number of bits in given number
    int on_mask=(1<<i); //brackett should be used as binary operators have less priority than '='
    int off_mask=~(1<<i);
    int toggle_mask=(1<<i);
    int check_mask=(1<<i);

    cout<<(n | on_mask)<<"\n";
    cout<<(n & off_mask)<<"\n";
    cout<<(n ^ toggle_mask)<<"\n";
    cout<<((n & check_mask)==0 ? "off" : "on" );
  return 0;
}
