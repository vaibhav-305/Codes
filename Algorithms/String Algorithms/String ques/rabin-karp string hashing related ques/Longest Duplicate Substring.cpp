/* problem link: https://leetcode.com/problems/longest-duplicate-substring/
Given a string s, consider all duplicated substrings: (contiguous) substrings of s that occur 2 or more times. The occurrences
may overlap.
Return any duplicated substring that has the longest possible length. If s does not have a duplicated substring, the answer is "". */
#include <iostream>
#include <set>
#include <utility>
using namespace std;

string longest_duplicate_substring(string );

int main()
{
    string s;
    cin>>s;
    cout<<longest_duplicate_substring(s);
  return 0;
}
string findSubs(string s,int winlen){
    int p1=31,p2=29,m=1e9+9;
    long long h_s1=0,h_s2=0,highestpow1=1,highestpow2=1;
    set<pair<int,int>> S;

    int i=0,j=0;
    //calculating highest pow
    for(int x=1;x<winlen;x++){
        highestpow1=(highestpow1*p1)%m;
        highestpow2=(highestpow2*p2)%m;
    }

    //first window
    for(j=0;j<winlen;j++){
        h_s1=(h_s1*p1 + (s[j]-'a'+1))%m;
        h_s2=(h_s2*p2 + (s[j]-'a'+1))%m;
    }
    S.insert(make_pair((int)h_s1,(int)h_s2));

    //rn i=0,j=winlen
    while(j<s.length()){
        h_s1=(p1*(h_s1-(s[i]-'a'+1)*highestpow1) + (s[j]-'a'+1))%m;
        if(h_s1<0)
            h_s1+=m;
        h_s2=(p2*(h_s2-(s[i]-'a'+1)*highestpow2) + (s[j]-'a'+1))%m;
        if(h_s2<0)
            h_s2+=m;
        i++;

        if(S.find(make_pair((int)h_s1,(int)h_s2))!=S.end()){
            /*for(pair<int,int> p:S){
                cout<<p.first<<" "<<p.second<<"\n";
            }
            cout<<" * "<<h_s1<<" "<<h_s2<<"\n";*/
            return s.substr(i,j-i+1);
        }
        else
            S.insert(make_pair((int)h_s1,(int)h_s2));

        j++;
    }
    return "";
}
string longest_duplicate_substring(string s)
{
    int left=1,right=s.length(),mid;
    string ans="";
    while(left<=right)
    {
        mid=(left+right)/2;
        string temp =findSubs(s,mid);
        if(temp.length()>0){
            ans=temp;
            left=mid+1;
        }
        else
            right=mid-1;
    }
    return ans;
}


