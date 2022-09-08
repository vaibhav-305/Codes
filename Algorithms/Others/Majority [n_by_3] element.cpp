/*Its a variation of Moore's voting algorithm
Given an integer array of size n, find all elements that appear more than [n/3] times.
In case of [n/3] there can be at-max 2 such majority elements and 0 at-min
*/
//! T.C.= O(n)      S.C.= O(1)
#include <iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];

    //---------------------algo-----------------------//
    int el1=-1,cn1=0,el2=-1,cn2=0;
    for(int i=0; i<arr.size(); i++)
    {
        if(el1==arr[i])
            cn1++;
        else if(el2==arr[i])
            cn2++;
        else if(cn1==0)
        {
            el1=arr[i];
            cn1=1;
        }
        else if(cn2==0)
        {
            el2=arr[i];
            cn2=1;
        }
        else
        {
            cn1--;
            cn2--;
        }
    }
    int cnt1=0,cnt2=0;
    vector<int> ans;
    for(int i=0; i<arr.size(); i++)
    {
        if(arr[i]==el1)
            cnt1++;
        else if(arr[i]==el2)
            cnt2++;
    }
    if(cnt1>arr.size()/3)
        ans.push_back(el1);
    if(cnt2>arr.size()/3)
        ans.push_back(el2);
    return 0;
}
