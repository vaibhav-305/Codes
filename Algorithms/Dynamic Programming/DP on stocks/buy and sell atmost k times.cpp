//T.C.=O(n*2*k)     S.C.=O(n*2*k) for memo/tabl    O(2*k) for space_opt
#include <iostream>
#include <vector>
using namespace std;

int solve(int ind,bool canBuy,int limit, vector<int>& arr,vector<vector<vector<int>>>& memo){
    if(ind==arr.size() || limit==0)
        return 0;
    if(memo[ind][canBuy][limit]!=-1)
        return memo[ind][canBuy][limit];

    int profit=0;
    if(canBuy){
        //max(buy or not buy)
        profit = max(-arr[ind]+solve(ind+1,false,limit,arr,memo),solve(ind+1,true,limit,arr,memo));
    }else{
        //max(sell or not sell)
        profit = max(arr[ind]+solve(ind+1,true,limit-1,arr,memo),solve(ind+1,false,limit,arr,memo));
    }

    return memo[ind][canBuy][limit] = profit;
}
int maxProfit_memo(vector<int>& arr,int k){
    vector<vector<vector<int>>> memo(arr.size(),vector<vector<int>>(2,vector<int>(k+1,-1)));
    return solve(0,true,k,arr,memo);
}

int maxProfit_tabl(vector<int>& arr,int k){
    int n=arr.size();
    vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(k+1,0)));   //already initialized to zero

    //false -> 0 ; true -> 1

    for(int ind=n-1;ind>=0;ind--){
        for(int canBuy=0;canBuy<=1;canBuy++){
            for(int limit=1;limit<=k;limit++){
                int profit=0;
                if(canBuy)
                    profit = max(-arr[ind]+dp[ind+1][false][limit],dp[ind+1][true][limit]);
                else
                    profit = max(arr[ind]+dp[ind+1][true][limit-1],dp[ind+1][false][limit]);

                dp[ind][canBuy][limit] = profit;
            }
        }
    }
    return dp[0][true][k];
}

int maxProfit_spaceOpt(vector<int>& arr,int k){
    int n=arr.size();
    vector<vector<int>> ahead(2,vector<int>(k+1,0));   //already initialized to zero
    vector<vector<int>> dp(2,vector<int>(k+1));  //dp -> curr

    for(int ind=n-1;ind>=0;ind--){
        for(int canBuy=0;canBuy<=1;canBuy++){
            for(int limit=1;limit<=k;limit++){
                int profit=0;
                if(canBuy)
                    profit = max(-arr[ind]+ahead[false][limit],ahead[true][limit]);
                else
                    profit = max(arr[ind]+ahead[true][limit-1],ahead[false][limit]);

                dp[canBuy][limit] = profit;
            }
        }
        ahead=dp;
    }
    return ahead[true][k];
}
int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<maxProfit_memo(arr,k)<<"\n";
    cout<<maxProfit_tabl(arr,k)<<"\n";
    cout<<maxProfit_spaceOpt(arr,k);
  return 0;
}
/*
6 2
10 22 5 75 65 80
Ans: 87  (Buy at 10, sell at 22, Buy at 5 and sell at 80)
*/
