/*Ques: We have given an index p, from there break string into 2 parts s[0..p-1] and s[p..slen-1], we need to find
        Longest common prefix(LCP) of these 2 parts
  Link: https://www.codechef.com/problems/INSQ15_A
  Approach: Binary search + Prefix hash Rabin-Karp
      1. Compute hash for every prefix of the string in O(N) total.
      2. Now, we'll do a binary search on all possible lengths: 0 to min(P, N-P), to find the highest value, say, mid , where
                        substring [0 to mid] = substring [P to P+mid]
      3. Each time, we can do this checking in O(1), and we’ll have to check O(logN) times per query Q, to find the highest length.

  Thus overall complexity is O(N + Q*log(N)).
OPTIMAL solution will be to use Z-algorithm (see in Z-algo ques or ques editorial)
*/
#include <iostream>
#include <vector>
#include <utility>
#include <string>
using namespace std;
vector<pair<int,int>> p_pow;
vector<pair<int,int>> h;
const int p1 = 29, p2 = 31, m = 1e9 + 9;

void prefxHash(string& txt,int txtlen)
{
    /// computing all the powers (for used in hashing)
    p_pow.assign(txtlen);
    p_pow[0].first = p_pow[0].second = 1;
    for (int i = 1; i < p_pow.size(); i++){
        p_pow[i].first = (1ll*p_pow[i-1].first * p1) % m;
        p_pow[i].second = (1ll*p_pow[i-1].second * p2) % m;
    }

    /// computing hash of all prefix strings of txt and storing it in vector. It is a prefix hash array (just like prefix sum array)
    h.assign(txtlen + 1);
    h[0].first = h[0].second = 0;
    for (int i = 0; i < txtlen; i++){
        h[i+1].first = (1ll*h[i].first + 1ll*(txt[i] - 'a' + 1) * p_pow[i].first) % m;
        h[i+1].second = (1ll*h[i].second + 1ll*(txt[i] - 'a' + 1) * p_pow[i].second) % m;
    }
}
string LCP(string &txt, int txtlen, int p)
{
    int l=0,h=min(p-1,txtlen-1-p),mid;
    int ansIndx,tempindx,curr1,curr2;
    while(l<=r){
        mid = (l+r)/2;
        curr1 = (1ll*p_pow[p].first * h[mid].first)%m;
        curr2 = (1ll*p_pow[p].second * h[mid])
        if( (h[p+mid].first- == p_pow[p]*h[mid].first)
    }

}
int main()
{
    string txt;
    cin>>txt;
    int txtlen = txt.length();

    prefixHash(txt,txtlen);

    int queries,p;
    cin>>queries;
    while(queries--){
        cin>>p;
        cout<<LCP(txt,txtlen,p)<<"\n";
    }
  return 0;
}
