#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int max_sum_IS(int *,int );

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];

    cout<<max_sum_IS(arr,n);
  return 0;
}

int max_sum_IS(int arr[],int n)
{
    // array to store subproblem solution. dp_msis[i] stores the max sum
    // of the increasing subsequence that ends with arr[i]
    int dp_msis[n];

    //Initialize dp_msis values for all indexes
    for(int i=0;i<n;i++)
        dp_msis[i]=arr[i];

    int Anc[n];
    fill(Anc,Anc+n,-1);

    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(arr[i]>=arr[j] && dp_msis[i]<=dp_msis[j]+arr[i]){
                dp_msis[i]=dp_msis[j]+arr[i];
                Anc[i]=j;
            }
        }
    }

    ///Printing the max_sum_increasing_subsequence
    //Same logic as for printing LIS
    int max_indx=max_element(dp_msis,dp_msis+n)-dp_msis;
    int pos=max_indx;

    vector<int> seq;
    while(pos!=-1)
    {
        seq.push_back(arr[pos]);
        pos=Anc[pos];
    }
    reverse(seq.begin(),seq.end());
    for(int i:seq)
        cout<<i<<" ";
    cout<<"\n";

    return dp_msis[max_indx];
}
/*
7
1 101 2 3 100 4 5
o/p :106 {1,2,3,100}

14
0 8 4 12 2 10 6 14 1 9 5 13 3 11
o/p :34  {8,12,14}
*/
