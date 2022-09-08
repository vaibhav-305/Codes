//! T.C.= O(r+c)        S.C.= O(1)
#include <iostream>
#include <vector>
using namespace std;

void clockwiseBoundaryTraversal(vector<vector<int>> arr,int r,int c)        //if no. of rows and columns are provided
{
    // Print the first row
    for (int j = 0; j < c; j++)
        cout << arr[0][j] << " ";

    // Print the last column except the first row
    for (int i = 1; i < r; i++)
        cout << arr[i][c - 1] << " ";

    // Print the last row except the last column
    if (r > 1)
    {
        // Print the last row
        for (int j = c - 2; j >= 0; j--)
            cout << arr[r - 1][j] << " ";
    }

    // Print the first column except the first and last row
    if (c > 1)
    {
        // Print the first column
        for (int i = r - 2; i > 0; i--)
            cout << arr[i][0] << " ";
    }
}
void clockwiseBoundaryTraversal(vector<vector<int>> arr,int r1,int c1,int r2,int c2)     //when co-ordinates are given
{
    // checking leftIndx < rightIndx and topIndx < bottomIndx
    if(c1>c2 || r1>r2){                        //    (r1,c1) - - - - - (r1,c2)
        cout<<"invalid parameters";            //       |                 |
        return ;                               //       |                 |
    }                                          //    (r2,c1) - - - - - (r2,c2)

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
int main()
{
    int r,c;
    cin>>r>>c;
    vector<vector<int>> arr(r,vector<int>(c));
    for(int i=0; i<r; i++)
        for(int j=0; j<c; j++)
            cin>>arr[i][j];
    clockwiseBoundaryTraversal(arr,r,c);
    cout<<"\n";
    clockwiseBoundaryTraversal(arr,0,0,r-1,c-1);
    return 0;
}
/*
2 4
1 2 3 4
5 6 7 8
*/
