#include <iostream>
using namespace std;

int LIS_length(int *,int,int ,int );

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<LIS_length(arr,n,0,-1);     //Take -1 as -INFINITY
  return 0;
}

int LIS_length(int arr[],int n,int curr_indx,int prev_indx)
{
    if(curr_indx==n) //whole array has been traversed
        return 0;

    /// case 1: exclude the current element and process the remaining elements
    int excl= LIS_length(arr,n,curr_indx+1,prev_indx);

    /// case 2: include the current element if it is greater than the previous element in LIS
    int incl=0;
    if(prev_indx==-1 || arr[curr_indx]>=arr[prev_indx]){
       incl=1+LIS_length(arr,n,curr_indx+1,curr_indx);
    }

    /// return the maximum of the above two choices
    return max(incl,excl);
}
/*
My Approach :
func call: LIS_length(arr,n-1,INT_MAX)
int LIS_length(int arr[],int curr_indx,int prev_num)
{
    if(curr_indx==0)
    {
        if(arr[curr_indx]<=prev_num)
            return 1;
        else
            return 0;
    }

    if(arr[curr_indx]<=prev_num)
    {
        return max(1+LIS_length(arr,curr_indx-1,arr[curr_indx]),LIS_length(arr,curr_indx-1,prev_num));
    }

    else
        return LIS_length(arr,curr_indx-1,prev_num);

Note: just replace prev_num with previous indx(-1 in caseof INT_MAX) for memoization
    : and in this idea, we have started traversal from last element instead of first
}
*/

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
