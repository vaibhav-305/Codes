//! This implementation assumes that the input string contains only lower case latin letters ('a'-'z').
//! T.C.= O(|txt| + |pat|)      S.C. = O(|txt|) to store prefix hash
/// This way is preferred when we have to do problems related to queries (see ques: https://www.codechef.com/problems/INSQ15_A )
#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> Prefix_rabin_karp(string pat, string txt) {          //<-- CP algorithm site implementation

    // 1. First we compute all the powers of p (p=29 and 31 in our code, 2 hashes so that it is a strong hash)
    // 2. Then we compute hash of all prefix strings of txt and store it. (h[1] -> hash of prefix of length 1, h[2] -> hash of prefix of length 2, ... and so on)
    // 3. Then we calculate calculate hash of pat which is calculated as => pat[0]*pow(p,0) + pat[1]*pow(p,1) + pat[2]*pow(p,2) + ... + pat[patlen-1]*pow(patlen-1) whole sum modulo m
    // 4. Then we find occurrences:

    const int p1 = 29;
    const int p2 = 31;
    const int m = 1e9 + 9;
    int patlen = pat.length(), txtlen = txt.length();

    /// computing all the powers (for used in hashing)
    vector<pair<int,int>> p_pow(max(patlen, txtlen));
    p_pow[0].first = p_pow[0].second = 1;
    for (int i = 1; i < p_pow.size(); i++){
        p_pow[i].first = (1ll*p_pow[i-1].first * p1) % m;
        p_pow[i].second = (1ll*p_pow[i-1].second * p2) % m;
    }

    /// computing hash of all prefix strings of txt and storing it in vector. It is a prefix hash array (just like prefix sum array)
    vector<pair<int,int>> h(txtlen + 1);
    h[0].first = h[0].second = 0;
    for (int i = 0; i < txtlen; i++){
        h[i+1].first = (1ll*h[i].first + 1ll*(txt[i] - 'a' + 1) * p_pow[i].first) % m;
        h[i+1].second = (1ll*h[i].second + 1ll*(txt[i] - 'a' + 1) * p_pow[i].second) % m;
    }

    /// finding hash of pattern
    long long h_pat1 = 0 , h_pat2 = 0;
    for (int i = 0; i < patlen; i++){
        h_pat1 = (h_pat1 + 1ll*(pat[i] - 'a' + 1) * p_pow[i].first) % m;      //hash is calculated as => pat[0]*pow(p,0) + pat[1]*pow(p,1) + pat[2]*pow(p,2) + ... + pat[patlen-1]*pow(patlen-1) whole sum modulo m
        h_pat2 = (h_pat2 + 1ll*(pat[i] - 'a' + 1) * p_pow[i].second) % m;
    }

    vector<int> occurences;
    for (int i = 0; i + patlen - 1 < txtlen; i++) {
        long long cur_h1 = (h[i+patlen].first - h[i].first + m) % m;    // h[i+patlen] - h[i] may be negative as we have taken modulo on h[i] values , so to avoid -ve we add m
        long long cur_h2 = (h[i+patlen].second - h[i].second + m) % m;
        if( (cur_h1 == 1ll*h_pat1 * p_pow[i].first % m) && (cur_h2 == 1ll*h_pat2 * p_pow[i].second % m) )      //as we comparing window answers, so there is some pow(p,k) (k can be any int depending on where the window is) in it , so to compare it with pattern we, multipy that pow(p,k) with pattern too for checking equality, If we multipy with curr_h(window hash) we have to take modeulo inverse of pow(p,k) and then multipy it with curr_h.
            occurences.push_back(i);
    }
  return occurences;
}
int main()
{
    string pat,txt;
    cin>>txt>>pat;
    cout<<"starting indices of pat in s: ";
    if(pat.length()<=txt.length()){
        vector<int> occurences = Prefix_rabin_karp(pat,txt);    //if vector empty -> no occurrence found
        for(int i:occurences)
            cout<<i<<" ";
    }
    else
        cout<<"Pat length is greater than txt length";
  return 0;
}
/*
barfoobarfoobarfoobarfoobarfoo
foobarfoo
Ans:3 9 15 21
*/
