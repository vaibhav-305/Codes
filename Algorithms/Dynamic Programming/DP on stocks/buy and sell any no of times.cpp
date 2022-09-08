//T.C.= O(2n)    S.C.=O(2n) for memo and tabl , O(1) for space_opt
#include <iostream>
#include <vector>
using namespace std;

int solve(int ind,bool canBuy,vector<int>& arr,vector<vector<int>>& memo){
    if(ind==arr.size())
        return 0;
    if(memo[ind][canBuy]!=-1)
        return memo[ind][canBuy];

    int profit=0;
    if(canBuy){
        //max(buy or not buy)
        profit = max(-arr[ind]+solve(ind+1,false,arr,memo),solve(ind+1,true,arr,memo));
    }else{
        //max(sell or not sell)
        profit = max(arr[ind]+solve(ind+1,true,arr,memo),solve(ind+1,false,arr,memo));
    }

    return memo[ind][canBuy] = profit;
}
int maxProfit_memo(vector<int>& arr){
    vector<vector<int>> memo(arr.size(),vector<int>(2,-1));
    return solve(0,true,arr,memo);
}

int maxProfit_tabl(vector<int>& arr)
{
    int n=arr.size();
    vector<vector<int>> dp(n+1,vector<int>(2));

    dp[n][0] = dp[n][1] = 0;
    //false -> 0 ; true -> 1

    for(int ind=n-1;ind>=0;ind--){
        for(int canBuy=0;canBuy<=1;canBuy++){
            int profit=0;
            if(canBuy)
                profit = max(-arr[ind]+dp[ind+1][false],dp[ind+1][true]);
            else
                profit = max(arr[ind]+dp[ind+1][true],dp[ind+1][false]);

            dp[ind][canBuy] = profit;
        }
    }
    return dp[0][true];
}

int maxProfit_spaceOpt(vector<int>& arr){
    int n=arr.size();
    vector<int> ahead(2),dp(2);  //dp -> curr

    ahead[0]=ahead[1]=0;

    for(int ind=n-1;ind>=0;ind--){
        for(int canBuy=0;canBuy<=1;canBuy++){
            int profit=0;
            if(canBuy)
                profit = max(-arr[ind]+ahead[false],ahead[true]);
            else
                profit = max(arr[ind]+ahead[true],ahead[false]);

            dp[canBuy] = profit;
        }
        ahead=dp;
    }
    return ahead[true];
}
int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<maxProfit_memo(arr)<<"\n";
    cout<<maxProfit_tabl(arr)<<"\n";
    cout<<maxProfit_spaceOpt(arr);
  return 0;
}
/*
7
1 2 3 4 5 6 7
Ans: 6   (We can make the maximum profit by buying the stock on the first day and selling it on the last day.)

7
7 6 5 4 3 2 1
Ans: 0
*/
