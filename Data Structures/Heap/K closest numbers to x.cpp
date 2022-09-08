//Ques: Given an unsorted array and two numbers x and k, find k closest values to x.
//Link: https://leetcode.com/problems/find-k-closest-elements/
//! T.C. = O(n*log(k))      S.C.= O(n)
#include <iostream>
#include <queue>
using namespace std;

vector<int> K_closest_to_x(int arr[],int n,int x,int k)
{
    priority_queue<pair<int,int>> maxH;   // for closest we need to find k smallest distance points , thus we use max Heap.
    int i=0;

    while(i<k){
        maxH.push(make_pair(abs(x-arr[i]),arr[i]));
        i++;
    }

    while(i<n){
        if(abs(x-arr[i]) < maxH.top().first){
            maxH.pop();
            maxH.push(make_pair(abs(x-arr[i]),arr[i]));
        }
        else if(abs(x-arr[i])==maxH.top().first && arr[i]<maxH.top().second){
            maxH.pop();
            maxH.push(make_pair(abs(x-arr[i]),arr[i]));
        }
        i++;
    }

    vector<int> ans;
    while(!maxH.empty()){
        ans.push_back(maxH.top().second);
        maxH.pop();
    }
    //sort(ans.begin(),ans.end());
    return ans;
}
int main()
{
    int n,k,x;
    cin>>n>>k>>x;     // n >= k
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];

    vector<int> ans = K_closest_to_x(arr,n,x,k);
    for(int i:ans)
        cout<<i<<" ";
  return 0;
}
/*
5 4 3
1 2 3 4 5
Ans: 1 2 3 4
*/
