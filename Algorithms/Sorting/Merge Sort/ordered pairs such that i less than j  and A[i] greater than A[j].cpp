/*Problem: find number of ordered pairs (i,j) such that i<j and A[i]>A[j] --where A is arrayname.
Problem link: https://www.hackerearth.com/practice/algorithms/sorting/merge-sort/tutorial/
This problem is also known as "inversions in array".

Here we see that we need to compare each left side element with right side element.in a naive approach we compare by O(n^2) approach.
In merge sort we actually compare left side element with right side element with O(nlogn) .no matter at which step we are all element
are compared to their right side element
*/
#include <iostream>
using namespace std;
#define ll long long

ll counter=0;

void Merge(ll arr[], ll start, ll mid, ll endi)
{
    // 2 parts [start.........mid] and [mid+1........endi]
    ll temp[endi-start+1];
    ll i=start;
    ll j=mid+1;
    ll t=0;
    while(i<=mid && j<=endi)
    {

        if(arr[i]<=arr[j])
            temp[t++]=arr[i++];
        else
        {
            temp[t++]=arr[j++];
            counter+=mid-i+1;
        }
    }
    while(i<=mid)
    {
        temp[t++]=arr[i++];
    }
    while(j<=endi)
        temp[t++]=arr[j++];


    for(t=0; t<(endi-start+1); t++)
        arr[start+t]=temp[t];

}

void mergeSort(ll a[], ll start, ll endi)
{
    if(start<endi)
    {
        ll mid=(start+endi)/2;

        mergeSort(a,start,mid);
        mergeSort(a,mid+1,endi);

        Merge(a,start,mid,endi);
    }
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin>>n;
    ll arr[n];
    for(ll i=0; i<n; i++)
        cin>>arr[i];

    mergeSort(arr,0,n-1);
    for(ll i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<"\n";
    cout<<counter<<endl;

    return 0;
}
