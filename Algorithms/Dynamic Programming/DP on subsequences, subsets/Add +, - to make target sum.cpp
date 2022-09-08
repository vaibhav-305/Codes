#include <iostream>
using namespace std;

int solve(int n,int targ,vector<int>& arr){

}
int no_of_ways(int n,int k,vector<int>& arr){
    return solve(n-1,k,arr);
    //basically this ques is count no. of ways such that difference of 2 subset sums if = k
}
int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<no_of_ways(n,k,arr);
  return 0;
}
