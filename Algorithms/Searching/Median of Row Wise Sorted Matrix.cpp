/* Problem: Given a matrix of integers A of size N x M in which each row is sorted. Find an return the overall median of the matrix A.
Input 1:
    A = [   [1, 3, 5],
            [2, 6, 9],
            [3, 6, 9]   ]
Output 1:
    5
Explanation 1:
    A = [1, 2, 3, 3, 5, 6, 6, 9, 9]
    Median is 5. So, we return 5.
*/
//! T.C.= O( log(1e9) * N * log(M) )              S.C.=O(1)
#include <iostream>
#include <vector>
using namespace std;

int median(vector<vector<int>>);

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> arr(n,vector<int>(m));
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>arr[i][j];

    cout<<median(arr);
  return 0;
}
int countSmallerThanMid(vector<int> &row, int val)        //basically upper_bound
{
    int low=0,high=row.size()-1,mid;

    while(low<=high)
    {
        mid=(low+high)/2;

        if(row[mid]<=val)
            low=mid+1;
        else
            high=mid-1;
    }
    return low;
}
int median(vector<vector<int>> arr)
{
    int n=arr.size();      //rows
    int m=arr[0].size();   //cols

    int low=1, high=1e9, mid;
    int cnt;

    while(low<=high)
    {
        mid=(high+low)/2;
        cnt=0;
        for(int i=0;i<n;i++)         //counts numbers smaller than equal to mid for every rows
            cnt+= countSmallerThanMid(arr[i],mid);

        if(cnt <= (n*m)/2)
            low=mid+1;
        else
            high=mid-1;
    }

    return low;
}
