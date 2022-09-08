/*
Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
 ** Roman numerals are usually written largest to smallest from left to right and get added.
However, There are six instances where subtraction is used:
    -> I can be placed before V (5) and X (10) to make 4 and 9.
    -> X can be placed before L (50) and C (100) to make 40 and 90.
    -> C can be placed before D (500) and M (1000) to make 400 and 900.
*/
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int roman_to_int(string );
string int_to_roman(int );

int main()
{
    string s;
    cin>>s;
    cout<<roman_to_int(s)<<"\n";

    int n;
    cin>>n;
    cout<<int_to_roman(n);
  return 0;
}
int roman_to_int(string s)
{
    int n=s.length();
    unordered_map<char, int> M = { {'I',1}, {'V',5}, {'X',10}, {'L',50}, {'C',100}, {'D',500}, {'M',1000} };

    int i=0,j=1;
    int num=0;
    while(j<n)
    {
        if(s[i]=='I' && s[j]=='V'){
            num+=4;
            i+=2;
            j+=2;
        }
        else if(s[i]=='I' && s[j]=='X'){
            num+=9;
            i+=2, j+=2;
        }
        else if(s[i]=='X' && s[j]=='L'){
            num+=40;
            i+=2, j+=2;
        }
        else if(s[i]=='X' && s[j]=='C'){
            num+=90;
            i+=2, j+=2;
        }
        else if(s[i]=='C' && s[j]=='D'){
            num+=400;
            i+=2, j+=2;
        }
        else if(s[i]=='C' && s[j]=='M'){
            num+=900;
            i+=2, j+=2;
        }
        else {
            num+=M[s[i]];
            i++, j++;
        }
    }
    if(i==n-1)
        num+=M[s[i]];

    return num;
}

int floor_indx(vector<pair<int,string>>& arr, int val)
{
    int n=arr.size();
    int low=0, high=n-1,mid;
    if(arr[0].first > val)            //if smallest element in array is greater than val, floor doesn't exist in array
        return -1;
    if(arr[n-1].first<=val)           //if the largest element is smaller than or equal to the val , then last index will be floor_indx.
        return n-1;

    while(low<=high)
    {
        mid=(high+low)/2;

        if(arr[mid].first==val)
            return mid;
        else if(arr[mid].first>val)
            high=mid-1;
        else
            low=mid+1;
    }
    return high;
}
string int_to_roman(int n)
{
    //Roman numerals are usually written largest to smallest from left to right and get added
    vector<pair<int,string>> M = { {1,"I"}, {4,"IV"}, {5,"V"}, {9,"IX"}, {10,"X"}, {40,"XL"}, {50,"L"}, {90,"XC"}, {100,"C"}, {400,"CD"}, {500,"D"}, {900,"CM"}, {1000,"M"} };

    string roman="";
    int quo,d;
    while(n)
    {
        d=floor_indx(M,n);
        quo=n/M[d].first;
        while(quo--)
            roman.append(M[d].second);
        n=n % M[d].first;
    }
    return roman;
}
/*
MCMXCIV
Ans: 1994
*/
