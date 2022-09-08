#include <iostream>
#include <vector>
using namespace std;

void solve(int n,int k,int indx,vector<int> temp,vector<vector<int>>& ans){
	if(k==0){
		ans.push_back(temp);
		return;
	}
    if(indx>n){
        return;
    }
    temp.push_back(indx);
    solve(n,k-1,indx+1,temp,ans);
    temp.pop_back();
    solve(n,k,indx+1,temp,ans);

}
vector<vector<int>> combinations(int n, int k)
{
    // Write your code here.
	vector<vector<int>> ans;
	solve(n,k,1,{},ans);
	return ans;
}
int main()
{
    int n,k;
    cin>>n>>k;
    vector<vector<int>> ans=combinations(n,k);
    for(vector<int> i:ans){
        for(int j:i)
            cout<<j<<" ";
        cout<<"\n";
    }
  return 0;
}
