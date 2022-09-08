/// T.C.=O(M^3 * log(n))            M-> dimesion of matrix   n->power
#include <iostream>
#include <vector>
#define MOD 1000000007 //1e9 + 7
using namespace std;

vector<vector<int>> fastPow_Matrix(vector<vector<int>> ,int ,int );

int main()
{
    int dim,n;
    cin>>dim>>n;    //fact: only square-matrix(say A) can go A^n (A power n)

    vector<vector<int>> A(dim,vector<int>(dim));

    for(int i=0;i<dim;i++)
        for(int j=0;j<dim;j++)
            cin>>A[i][j];

    vector<vector<int>> res=fastPow_Matrix(A,dim,n);

    for(int i=0;i<dim;i++){
        for(int j=0;j<dim;j++)
            cout<<res[i][j]<<" ";
        cout<<endl;
    }

  return 0;
}
vector<vector<int>> multiply(vector<vector<int>> A, vector<vector<int>> B, int dim)      //returns A*B
{
    vector<vector<int>> res(dim,vector<int>(dim));

    for(int i=0;i<dim;i++){
        for(int j=0;j<dim;j++){
            res[i][j]=0;             //initialization
            for(int k=0;k<dim;k++){
                res[i][j]+= (A[i][k]*B[k][j])%MOD;   //%MOD if asked to do so
                // res[i][j] = (res[i][j] % MOD + ((A[i][k] % MOD) * (B[k][j] % MOD) % MOD)) % MOD; //for SPOJ problem
            }
        }
    }
    return res;
}
vector<vector<int>> fastPow_Matrix(vector<vector<int>> A,int dim,int n)   //A^n
{
    //first we define an identity matrix
    vector<vector<int>> I(dim,vector<int>(dim,0));
    for(int i=0;i<dim;i++)
        I[i][i]=1;

    vector<vector<int>> res=I;      //like res=1 in case of integers

    while(n)
    {
        if(n&1)                    //if n is odd
        {
            res=multiply(res,A,dim);
            n--;
        }
        else
        {
            A=multiply(A,A,dim);
            n=(n>>1);              //equivalent to n=n/2
        }
    }

    return res;
}
/*
Spoj accelpted solution: MPOW SPOJ

#include <iostream>
#include <vector>
#define MOD 1000000007 //1e9 + 7
using namespace std;
using ll = long long;

vector<vector<ll>> fastPow_Matrix(vector<vector<ll>>,int,int );

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    int dim,n;
    vector<vector<ll>> A(50,vector<ll>(50));
    while(T--){
        cin>>dim>>n;    //fact: only square-matrix(say A) can go A^n (A power n)

        for(int i=0; i<dim; i++)
            for(int j=0; j<dim; j++)
                cin>>A[i][j];

        vector<vector<ll>> res=fastPow_Matrix(A,dim,n);

        for(int i=0; i<dim; i++)
        {
            for(int j=0; j<dim; j++)
                cout<<res[i][j]<<" ";
            cout<<endl;
        }
    }
return 0;
}
vector<vector<ll>> multiply(vector<vector<ll>> A, vector<vector<ll>> B, int dim)      //returns A*B
{
    vector<vector<ll>> res(dim,vector<ll>(dim));

    for(int i=0; i<dim; i++)
    {
        for(int j=0; j<dim; j++)
        {
            res[i][j]=0;             //initialization
            for(int k=0; k<dim; k++)
            {
                res[i][j] = (res[i][j] % MOD + ((A[i][k] % MOD) * (B[k][j] % MOD) % MOD)) % MOD;
            }
        }
    }
    return res;
}
vector<vector<ll>> fastPow_Matrix(vector<vector<ll>> A,int dim,int n)   //A^n
{
    //first we define an identity matrix
    vector<vector<ll>> res(dim,vector<ll>(dim,0));
    for(int i=0; i<dim; i++)
        res[i][i]=1;

    while(n)
    {
        if(n&1)                    //if n is odd
        {
            res=multiply(res,A,dim);
            n--;
        }
        else
        {
            A=multiply(A,A,dim);
            n=(n>>1);              //equivalent to n=n/2
        }
    }

    return res;
}
*/
