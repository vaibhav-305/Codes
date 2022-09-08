/** Sort the array in such a way that {(no. smaller than a),a,(no. between a and b),b,(no. greater than b)} */
//Here a and b are given
//O(2*n) Time and O(1) space
#include <iostream>
using namespace std;

void Swap(int *a,int *b)
{
    int k=*a;
    *a=*b;
    *b=k;
}
int main()
{   //code
	int n,l,r,mid,a,b;
	cin>>n>>a>>b;
	int arr[n];
	for(int i=0;i<n;i++)
        cin>>arr[i];
    //Algo starts from here
    l=0;
    mid=0;
    r=n-1;
    while(mid<=r)
    {
        if(arr[mid]<a)
       {
           Swap(&arr[mid],&arr[l]);
           l++;
           mid++;
       }
       else if(arr[mid]==a)
        mid++;
       else
       {
           Swap(&arr[mid],&arr[r]);
           r--;
       }

    }
    l=mid;
    r=n-1;
    while(mid<=r)
    {
        if(arr[mid]<b)
       {
           Swap(&arr[mid],&arr[l]);
           l++;
           mid++;
       }
       else if(arr[mid]==b)
        mid++;
       else
       {
           Swap(&arr[mid],&arr[r]);
           r--;
       }

    }
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}
