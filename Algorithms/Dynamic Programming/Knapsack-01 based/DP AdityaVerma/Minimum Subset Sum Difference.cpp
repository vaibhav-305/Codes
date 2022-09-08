//Time Complexity = O(n*(sum/2))
#include <iostream>
#include <vector>
using namespace std;

int min_difference_of_2_subsets(int *,int );

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<min_difference_of_2_subsets(arr,n);
  return 0;
}
int min_difference_of_2_subsets(int arr[],int n)
{
    // Calculate sum of all elements
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];

    // Create an array to store results of subproblems
    bool dp[n+1][(sum/2)+1];

    // Initialize first column as true. 0 sum is possible
    // with all elements.
    for (int i = 0; i <= n; i++)
        dp[i][0] = true;

    // Initialize top row, except dp[0][0], as false. With
    // 0 elements, no other sum except 0 is possible
    for (int i = 1; i <= sum/2; i++)
        dp[0][i] = false;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum/2;j++)
        {
            if(arr[i-1]<=j)
                dp[i][j]=dp[i-1][j] || dp[i-1][j-arr[i-1]];
            else
                dp[i][j]=dp[i-1][j];
        }
    }
    int diff;
    for (int j=sum/2; j>=0; j--)
    {
        // Find the
        if (dp[n][j] == true)
        {
            diff = sum-2*j;
            break;
        }
    }
    return diff;
}
