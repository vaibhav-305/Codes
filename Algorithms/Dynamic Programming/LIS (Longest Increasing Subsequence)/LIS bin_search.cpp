//! T.C.= O(n*log(n))   S.C.= O(n)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int LIS(int arr[],int n)
{
    vector<int> temp;
    temp.push_back(arr[0]);
    for(int i=1;i<n;i++){
        if(arr[i]>temp[temp.size()-1])
            temp.push_back(arr[i]);
        else{
            int pos=lower_bound(temp.begin(),temp.end(),arr[i])-temp.begin();
            temp[pos]=arr[i];
        }
    }
    return temp.size();
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<LIS(arr,n);
  return 0;
}
/*
6
5 8 3 7 9 1
Ans: 3 {5,7,9}
*/
