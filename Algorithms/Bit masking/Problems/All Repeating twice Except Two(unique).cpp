/*
Q- You are given an array of numbers. You have to find 2 non-repeating numbers in an array. All repeating numbers are repeating even number of times.
Example:
    Sample Input:
    6
    23 27 23 17 17 37
    Sample Output:
    27
    37
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

    /*----------------solution-------------*/
    int xortotal=0,x=0,y=0,rsb;
    for(int i=0;i<n;i++)
        xortotal=(xortotal^arr[i]);

    rsb=(xortotal & -xortotal);

    for(int i=0;i<n;i++)
    {
        if(rsb & arr[i])         //if not zero
            x=(x^arr[i]);
        else              //if zero
            y=(y^arr[i]);
    }
    cout<<x<<"\n"<<y<<endl;
  return 0;
}
