// Problem : Given an array of n distinct elements. Find the minimum number of swaps required to sort the array in strictly increasing order.
//! T.C.= O(n*log(n))+O(n) ≈ O(n*log(n))                S.C.= O(n)
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
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
    int indxarr[n];
    vector<pair<int,int>> swapOrder;
    for(int i=0;i<n;i++)
        indxarr[i]=i;

    sort(indxarr,indxarr+n,[&](int a,int b){         //sort on the basis of vec[i].first
         return arr[a]<arr[b];
    });

    //! Now we have sorted the array values, but the indexes are unsorted, so now we'll calculate the min swaps required to sort that which in turn will be equal to min. swaps required to sort the array
    //! The unsorted index array will be of size N, containing values from 0 to n-1, so now this is similar to the ques: "min swaps required to sort array of 1 to N"
    for(int i=0;i<n;i++)
    {
        while(indxarr[i] != i)
        {
            swapOrder.push_back(make_pair(i,indxarr[i]));
            swap(indxarr[i],indxarr[indxarr[i]]);
            cnt++;
        }
    }
    cout<<"swap order(index based): \n";
    for(int i=swapOrder.size()-1;i>=0;i--)   //printing in reverse for sequence of swaps (index based)
        cout<<swapOrder[i].first<<" "<<swapOrder[i].second<<"\n";
  return cnt;
}
/*
5
10 19 6 3 5
Ans: 2

7
4 3 3 2 -1 5 0
Ans: 6

8
5 2 6 8 3 1 6 8
Ans: 4
*/
