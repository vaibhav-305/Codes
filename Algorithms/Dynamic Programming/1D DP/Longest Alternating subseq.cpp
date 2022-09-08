//! T.C.= O(n)  S.C.= O(1)
//Link: https://www.youtube.com/watch?v=UogHvfQ3e18
#include <iostream>
using namespace std;

int LAS(int arr[],int n)
{
    int ma=1,mi=1;
    for(int i=1;i<n;i++){
        if(arr[i]>arr[i-1])
            ma=mi+1;
        else if(arr[i]<arr[i-1])
            mi=ma+1;
    }
    return max(ma,mi);
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<LAS(arr,n);
  return 0;
}
/*
10
1 17 5 10 13 15 10 5 16 8
Ans: 7
*/
