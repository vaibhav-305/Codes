//! T.C.= O(r*c) 1 traversal         S.C.= O(1)
#include <iostream>
#include <vector>
using namespace std;

void clockwiseBoundaryTraversal(vector<vector<int>>& arr,int r1,int c1,int r2,int c2)     //when co-ordinates are given
{
    // Print the last column except the first row
    for(int j=c1;j<=c2;j++)
        cout<<arr[r1][j]<<" ";

    // Print the last column except the first row
    for(int i=r1+1;i<=r2;i++)
        cout<<arr[i][c2]<<" ";

    // Print the last row except the last column
    if(r2-r1+1 > 1)    //checking no. of rows
    {
        for (int j = c2 - 1; j >= c1; j--)
            cout << arr[r2][j] << " ";
    }

    // Print the first column except the first and last row
    if (c2-c1+1 > 1)         //checking no. of cols
    {
        // Print the first column
        for (int i = r2 - 1; i > r1; i--)
            cout << arr[i][c1] << " ";
    }
}
void spiralTraversal(vector<vector<int>> arr,int r,int c)
{
    int r1=0,c1=0,r2=r-1,c2=c-1;

    while(r1<=r2 && c1<=c2)
    {
        clockwiseBoundaryTraversal(arr,r1,c1,r2,c2);
        r1++,c1++;  //shrinking matrix by 1 as border is already traversed
        r2--,c2--;
    }
}
int main()
{
    int r,c;
    cin>>r>>c;
    vector<vector<int>> arr(r,vector<int>(c));
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            cin>>arr[i][j];
    spiralTraversal(arr,r,c);
  return 0;
}
/*
5 4
1  2  3  4
5  6  7  8
9  10 11 12
13 14 15 16
17 18 19 20

3 2
1 2
3 4
5 6

3 3
1 2 3
4 5 6
7 8 9
*/
