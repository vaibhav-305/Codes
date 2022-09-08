//Given an integer array arr, return all the quads [arr[i], arr[j], arr[k], arr[l]] such that i!=j!=k!=l,and arr[i] + arr[j] + arr[k]+arr[l] = given sum
//! T.C.= O(n*n*n)+O(log(m))            S.C.= O(n)+O(m)       where m is no. of triplets stored in set
//! Optimal approach: see 2-pointer approcach
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> solve(vector<int> arr, int target)
{
    set<vector<int>> S;
    vector<vector<int>> ans;
    vector<int> quad(4);
    int temp1,temp2,num;
    int n=arr.size();
    if(n<4)
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
                for(pair<int, int> r: M)
                {
                    if(M[r.first]>0)
                    {
                        num=temp2-r.first;
                        M[r.first]--;
                        if(M.find(num)!=M.end())
                        {
                            if(M[num]>0){
                            //cout<<temp2<<" "<<M[temp2]<<"\n";
                            quad[0]= p.first;
                            quad[1]= q.first;
                            quad[2]= r.first;
                            quad[3]= num;
                            sort(quad.begin(),quad.end());
                            S.insert(quad);
                            }
                        }
                        M[r.first]++;
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
