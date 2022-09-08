//! T.C.= O(n*log(n))       S.C.= O(n)
#include <bits/stdc++.h>
using namespace std;
struct Item
{
    int value;
    int weight;
};

double fractionalKnapsack(int W, Item arr[], int n)
{
    // Your code here
    double profit=0;
    pair<double,int> items[n];       //stores value/kg and respective index with arr[]
    for(int i=0; i<n; i++)
    {
        items[i].first=(double)(arr[i].value*1.0/arr[i].weight*1.0);
        items[i].second=i;
    }
    sort(items,items+n,[&](pair<double,int> &a, pair<double,int> &b)
    {
        return a.first>b.first;
    });
    //for(int i=0;i<n;i++)
    //  cout<<items[i].first<<" "<<items[i].second<<endl;
    for(int i=0; i<n && W!=0; i++)
    {
        if(W>=arr[items[i].second].weight)
        {
            W=W-arr[items[i].second].weight;
            profit+=(double)arr[items[i].second].value;
        }
        else
        {
            profit+=(double)(items[i].first * W);
            W=0;
            break;
        }
    }
    return profit;
}

int main()
{
    cout<<setprecision(2)<<fixed;

    int n, W;
    cin>>n>>W;
    Item arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i].value>>arr[i].weight;

    cout<<fractionalKnapsack(W, arr, n)<<endl;
    return 0;
}
/*
7 15
10 2 5 3 15 5 7 7 6 1 18 4 3 1

Ans: 55.33
*/
