//Given an integer array nums, return all the triplets [arr[i], arr[j], arr[k]] such that i != j, i != k, and j != k, and arr[i] + arr[j] + arr[k] = given sum
//! T.C.= O(n*n)+O(long(m))    O.C.= O(n)+O(m)    where m is no. of triplets stored in set
//! Optimal approcah: see 2-pointer approach
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> solve(vector<int> arr, int target)
{
    set<vector<int>> S;
    vector<vector<int>> ans;
    vector<int> triplet(3);
    int temp1,temp2;
    int n=arr.size();
    if(n<3)
        return ans;

    unordered_map<int,int> M;
    for(int i:arr)
        M[i]++;
    /*for(pair<int,int> p: M)
        cout<<p.first<<" -> "<<p.second<<endl;*/
    for(pair<int,int> p:M)
    {
        temp1=target-p.first;
        M[p.first]--;
        for(pair<int, int> q: M)
        {
            if(M[q.first]>0)
            {
                temp2=temp1-q.first;
                M[q.first]--;
                if(M.find(temp2)!=M.end())
                {
                    if(M[temp2]>0){
                    //cout<<temp2<<" "<<M[temp2]<<"\n";
                    triplet[0]= p.first;
                    triplet[1]= q.first;
                    triplet[2]= temp2;
                    sort(triplet.begin(),triplet.end());
                    S.insert(triplet);
                    }
                }
                M[q.first]++;
            }
        }
        M[p.first]++;
    }
    for(vector<int> i:S)
        ans.push_back(i);
    return ans;
}
int main()
{
    int n,target;
    cin>>n>>target;
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        cin>>arr[i];

    vector<vector<int>> ans=solve(arr,target);
    cout<<"-------------------------------------\n";
    for(vector<int> v:ans)
    {
        for(int i:v)
            cout<<i<<" ";
        cout<<"\n";
    }

    return 0;
}
/*
11 0
-1 0 1 2 -1 -4 -2 -3 3 0 4
*/
