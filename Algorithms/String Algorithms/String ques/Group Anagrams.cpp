#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <utility>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& arr);

int main()
{
    int n;
    cin>>n;
    vector<string> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];

    vector<vector<string>> ans=groupAnagrams(arr);
    for(vector<string> v:ans)
    {
        for(string s: v)
            cout<<s<<" ";
        cout<<"\n";
    }
  return 0;
}
vector<vector<string>> groupAnagrams(vector<string>& arr)
{
    if(arr.size()<0)
        return {{}};

    unordered_map<string,vector<int>> M;     //vector<int> is taken for storing the indexes of arr
    string temp;
    for(int i=0;i<arr.size();i++)
    {
        temp=arr[i];
        sort(temp.begin(),temp.end());

        M[temp].push_back(i);
    }

    vector<vector<string>> res(M.size());
    int x=0;
    for(pair<string,vector<int>> p:M)
    {
        for(int i: p.second)
            res[x].push_back(arr[i]);
        x++;
    }
    return res;
}
/*
eat tea tan ate nat bat
Output: bat
        nat tan
        ate eat tea
*/
