//! T.C.= O(n*(m+m))        S.C.= O(m)+O(m)         n->rows  m->cols
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int maximalRectangle(vector<vector<char>>& );

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<char>> arr(n,vector<char>(m));
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>arr[i][j];

    cout<<maximalRectangle(arr);
  return 0;
}
int maxAreaHist(vector<int> &arr)
{
    int n=arr.size();
    stack<int> S;           //for storing indexes of nearest smaller to left
    int mx=0,h,w;
    for(int i=0;i<n;i++)
    {
        if(S.empty() || arr[S.top()]<=arr[i])
            S.push(i);
        else{                //this will break when stack.top() element will be greater than than arr[i] which is actually the nearest smaller to right.
            while( !S.empty() && arr[S.top()]>arr[i]){
                h=arr[S.top()];
                S.pop();

                if(S.empty())
                    w=i;
                else
                    w=i-S.top()-1;

                mx=max(mx,h*w);
            }
            S.push(i);
        }
    }
    while(!S.empty()){
        h=arr[S.top()];
        S.pop();

        if(S.empty())
            w=n;
        else
            w=n-S.top()-1;

        mx=max(mx,h*w);
    }
    return mx;
}
int maximalRectangle(vector<vector<char>>& matrix)
{
    int n=matrix.size();       //rows
    int m=matrix[0].size();    //cols

    vector<int> heights(m,0);
    int mx=0;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++){
            if(matrix[i][j]=='0')
                heights[j]=0;
            else
                heights[j]+=1;
        }
        mx=max(mx,maxAreaHist(heights));
    }
    return mx;
}
/*
4 5
1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0
Ans: 6
*/
