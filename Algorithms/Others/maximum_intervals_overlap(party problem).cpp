/**Find the point where maximum intervals overlap*/
// n O(n*log(n)) time and O(1) space
#include <iostream>
#include <algorithm>
using namespace std;

void findMaxGuests(int arr1[], int exit1[], int n)
{
    sort(arr1,arr1+n);
    sort(exit1,exit1+n);
    int guests_in=1,max_guest=1,time1=arr1[0];
    int i=1,j=0;
    while(i<n && j<n)
    {
        if(arr1[i]<=exit1[j])
        {
            guests_in++;
            if(max_guest<guests_in)
            {
                max_guest=guests_in;
                time1=arr1[i];
            }
            i++;
        }
        else
        {
            guests_in--;
            j++;
        }
    }
    cout<<max_guest<<" "<<time1;
}
int main()
{
    int n;
    cin>>n;
    int arr1[n],exit1[n];
    for(int i=0;i<n;i++)
        cin>>arr1[i];
    for(int i=0;i<n;i++)
        cin>>exit1[i];
    findMaxGuests(arr1,exit1,n);
  return 0;
}
