//T.C.= O(n*n)    S.C.=O(n+n) for tablutaion
#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long int llt;

int solve(vector<int> arr)  //Tabulation
{
    int n=arr.size();
    vector<int> dp1(n,1);   //fwd
    vector<int> dp2(n,1);   //backwd
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[i]>arr[j])
                dp1[i]=max(dp1[i],1+dp1[j]);
        }
    }
    for(int i=n-1;i>=0;i--){
        for(int j=n-1;j>i;j--){
            if(arr[i]>arr[j])
                dp2[i]=max(dp2[i],1+dp2[j]);
        }
    }
    int ans=1;
    for(int i=0;i<n;i++){
        ans=max(ans,dp1[i]+dp2[i]-1);
    }
    return ans;
}

int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<solve(arr);
}
/*
8
1 11 2 10 4 5 2 1
Ans: 6

3
1 2 1
Ans: 3
*/
