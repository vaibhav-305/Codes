//! No. of subsequences = 2^n
#include <iostream>
#include <vector>
using namespace std;

void printAllSubseq(int arr[],int n,int currindx,vector<int> temp)
{
    if(currindx==n){
        for(int i:temp)
            cout<<i<<" ";
        cout<<"\n";
        return;
    }
    printAllSubseq(arr,n,currindx+1,temp); //not picking the current index element
    temp.push_back(arr[currindx]);     //picking the current index element
    printAllSubseq(arr,n,currindx+1,temp);
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    vector<int> temp;
    printAllSubseq(arr,n,0,temp);
  return 0;
}
