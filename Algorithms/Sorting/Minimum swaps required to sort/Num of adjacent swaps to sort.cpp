//Number of swaps to sort when only adjacent swapping allowed
/**  It can be solved using the fact that number of swaps needed is equal to number of inversions. So we basically need to count inversions in array.
The fact can be established using below observations:
1) A sorted array has no inversions.
2) An adjacent swap can reduce one inversion. Doing x adjacent swaps can reduce x inversions in an array.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int adj_swaps_to_sort(int *,int );

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];

    cout<<adj_swaps_to_sort(arr,n);
  return 0;
}
int adj_swaps_to_sort(int )
