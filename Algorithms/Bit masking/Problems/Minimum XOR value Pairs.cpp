#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];

    sort(arr,arr+n);

    vector<pair<int,int>> min_pair;

    int mn=INT_MAX,Xor;
    for(int i=0;i<n-1;i++)
    {
        Xor=arr[i]^arr[i+1];
        if(mn>Xor)
        {
            mn=Xor;
            min_pair.clear();
            min_pair.push_back(make_pair(i,i+1));
        }
        else if(mn==Xor)
            min_pair.push_back(make_pair(i,i+1));
    }

    for(int i=0;i<min_pair.size();i++)
        cout<<min_pair[i].first<<", "<<min_pair[i].second<<endl;

  return 0;
}
