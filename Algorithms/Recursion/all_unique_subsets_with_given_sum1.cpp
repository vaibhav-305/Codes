/*Problem:
Given a, array of numbers and a target sum, find all unique subsets in array where the subset sum = target sum.
Each number in candidates may only be used once in the combination.
Note: The solution set must not contain duplicate combinations.
*/
//! T.C.= exponential       S.C.= O(n) {at max if all elements in array are unique}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void getcomboSum(vector<pair<int,int>> ,int ,int ,vector<vector<int>>& ,vector<int> );

int main()
{
    int n,sum;
    cin>>n>>sum;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];

    sort(arr,arr+n);
    vector<pair<int,int>> M;
    int top=0;
    M.push_back(make_pair(arr[0],1));
    for(int i=1;i<n;i++)
    {
        if(M[top].first==arr[i])
            M[top].second++;
        else{
            M.push_back({arr[i],1});
            top++;
        }
    }
    for(int i=0;i<M.size();i++)
        cout<<M[i].first<<" "<<M[i].second<<endl;

    vector<vector<int>> comboSum;
    getcomboSum(M,0,sum,comboSum,{});
    for(vector<int> i:comboSum)
    {
        cout<<"[";
        for(int j:i)
            cout<<j<<", ";
        cout<<"]\n";
    }
    return 0;
}
void getcomboSum(vector<pair<int,int>> M,int i,int sum,vector<vector<int>>& ans,vector<int> v)
{
    if(sum==0)           //yeh pehle aaega because it might happen that sum=0 and i=M.size(), in this we will consider  it as one answer.
    {
        ans.push_back(v);
        return ;
    }

    if(i==M.size() && sum<0)   //writing sum<0 here is optional cause we have checked this in for loop
        return ;

    getcomboSum(M,i+1,sum,ans,v);

    for(int x=1;x<=M[i].second;x++){
        if(sum<M[i].first)
            break;

        v.push_back(M[i].first);
        sum-=M[i].first;
        getcomboSum(M,i+1,sum,ans,v);
    }
}
