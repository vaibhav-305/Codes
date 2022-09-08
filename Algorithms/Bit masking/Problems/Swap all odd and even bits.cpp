/*Problem:
You are given a number n.You have to swap all odd position bits with even position bits.
Every odd position bit is swapped with adjacent bit on left side. Every even position bit is swapped with adjacent bit on right side.
Print the number formed after swapping.
*/
#include <iostream>
using namespace std;
using ll=long long;

int main()
{
    int n;
    cin>>n;

    /**
        For masks such as 101010101...   or 01010101...
        use hexadecimal numbers
        0x5=0101                    0xA=1010
        0x55=01010101               0xAA=10101010
        0x555=010101010101          0xAAA=101010101010
                            ...and so on to get required length mask
    */

    int even_mask=0xAAAAAAAA;      //1 at even places ; mask of 32 bit is taken as after AND operation the non-use bits will be off
    int odd_mask=0x55555555;       //1 at odd places  ; mask of 32 bit is taken as after AND operation the non-use bits will be off

    even_mask=(n & even_mask);
    odd_mask=(n & odd_mask);

    even_mask=(even_mask>>1);
    odd_mask=(odd_mask<<1);

    cout<<(even_mask | odd_mask);

  return 0;
}
