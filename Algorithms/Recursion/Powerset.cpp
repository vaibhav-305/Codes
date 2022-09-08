//For a given array, find its Powerset(aka all its unique subsets)
/// In a subset order doesn't matter(unlike subsequence) and it need not to be continous(unlike subarray).
//! T.C.= exponential        S.C.= O(n)  {at max if all the elements of array are unique}
#include <bits/stdc++.h>
using namespace std;

void getPowerset(vector<pair<int,int>>,int , vector<vector<int>>& ,vector<int> );

int main()
{
    int n;
    cin>>n;
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
    //for(int i=0;i<M.size();i++)
      //  cout<<M[i].first<<" "<<M[i].second<<endl;

    vector<vector<int>> PowerSet;
    getPowerset(M,0,PowerSet,{});

    for(vector<int> i:PowerSet){
        cout<<"[";
        for(int j: i)
            cout<<j<<", ";
        cout<<"]";
        cout<<"\n";
    }

    return 0;
}
void getPowerset(vector<pair<int,int>> M,int i,vector<vector<int>>& ans,vector<int> v)
{
    if(i==M.size())
    {
        cout<<"& ";
        ans.push_back(v);
        for(int w:v)
            cout<<w<<" - ";
        cout<<"\n";
        return;
    }

    getPowerset(M,i+1,ans,v);

    for(int x=1;x<=M[i].second;x++){
        v.push_back(M[i].first);
        getPowerset(M,i+1,ans,v);
    }
}
