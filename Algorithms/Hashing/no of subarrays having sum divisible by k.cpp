//Approach video: https://www.youtube.com/watch?v=QM0klnvTQzk&t=660s (pepcoding)
//! T.C.= O(n+k)         S.C.= O(k)
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
using llt=long long int;

llt countSubarraysDivByK(int arr[],int n,int k)
{
    llt cnt=0,sum=0;
    int rem;

    //map will store sum%k with its count
    //unordered_map<int,llt> remainders;         //can be done by both map or index hashed array
    vector<llt> remainders(k,0);

    remainders[0]++;        //for empty array

    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
        rem=((sum%k)+k)%k;

        //if(remainders.find(t)!=remainders.end())
        if(remainders[rem]!=0)
            cnt+=remainders[rem];

        remainders[rem]++;
    }
    return cnt;
}
int main()
{
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];
    cout<<countSubarraysDivByK(arr,n,k);
  return 0;
}
/*
6 5
4 5 0 -2 -3 1
Ans: 7
Subarrays are:
{4, 5, 0, -2, -3, 1}
{5}
{5, 0}
{5, 0, -2, -3}
{0}
{0, -2, -3}
{-2, -3}

5 5
3 1 2 7 4
Ans: 1
*/
