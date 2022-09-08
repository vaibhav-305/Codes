//! T.C.= O(n)      S.C.=O(n)
// Same question: Count number of subarrays with given XOR. in XOR just replace "curr_sum+=arr[i]" --> "curr_sum^=arr[i]" & "curr_sum-k"-->"curr_sum^k".
#include <iostream>
#include <unordered_map>
using namespace std;
using llt=long long int;

llt count_subarrays(int arr[],int n,llt k)
{
    llt curr_sum=0;
    llt cnt=0;
    unordered_map<llt,int> M;   //stores all previous sums

    for(int i=0;i<n;i++)
    {
        curr_sum+=(llt)arr[i];

        // If currsum is equal to desired sum, then a new subarray is found. So increase count of subarrays.
        //For eg if k=0 and whole array sum is also zero then this if-condition will be true
        if(curr_sum==k)
            cnt++;

        if(M.find(curr_sum-k)!=M.end())
            cnt+=M[curr_sum-k];

        // Add currsum value to count of different values of sum. If it already exists(like in case of k=0) then simply it will increment value by 1
        // In this map we basically store the sums and count of their occurrences
        M[curr_sum]++;
    }

    return cnt;
}
int main()
{
    int n;
    llt k;       //k=target sum
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<count_subarrays(arr,n,k);
  return 0;
}
/*
An efficient solution is while traversing the array, store sum so far in currsum. Also, maintain the count of different values
of currsum in a map. If the value of currsum is equal to the desired sum at any instance increment count of subarrays by one.
The value of currsum exceeds the desired sum by currsum – sum. If this value is removed from currsum then the desired sum can be
obtained. From the map find the number of subarrays previously found having sum equal to currsum-sum. Excluding all those subarrays
from the current subarray, gives new subarrays having the desired sum. So increase count by the number of such subarrays.
Note that when currsum is equal to the desired sum then also check the number of subarrays previously having a sum equal to 0.
Excluding those subarrays from the current subarray gives new subarrays having the desired sum. Increase count by the number of subarrays having sum 0 in that case.
*/
