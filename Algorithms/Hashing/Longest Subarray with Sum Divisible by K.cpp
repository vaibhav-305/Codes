//! T.C.= S.C.= O(n)
#include <iostream>
#include <unordered_map>
using namespace std;

int longestSubarrayIndx(int *,int ,int );

int main()
{
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<longestSubarrayIndx(arr,n,k);
  return 0;
}
int longestSubarrayIndx(int arr[],int n,int k)
{
    unordered_map<int, int> M;   //for storing remainders and their first occurrence index

    M.insert(make_pair(0,-1));    //storing 0 sum as rn we have not taken any element

    // 'mod_arr[i]' stores (sum[0..i] % k)
    int mx = 0;
    int startindx=-1,endindx=-1;
    int curr_sum = 0;

    for (int i = 0; i < n; i++) {
        curr_sum += arr[i];

        int rem = ((curr_sum % k) + k) % k;  //we add k to handle -ve sum values


        // if value 'mod_arr[i]' not present in 'M'
        // then store it in 'M' with index of its
        // first occurrence
        if (M.find(rem) == M.end())
            M.insert(make_pair(rem,i));

        else{
            if(mx < (i - M[rem])){  // if true, then update 'max'
                mx = i - M[rem];
                startindx = M[rem];
                endindx = i;
            }
        }
    }

    cout<<"Starting index: "<<startindx<<"\tEnd index: "<<endindx<<"\n";
    return mx;  // required length of longest subarray with sum divisible by 'k'
}
/*
6 3
2 7 6 1 4 5

7 3
-2 2 -5 12 -11 -1 7
Ans: 5

5 21
1 2 3 4 5
*/
