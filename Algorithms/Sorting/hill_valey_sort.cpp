#include <iostream>
#include <algorithm>
using namespace std;

void sort_HillValley(int *arr,int n,int i,int j)
{
    if(i==-1)
        return ;
    int a=arr[i];
    int b=arr[j];
    //cout<<a<<" "<<b<<endl;
    sort_HillValley(arr,n-1,i-1,j+1);
    //cout<<a<<" "<<b<<" "<<n<<endl;
    arr[2*n]=a;
    arr[2*n+1]=b;
}
int main() {
	//code
	int n;
	cin>>n;
	int arr[n],mid,temp;
	for(int i=0;i<n;i++)
        cin>>arr[i];
    mid=(n-1)/2;
    temp=arr[mid];
    if(n%2==0)
        sort_HillValley(arr,(n-1)/2,mid,mid+1);
    else{
        sort_HillValley(arr,(n-2)/2,mid-1,mid+1);
        arr[n-1]=temp;
    }
    for(int i:arr)
        cout<<i<<" ";
	return 0;
}
