// Problem: Given an array arr[] of distinct integers from 1 to N. The task is to find the minimum number of swaps required to sort the array.
//! T.C.= O(n)          S.C.= O(1)
#include <iostream>
#include <vector>
using namespace std;

int min_swaps_to_sort(int *,int );

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];

    cout<<min_swaps_to_sort(arr,n);
  return 0;
}
int min_swaps_to_sort(int arr[],int n)
{
    int cnt=0;
    vector<pair<int,int>> swapOrder;
    for(int i=0;i<n;i++)
    {
        while(arr[i]!=i+1)
        {
            swapOrder.push_back(make_pair(i,arr[i]-1));
            swap(arr[i],arr[arr[i]-1]);
            cnt++;
        }
    }
    cout<<"swap order(index based):\n";
    for(pair<int,int> p:swapOrder)
        cout<<p.first<<" "<<p.second<<"\n";
    return cnt;
}
/*
7
7 1 3 2 4 5 6
Ans: 5

6
2 4 5 3 1 6
Ans: 4
*/
