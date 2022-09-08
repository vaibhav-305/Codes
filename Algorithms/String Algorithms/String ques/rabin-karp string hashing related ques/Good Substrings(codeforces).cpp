// Ques Link: https://codeforces.com/problemset/problem/271/D
#include <iostream>
#include <string>
#include <set>
#include <utility>
using namespace std;
set<pair<int,int>> S;

int main() {
	//code
	ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

	int k,temp,i,j;
	string s,bin;
	cin>>s>>bin>>k;
	long long h_s1,h_s2=0;
	int p1=31,p2=29,m=1e9 + 9;

	for(i=0;i<s.length();i++){
        temp=1;
        h_s1=0;
        h_s2=0;
        for(j=i;j<s.length();j++){
            if(bin[s[j]-'a']=='0'){
                if(temp<=k)
                    temp++;
                else
                    break;
            }
            h_s1=(h_s1*p1 + (s[j]-'a'+1))%m;
            h_s2=(h_s2*p2 + (s[j]-'a'+1))%m;
            S.insert(make_pair((int)h_s1,(int)h_s2));
        }
	}
	cout<<S.size();
    return 0;
}
/*
dcijflpluxgeqlroaktzcujfaaidnrdzgogzhobhsmbwmjpschtvjmivfapddsmxfvlhhgguymgtdjxpiezbnlmnlvdnuaohqskdbcjlyfdrzicflveffvpeyzhwqqdaenbsghuvetpxvqcutjxbelbfzuqpwlfvveebnmkoryxgodpccanzwhziiiumgtwskxhrhwdkwmyreefwmoedcvaokvetcgundyiidsqkolpqkarpszrrmagrfvpnwharotashtwcnrcnhapdwrbltgkpkkmlrpapfizonyttrikh
11011010101101110101010001
54
Ans:  31658

By doing only one hash (p=31 only) below collisions will happen for above testcase, so thats why we did 2 hashes
skdbcjlyfdrzicflveffvpe belbfzuqpwlfvvee 257471541 <- hash value
skdbcjlyfdrzicflveffvp belbfzuqpwlfvve 911531348 <- hash value
*/
