//Program to find element in a matrix which has sorted row-wise
//and column-wise and first element of a row is greater than
//last element of previous row.Time complexity=O(log(n*m))
#include <iostream>
#include <vector>
using namespace std;

void find_element(int n,int m,int arr[][4],int val,int *x_pos,int *y_pos)
{
    int start=0;
    int endi=m*n-1;
    while(start<=endi)
    {
        int mid=start+(endi-start)/2;
        int i=mid/m;
        int j=mid%m;
        if(arr[i][j]==val)
        {
            *x_pos=i;
            *y_pos=j;
            return ;
        }
        else if(arr[i][j]>val)
            endi=mid-1;
        else
            start=mid+1;
    }
    *x_pos=-1;
    *y_pos=-1;
    return ;
}

int main()
{
    int arr[5][4]={ { 10, 20, 30, 40 },
                    { 43, 55, 56, 59 },
                    { 67, 69, 77, 78 },
                    { 82, 83, 89, 90 },
                    { 91, 97, 101, 105} };
    int val,n,m,x_pos,y_pos;
    cout<<"Enter Value to be searched: ";
    cin>>val;
    n=5;  //No. of rows in matrix
    m=4;  //No. of columns in matrix
    find_element(n,m,arr,val,&x_pos,&y_pos);
    cout<<"Index of searched element=("<<x_pos<<","<<y_pos<<")";
  return 0;
}
