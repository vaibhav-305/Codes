// Problem link: https://leetcode.com/problems/longest-consecutive-sequence/
//! T.C.= O(N) (O(3N))         S.C.= O(n)
#include <iostream>
#include <unordered_set>
using namespace std;

int Longest_consecutive_sequence(int arr[],int n)
{
    if(n<2)
        return n;

    unordered_set<int> S;
    int cnt=1,temp,mx=1;

    for(int i=0;i<n;i++)
        S.insert(arr[i]);

    for(int i=0;i<n;i++)
    {
        if(S.find(arr[i]-1)==S.end())     //which means this will be the smallest element in its consecutive sequence
        {
            temp=arr[i];
            cnt=1;
            while(S.find(temp+1)!=S.end()){       //finding the next (greater)term of consecutive sequence
                cnt++;
                temp+=1;
            }
            mx=max(mx,cnt);
        }
    }
    return mx;
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];

    cout<<Longest_consecutive_sequence(arr,n);
  return 0;
}
