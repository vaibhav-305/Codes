//! T.C.= O(9^(n*n)) for every unfilled we have 9 possibilities(1,2....9)       S.C.= O(n*n)  where n=9 size of sudoko
#include <iostream>
using namespace std;

bool isValid(int temp[][9],int x,int y,int num)
{
    //row check
    for(int j=0; j<9; j++)
    {
        if(temp[x][j]==num)
            return false;
    }

    //column check
    for(int i=0; i<9; i++)
    {
        if(temp[i][y]==num)
            return false;
    }

    //box check
    int tempx=3*(x/3);
    int tempy=3*(y/3);
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            if(temp[tempx+i][tempy+j]==num)
                return false;
        }
    }
    return true;
}
void solve(int temp[][9],int arr[][9],int x,int y,bool &solved)
{
    if(solved)
        return;
    if(x==9)
    {
        solved=true;
        for(int i=0; i<9; i++) //copying temp in arr as it is answer
            for(int j=0; j<9; j++)
                arr[i][j]=temp[i][j];
        return;
    }
    if(temp[x][y]!=0)   //already filled
        solve(temp,arr,x+((y+1)/9),(y+1)%9,solved);
    else
    {
        for(int i=1; i<=9; i++){
            if(isValid(temp,x,y,i)){
                temp[x][y]=i;
                solve(temp,arr,x+((y+1)/9),(y+1)%9,solved);  //next cell
                temp[x][y]=0;   //reseting cell
            }
        }
    }
}
bool sudoko(int arr[][9])
{
    int temp[9][9];
    for(int i=0; i<9; i++) //copying arr in temp
        for(int j=0; j<9; j++)
            temp[i][j]=arr[i][j];
    bool solved =false;
    solve(temp,arr,0,0,solved);
    return solved;
}
int main()
{
    int arr[9][9];
    for(int i=0; i<9; i++)
        for(int j=0; j<9; j++)
            cin>>arr[i][j];
    cout<<"\n";
    if(sudoko(arr))
    {
        for(int i=0; i<9; i++)
        {
            for(int j=0; j<9; j++)
                cout<<arr[i][j]<<" ";
            cout<<"\n";
        }
    }
    else
        cout<<"No solution possible of given sudoko";
    return 0;
}
/*
3 0 6  5 0 8  4 0 0
5 2 0  0 0 0  0 0 0
0 8 7  0 0 0  0 3 1

0 0 3  0 1 0  0 8 0
9 0 0  8 6 3  0 0 5
0 5 0  0 9 0  6 0 0

1 3 0  0 0 0  2 5 0
0 0 0  0 0 0  0 7 4
0 0 5  2 0 6  3 0 0

Ans:
3 1 6  5 7 8  4 9 2
5 2 9  1 3 4  7 6 8
4 8 7  6 2 9  5 3 1

2 6 3  4 1 5  9 8 7
9 7 4  8 6 3  1 2 5
8 5 1  7 9 2  6 4 3

1 3 8  9 4 7  2 5 6
6 9 2  3 5 1  8 7 4
7 4 5  2 8 6  3 1 9

*/
