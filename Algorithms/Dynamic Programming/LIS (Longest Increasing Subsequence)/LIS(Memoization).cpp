#include <iostream>
#include <vector>
using namespace std;

int LIS_length(int *,int,int ,int,vector<vector<int>> );


int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];

    vector<vector<int>> memo(n,vector<int>(n,-1));
    cout<<LIS_length(arr,n,0,-1,memo);     //Take -1 as -INFINITY
  return 0;
}

int LIS_length(int arr[],int n,int curr_indx,int prev_indx,vector<vector<int>> memo)
{
    if(curr_indx==n){ //whole array has been traversed
        return 0;
    }

    if(prev_indx!=-1 && memo[prev_indx][curr_indx]!=-1)
        return memo[prev_indx][curr_indx];

    /// case 1: exclude the current element and process the remaining elements
    int excl= LIS_length(arr,n,curr_indx+1,prev_indx,memo);


    /// case 2: include the current element if it is greater than the previous element in LIS
    int incl=0;
    if(prev_indx==-1 || arr[curr_indx]>=arr[prev_indx]){
       incl=1+LIS_length(arr,n,curr_indx+1,curr_indx,memo);
    }

    /// return the maximum of the above two choices
    if(prev_indx!=-1)
        memo[prev_indx][curr_indx]= max(incl,excl);

    return max(incl,excl);
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
