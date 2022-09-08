/*
Q- You are given an array of length n containing numbers from 1 to n. One number is present twice in array and one is missing. You have to find these two numbers.
Example:
    Sample Input:
    7
    1 3 4 5 1 6 2
    Sample Output:
    Missing Number -> 7
    Repeating Number -> 1

*/
#include <iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];

    //--------------------------Solution---------------------------//
    //expanding our processing-input by considering arr[i] and numbers 1...N, this problem will become similar to "All Repeating except two" where unique will come once and the duplicate will come thrice which will be effectively once (as the two's xor will cancel out)
    int Xor=0,x=0,y=0,duplicate_val,unique_val;
    for(int i=0;i<n;i++)
        Xor=Xor^arr[i];
    for(int i=1;i<=n;i++)
        Xor=Xor^i;

    int rsb= (Xor & -Xor);

    for(int i=0;i<n;i++)
    {
        if(rsb & arr[i])       //if not zero
            x=x^arr[i];
        else                   //if zero
            y=y^arr[i];
    }
    for(int i=1;i<=n;i++)
    {
        if(rsb & i)       //if not zero
            x=x^i;
        else                   //if zero
            y=y^i;
    }

    //for distinguishing which one is duplicate and which is unique
    for(int i=0;i<n;i++)
    {
        if(x==arr[i])      //if x is found in arr, that means x is the duplicate one and y is the unique one
        {
            duplicate_val=x;
            unique_val=y;
            break;
        }
        else if(y==arr[i])  //if y is found in arr, that means y is the duplicate one and x is the unique one
        {
            duplicate_val=y;
            unique_val=x;
        }
    }
    cout<<"Missing Number -> "<<unique_val<<endl;
    cout<<"Repeating Number -> "<<duplicate_val<<endl;
  return 0;
}
