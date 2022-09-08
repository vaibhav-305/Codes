/* Problem:
Given an array of size n, return the majority element.

The majority element is the element that appears more than [n/2] times.
You may assume that the majority element always exists in the array.
*/
//! T.C.= O(n)      S.C.= O(1)
#include <iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];

    //---------------------Algorithm----------------------/
    int element, cnt=0;
    for(int i=0;i<n;i++)
    {
        if(cnt==0)
            element=arr[i];
        if(element==arr[i])
            cnt++;
        else
            cnt--;
    }
    cout<<"Max occurence element is: "<<element;
  return 0;
}
