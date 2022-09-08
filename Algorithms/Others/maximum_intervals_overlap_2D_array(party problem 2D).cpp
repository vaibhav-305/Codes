//Problem link: https://www.codechef.com/problems/COWA19B
#include <iostream>
using namespace std;
long long int arr[1000+1][1000+1],calc[1000][1000];
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(0);
    /***************2D array overlap part starts from here**************/
    int n,m,u,q,r1,r2,c1,c2;
    long long int k,sum;

    cin>>n>>m>>u>>q;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>arr[i][j];
            calc[i-1][j-1]=0;
        }
    }
    for(int i=0;i<=m;i++)
        arr[0][i]=0;
    for(int i=0;i<=n;i++)
        arr[i][0]=0;
    ///operation of queries is done on calc[][] matrix
    while(u--)
    {
        cin>>k>>r1>>c1>>r2>>c2;
        for(int i=r1;i<=r2;i++){
            calc[i][c1]+=k;
            if(c2+1<m)
                calc[i][c2+1]-=k;
        }
    }
    for(int i=0;i<n;i++)
    {
        sum=calc[i][0];
        for(int j=1;j<m;j++)
        {
            if(calc[i][j]!=0)
                sum+=calc[i][j];

            calc[i][j]=sum;
        }
    }
    /*****************Till Here*****************/
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            arr[i][j]=arr[i][j]+calc[i-1][j-1];
    for(int i=1;i<=n;i++)
    {
        sum=0;
        for(int j=0;j<=m;j++){
            sum+=arr[i][j];
            arr[i][j]=sum+arr[i-1][j];
        }
    }
    while(q--)
    {
        cin>>r1>>c1>>r2>>c2;
        r1++,c1++,r2++,c2++;
        cout<<arr[r2][c2]-arr[r2][c1-1]-arr[r1-1][c2]+arr[r1-1][c1-1]<<"\n";
    }
  return 0;
}
