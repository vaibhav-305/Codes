#include <iostream>
#include <vector>
using namespace std;

int no_of_subset(int *,int,int);

int main()
{
    int n,sum;
    cin>>n>>sum;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<no_of_subset(arr,n,sum);
  return 0;
}

int no_of_subset(int arr[],int n, int sum)
{
    int dp[n+1][sum+1];

    /* fill the first cols with 1 as for sum  = 0 it will be true for all the rows */
    for (int i = 0 ; i <=n ; i++)  //!i=0
		dp[i][0] = 1;

    /* for the first row all the value will be 0 as size of input array is 0 */
	for (int j = 1 ; j <=sum ; j++)  //! j=1
		dp[0][j] = 0;

    for(int i = 1; i <= n; i++)
    {
		for (int j = 1; j <= sum; j++)
		 {
			if (j >= arr[i - 1])
				dp[i][j] = dp[i - 1][j] + dp[i - 1][j - arr[i - 1]];
            else
				dp[i][j] = dp[i - 1][j];
		}
	}
	return dp[n][sum];
}
/* dataset
6 19
1 32 4 5 7 2
*/
