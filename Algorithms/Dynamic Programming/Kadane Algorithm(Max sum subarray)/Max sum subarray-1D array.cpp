//Link to explanation: https://www.youtube.com/watch?v=2MmGzdiKR9Y (Kadane algo - "Back to back SWE" youtube channel)
/** Intitution:  here we make the choice that whether we'll use the previous computed result (stored in "sum" variable) or we'll discard the previous computed result and set sum to current value
                max( start with new item , new item + previous computed result(sum) )
*/
//! T.C.= O(n)              S.C.= O(1)
/* Algorithm
Initialize:
    max_so_far = INT_MIN
    sum = 0

Loop for each element of the array
  (a) sum = sum + a[i]
  (b) if(max_so_far < sum)
            max_so_far = sum
  (c) if(sum < 0)
            sum = 0
return max_so_far
*/
#include <iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];

    //-------------Algorithm---------------//
    long long int max_so_far = arr[0], sum=0;
    int max_ending_indx=0 ,max_starting_indx=0,s=0;

    for(int i=0;i<n;i++)
    {
        sum+=(long long int)arr[i];

        if(max_so_far < sum){
            max_so_far=sum;
            max_starting_indx=s;
            max_ending_indx=i;
        }

        if(sum<0){
            sum=0;
            s=i+1;
        }
    }
    cout<<"Max sum: "<<max_so_far<<endl;
    //printing sub-array of max sum
    for(int i=max_starting_indx;i<=max_ending_indx;i++)
        cout<<arr[i]<<" ";
    cout<<"\nIndex Range: ["<<max_starting_indx<<", "<<max_ending_indx<<"]\n";
  return 0;
}
