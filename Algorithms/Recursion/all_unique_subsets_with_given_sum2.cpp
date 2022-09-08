/* Problem
Given an array of distinct integers and a target sum, return a list of all unique combinations(subsets) where the subset sum = target sum. You may return the combinations in any order.
The same number may be chosen from array an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

similar to unbounded knapsack
*/
//! T.C.= exponential         S.C.= O(1)
#include <bits/stdc++.h>
using namespace std;

void findsum(int *,int ,int ,int ,vector<vector<int>>& ,vector<int> );

int main()
{
    int n,sum;
    cin>>n>>sum;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];

    vector<vector<int>> comboSum;
    findsum(arr,n,sum,0,comboSum,{});
    for(vector<int> i:comboSum)
    {
        cout<<"[";
        for(int j:i)
            cout<<j<<", ";
        cout<<"]\n";
    }
    return 0;
}
void findsum(int arr[],int n,int sum,int i,vector<vector<int>>& ans,vector<int> v)
{
    if(i==n || sum<0)
        return ;

    if(sum==0)
    {
        ans.push_back(v);
        return ;
    }

    if(arr[i]<=sum){
        findsum(arr,n,sum,i+1,ans,v);        //we'll choose not take it
        v.push_back(arr[i]);
        findsum(arr,n,sum-arr[i],i,ans,v);   //we'll choose to take it
    }
    else
        findsum(arr,n,sum,i+1,ans,v);        //we can't take it
}
/*
7 15
10 2 5 3 15 5 7 7 6 1 18 4 3 1

Ans: 55.33
*/
