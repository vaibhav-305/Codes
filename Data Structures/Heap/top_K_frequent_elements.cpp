#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

vector<int> top_K_frequent(int arr[], int n, int k)
{
    unordered_map<int,int> M;
    for(int i=0;i<n;i++)
        M[arr[i]]++;

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minH;  //as we have to find k elements having largest frequencies so we use min Heap
    for(pair<int,int> p:M)
    {
        if(minH.size()<k){
            minH.push(make_pair(p.second,p.first));
            continue;
        }

        if(p.second > minH.top().first){
            minH.pop();
            minH.push(make_pair(p.second,p.first));
        }
    }

    vector<int> ans;
    while(!minH.empty()){
        ans.push_back(minH.top().second);
        minH.pop();
    }
    return ans;
}
int main()
{
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];

    vector<int> ans = top_K_frequent(arr,n,k);
    for(int i:ans)
        cout<<i<<" ";
  return 0;
}
/*
6 2
1 1 1 2 2 3
*/
