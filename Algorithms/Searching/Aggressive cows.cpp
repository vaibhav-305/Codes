//! T.C.= O(n*log(n))         S.C.= O(1)
#include <iostream>
#include <algorithm>
using namespace std;

int largest_minimum_distance(int *,int ,int );

int main()
{
    int n,C;       //C -> no. of cows
    cin>>n>>C;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];

    cout<<largest_minimum_distance(arr,n,C);
  return 0;
}
int canPlaceCows(int arr[],int n,int C,int targetDistance)
{
    int cows=1,dist=0;
    int prev=0;
    for(int i=1;i<n;i++)
    {
        dist=arr[i]-arr[prev];
        if(dist>=targetDistance)
        {
            cows++;
            prev=i;
        }

        if(cows==C)
            return true;
    }
    return false;
}
int largest_minimum_distance(int arr[],int n,int C)
{
    sort(arr,arr+n);

    int res;

    int low=1;   //atleast a distance of 1 unit will be there between 2 consecutive stalls
    int high=arr[n-1]-arr[0];
    int mid;
    while(low<=high)
    {
        mid=low+(high-low)/2;

        if(canPlaceCows(arr,n,C,mid))
        {
            res=mid;
            low=mid+1;
        }
        else
            high=mid-1;
    }
    return res;
}
/*
6 4
0 3 4 7 10 9

6 3
0 4 3 7 10 9
*/
