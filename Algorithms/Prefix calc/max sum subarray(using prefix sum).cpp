/* Approach:
Consider the prefix sum array p. The subarray sum Ai,A(i+1)...A(j-1), where i<=j is p[j]-p[i]. Thus, we are looking for the maximum possible value of p[j]-p[i] over 0 <= i <= j <= N.
For a fixed right bound j, the maximum subarray sum is
        p[j]-min(p[i]) (i<=j)
Thus, we can keep a running minimum to store min(p[i]){i<=j} as we iterate through j. This yields the maximum subarray sum for each possible right bound, and the maximum over all these values is our answer.
*/
/// we would use this method when we wanna control the size of maximum size subarray (eg: CSES: Maximum Subarray Sum II problem)
//! T.C.= S.C. = O(n)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main()
{
	int n;
	cin >> n;
	vector<long long> pfx(n + 1,0);  // prefix sum array initially filled with 0's
	for (int i = 1; i <= n; i++)
    {
		ll x;
		cin >> x;
		pfx[i] = pfx[i - 1] + x;  // compute the prefix sum at each element
	}

	ll max_subarray_sum = pfx[1];
	ll min_prefix_sum = pfx[0];
	int startindx=0,endindx=0,temps=0;
	for (int i = 1; i <= n; i++) //as loop starts from 1 , so we'll do -1 to get index
    {
		// Max subarray sum is the maximum difference between two prefix sums
		//max_subarray_sum = max(max_subarray_sum, pfx[i] - min_prefix_sum);
		if(max_subarray_sum < pfx[i] - min_prefix_sum){
            max_subarray_sum = pfx[i] - min_prefix_sum;
            startindx=temps;
            endindx=i-1;
		}

		/* //if we want longest max subarray sum:
		else if(max_subarray_sum == pfx[i]-min_prefix_sum){
            //cout<<i-1<<" & "<<temps<<"\t"<<startindx<<" # "<<endindx<<" ";
            if((endindx-startindx)<(i-1-temps)){
                startindx=temps;
                endindx=i-1;
            }
        */

		//min_prefix_sum = min(min_prefix_sum, pfx[i]);
		if(min_prefix_sum>pfx[i]){
            min_prefix_sum=pfx[i];
            temps=i+1-1;      //here +1 beacuse the subrarry will start from i+1 as we are substracting psum[k]-psum[i] that means max subarray start from i+1, and -1 beacuse we have started loop from 1
		}
	}
	cout<<"Starting index: "<<startindx<<"\tEnd index: "<<endindx<<"\n";
	cout << max_subarray_sum << endl;
}
/*
8
-2 -3 4 -1 -2 1 5 -3
Ans: 7      [2,6]indx

9
-2 1 -3 4 -1 2 1 -5 4
Ans: 6      [3,6]indx

4
-1 -2 -3 -4
Ans: -1   [0,0]

5
1 1 -1 1 1
Ans: 3   [0,4]
*/
