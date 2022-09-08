#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int LIS(int *,int);


int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];

    cout<<LIS(arr,n);
  return 0;
}

int LIS(int arr[],int n)
{
    // array to store subproblem solution. dp[i] stores the length
    // of the longest increasing subsequence that ends with arr[i]
    int dp[n];

    // the longest increasing subsequence ending with arr[i] has atleast length 1
    fill(dp,dp+n,1);

    int Anc[n];
    fill(Anc,Anc+n,-1);  //for printing LIS

    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            /*if(arr[i]>=arr[j]){
                dp[i]=max(dp[i],dp[j]+1);
            }*/
            if(arr[i]>=arr[j] && dp[i]<=dp[j]+1)
            {
                dp[i]=dp[j]+1;
                Anc[i]=j;
            }
        }
    }

    ///Printing the subsequence
    /*
    To be able to restore the subsequence we generate an additional auxiliary
    array Anc[0…n−1] that we will compute alongside the array dp[]. Anc[i] will be
    the index j of the second last element in the longest increasing subsequence
    ending in i. In other words the index Anc[i] is the same index j at which the
    highest value dp[i] was obtained. This auxiliary array Anc[] points in some
    sense to the ancestors.

    Then to derive the subsequence, we just start at the index i with the
    maximal dp[i], and follow the ancestors until we deduced the entire subsequence,
    i.e. until we reach the element with dp[i]=1.

    For convenience we originally assign the ancestors with Anc[i]=−1. For elements with
    dp[i]=1, the ancestors value will remain −1, which will be slightly more convenient
    for restoring the subsequence.
    */
    int max_indx=max_element(dp,dp+n)-dp;

    int pos=max_indx;
    vector<int> lis;
    while(pos!=-1)
    {
        lis.push_back(arr[pos]);
        pos=Anc[pos];
    }
    reverse(lis.begin(),lis.end());
    for(int i:lis)
        cout<<i<<" ";
    cout<<"\n";

    return dp[max_indx];   ///lenght of the LIS
}
/*
9
10 22 9 33 21 50 41 60 80
Output: 6 {10,22,33,50,60,80}

6
50 3 10 7 40 80
Output: 4 {3,7,40,80}

8
-1 3 4 5 2 2 2 2
output:  5 {-1,2,2,2,2}
*/
