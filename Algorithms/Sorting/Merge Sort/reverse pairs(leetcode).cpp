#include <iostream>
#include <math.h>
//#include <vector>
//#include <unordered_set>
using namespace std;
using llt=long long int;

int counter=0;
int nextgreatest(int* arr,int start,int end, int targ) //returns index of element greater than 2*targ
{
    llt target =(llt)2*targ;
    llt temp;
    int endi=end;
    int ans;
    temp=(llt)arr[endi];
    if(temp<=target)
        return 0;

    //temp=arr[start];
    //if(arr)
    //cout<<start<<" "<<endi<<"\n";
    while (start <= endi)
    {
        int mid = (start + endi) / 2;

        // Move to right side if target is
        // greater.
        temp=(llt)arr[mid];
        if (temp <= target)
            start = mid + 1;

        // Move left side.
        else
        {
            ans = mid;
            endi = mid - 1;
        }
    }
    //cout<<start<<" "<<endi<<" "<<ans<<"\n";
    return end-ans+1;
}
void Merge(int* arr, int start, int mid, int endi)
{
    //start....mid  mid+1.....end
    int temp[endi-start+1];
    int i=start;
    int j=mid+1;
    int t=0;
    while(i<=mid && j<=endi)
    {
        if(arr[i]<arr[j])     //in this case [-5,-5]; -5 > 2*(-5) we need to inspect for '=' condn so we'll not do <= here
            temp[t++]=arr[i++];
        else
        {
            temp[t]=arr[j];
            counter+=nextgreatest(arr,i,mid,temp[t]);
            t++,j++;
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
void merge_sort(int* arr, int start, int endi)
{
    if(start<endi)
    {
        int mid=(start+endi)/2;

        merge_sort(arr,start,mid);
        merge_sort(arr,mid+1,endi);

        Merge(arr,start,mid,endi);
    }

}
void reversePairs(int arr[],int n){
    counter=0;
    merge_sort(arr,0,n-1);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    reversePairs(arr,n);
    cout<<counter;
  return 0;
}
/*
6
2147483647 2147483647 -2147483647 -2147483647 -2147483647 2147483647 ->9
2
-5 -5 ->1
5
2 4 3 5 1 -> 3
*/
