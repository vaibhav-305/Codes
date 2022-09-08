#include <iostream>
#include <utility>
#include <vector>
#include <cmath>
using namespace std;
using llt = long long int;

vector<pair<int,int>> primeFactorization(int n)                  /// T.C.=O(sqrt(n))
{
    int cnt=0;
    vector<pair<int,int>> primefact;
    for(int i=2; i*i<=n; i++)
    {
        if(n%i==0)
        {
            cnt=0;
            while(n%i==0)
            {
                cnt++;
                n=n/i;
            }
            primefact.push_back(make_pair(i,cnt));
        }
    }
    //if no. is prime
    if(n>1)
        primefact.push_back(make_pair(n,1));

    return primefact;
}
int NumOfDivisor(vector<pair<int,int>> primefact)
{
    int ans=1;
    for(pair<int,int> p:primefact)
    {
        ans*=(p.second+1);
    }
    return ans;
}
int sumOfDiv(vector<pair<int,int>> primefact)
{
    int numerator = 1, denominator = 1;
    for(pair<int,int> p:primefact)
    {
        numerator*=( pow(p.first,p.second+1) - 1 );
        denominator*=(p.first-1);
    }
    return numerator/denominator;
}
int main()
{
    int n;
    cin>>n;

    vector<pair<int,int>> primefact = primeFactorization(n);
    int numOfDiv = NumOfDivisor(primefact);

    cout<<"Sum of Divisors: "<<sumOfDiv(primefact);
    cout<<"\nProduct of Divisors: "<<pow(n,numOfDiv/2);        //product of divisors of n = pow(n,numberOfDivisors/2)
  return 0;
}
