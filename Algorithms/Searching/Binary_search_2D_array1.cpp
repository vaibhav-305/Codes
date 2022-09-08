//Program to find element in a matrix which has sorted row-wise
//and column-wise and first element of a row is not greater than
//last element of previous row.Time Complexity=O(n+m)
#include <iostream>
#include <vector>
using namespace std;

void find_element(vector<vector<int>> arr,int n,int m,int val,int *x_pos,int *y_pos)
{
    int i=0,j=m-1;
    while(i>=0 && i<n && j>=0 && j<m)
    {
        if(arr[i][j]==val)
        {
            *x_pos=i;
            *y_pos=j;
            return ;
        }
        else if(arr[i][j]>val)
            j--;
        else
            i++;
    }
    *x_pos=-1;
    *y_pos=-1;
  return ;
}
int main()
{
    vector<vector<int>> arr={ { 10, 20, 30, 40 },
                              { 15, 25, 35, 45 },
                              { 27, 29, 37, 48 },
                              { 32, 33, 39, 50 },
                              { 41, 47, 51, 55} };
    int val,n,m,x_pos,y_pos;
    cout<<"Enter Value to be searched: ";
    cin>>val;
    n=5;  //No. of rows in matrix
    m=4;  //No. of columns in matrix
    find_element(arr,n,m,val,&x_pos,&y_pos);
    cout<<"Index of searched element=("<<x_pos<<","<<y_pos<<")";
  return 0;
}
