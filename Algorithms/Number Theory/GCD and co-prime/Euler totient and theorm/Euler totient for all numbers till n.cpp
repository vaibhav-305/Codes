//This approach calculates phi[] values (euler totient function) from 1 to n
//! T.C.= O(n*log(log(n)))      S.C.= O(n)    storing all phi[] values from 1 to n
#include <iostream>
using namespace std;
using llt = long long int;

int phi[1000001];

void euler_totient_init(int n)   //used for range queries ONLY APPLICABLE FOR n<=1e6
{
    for(int i=1;i<=n;i++)
        phi[i] = i;

    for(int i=2;i<=n;i++)
    {
        if(phi[i]==i)
        {
            for(int j=i;j<=n;j+=i){
                phi[j]=phi[j]/i;
                phi[j]=phi[j]*(i-1);  //(i-1)/i  => (p-1)/p
            }

        }
    }
}

int main()
{
    int n=1e6;
    euler_totient_init(n);
    int T,a;
    cin>>T;
    while(T--){
        cin>>a;
        cout<<phi[a]<<"\n\n";
    }
  return 0;
}
