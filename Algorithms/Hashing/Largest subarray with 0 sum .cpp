#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> arr,int n)
{
    int mx=0;
    int sum=0;
    unordered_map<int,int> M;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
        if(sum==0)
            mx=max(mx,i+1);
        if(M.find(sum)!=M.end())
        {
            mx=max(mx,i-M[sum]);
        }
        else
            M.insert(make_pair(sum,i));
    }
    if(sum==0)
        return n;
    else
        return mx;
}
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++)
        cin>>arr[i];

    cout<<solve(arr,n);

  return 0;
}
/*8
15 -2 2 -8 1 7 10 23*/
