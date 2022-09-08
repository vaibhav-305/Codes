//T.C.= O(n^3)   S.C.= O(n*n*2);
#include <iostream>
#include <vector>
using namespace std;
using llt = long long int;
int M=1e9+7;

int solve(int i,int j,int istrue,string& s,vector<vector<vector<int>>>& memo){
    if(i>j)
        return 0;
    if(i==j){
        if(istrue)
            return s[i]=='T';
        else
            return s[i]=='F';
    }
    if(memo[i][j][istrue]!=-1)
        return memo[i][j][istrue];

    llt ways=0;
    for(int k=i+1;k<=j-1;k+=2){
        llt lT = solve(i,k-1,1,s,memo);
        llt lF = solve(i,k-1,0,s,memo);
        llt rT = solve(k+1,j,1,s,memo);
        llt rF = solve(k+1,j,0,s,memo);

        if(s[k]=='&'){
            if(istrue)
                ways = (ways + (lT*rT))%M;
            else  //for false in AND
                ways = (ways + (lT*rF) + (lF*rT) + (lF*rF))%M;
        }
        else if(s[k]=='|'){
            if(istrue)
                ways = (ways + (lT*rF) + (lF*rT) + (lT*rT))%M;
            else  //for false in OR
                ways = (ways + (lF*rF))%M;
        }
        else{ //XOR
            if(istrue)
                ways = (ways + (lT*rF) + (lF*rT))%M;
            else  //for false in XOR
                ways = (ways + (lT*rT) + (lF*rF))%M;
        }
    }
    return memo[i][j][istrue]=(int)ways;
}
int Eval(string s){
    int n=s.length();
    vector<vector<vector<int>>> memo(n,vector<vector<int>>(n,vector<int>(2,-1)));
    return solve(0,n-1,1,s,memo);
}
int main()
{
    string s;
    cin>>s;
    cout<<Eval(s);
  return 0;
}
/*
F|T^F
Ans: 2

T^T^F
Ans: 0

T&T&F^T
Ans: 5
*/
