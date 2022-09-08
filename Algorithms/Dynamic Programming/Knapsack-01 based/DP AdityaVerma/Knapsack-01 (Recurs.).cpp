//T.C.=O(2^n)
#include <iostream>
using namespace std;

int knapsack(int *,int *,int ,int );

int main()
{
    int n,W;
    cin>>n>>W;
    int val[n],wt[n];
    for(int i=0;i<n;i++)
        cin>>wt[i];
    for(int i=0;i<n;i++)
        cin>>val[i];
    int maxprofit=knapsack(wt,val,n,W);
    cout<<maxprofit;
  return 0;
}
int knapsack(int wt[],int val[],int n,int W)
{
    if(n==0 || W==0)
        return 0;

    if(wt[n-1]<=W)
        return max((val[n-1]+knapsack(wt,val,n-1,W-wt[n-1])),knapsack(wt,val,n-1,W));
    else
        return knapsack(wt,val,n-1,W);
}
