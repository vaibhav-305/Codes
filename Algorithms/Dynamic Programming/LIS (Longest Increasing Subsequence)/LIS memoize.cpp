#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int fun(vector<int>& arr,int prev,int i,vector<vector<int>>& memo){
    if(i>=arr.size())
        return 0;
    if(memo[i][prev+1]!=-1)
        return memo[i][prev+1];

    int ntk=fun(arr,prev,i+1,memo);
    int tk=0;
    if(prev==-1 || arr[prev]<arr[i])
        tk=1+fun(arr,i,i+1,memo);
    return memo[i][prev+1]=max(tk,ntk);
}
int solve(vector<int>& arr){
    int n=arr.size();
    vector<vector<int>> memo(n,vector<int>(n+1,-1));
    return fun(arr,-1,0,memo);
}
int main()
{
    //IOS
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<solve(arr);
    return 0;
}
/*
6
5 4 11 1 16 8
Ans: 2

3
1 2 2
Ans: 2
*/
