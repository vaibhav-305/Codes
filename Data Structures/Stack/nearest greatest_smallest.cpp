#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

vector<int> Nearest_greater_to_right(int *,int );
vector<int> Nearest_greater_to_left(int *,int );
vector<int> Nearest_smaller_to_left(int *,int );
vector<int> Nearest_smaller_to_right(int *,int );

int main()
{
    int T;
    cin>>T;
    while(T--){
    int n;
    cin>>n;
    vector<int> v;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    v=Nearest_greater_to_right(arr,n);
    cout<<"Nearest greater to right: ";
    for(int i:v)
        cout<<i<<" ";
    cout<<endl;
    v=Nearest_greater_to_left(arr,n);
    cout<<"Nearest greater to left: ";
    for(int i:v)
        cout<<i<<" ";
    cout<<endl;
    v=Nearest_smaller_to_left(arr,n);
    cout<<"Nearest smaller to left: ";
    for(int i:v)
        cout<<i<<" ";
    cout<<endl;
    v=Nearest_smaller_to_right(arr,n);
    cout<<"Nearest smaller to right: ";
    for(int i:v)
        cout<<i<<" ";
    cout<<endl;
    }
  return 0;
}
vector<int> Nearest_greater_to_right(int arr[],int n)
{
    stack<int> St;
    vector<int> ans;
    for(int i=n-1;i>=0;i--)
    {
        if(St.empty())
            ans.push_back(-1);
        else if(St.top()>arr[i])
            ans.push_back(St.top());
        else if(St.top()<=arr[i])
        {
            while(!St.empty())
            {
                if(St.top()>arr[i])
                    break;
                St.pop();
            }
            if(St.empty())
                ans.push_back(-1);
            else
                ans.push_back(St.top());
        }
        St.push(arr[i]);

    }
    reverse(ans.begin(),ans.end());
    return ans;
}
vector<int> Nearest_greater_to_left(int *arr,int n)
{
    vector<int> ans;
    stack<int> St;
    for(int i=0;i<n;i++)
    {
        if(St.empty())
            ans.push_back(-1);
        else if(St.top()>arr[i])
            ans.push_back(St.top());
        else
        {
            while(!St.empty())
            {
                if(St.top()>arr[i])
                    break;
                St.pop();
            }
            if(St.empty())
                ans.push_back(-1);
            else
                ans.push_back(St.top());
        }
        St.push(arr[i]);
    }
    return ans;
}
vector<int> Nearest_smaller_to_left(int arr[],int n)
{
    vector<int> v;
    stack<int> St;
    for(int i=0;i<n;i++)
    {
        if(St.empty())
            v.push_back(-1);
        else if(St.top()<arr[i])
            v.push_back(St.top());
        else
        {
            while(!St.empty())
            {
                if(St.top()<arr[i])
                    break;
                St.pop();
            }
            if(St.empty())
                v.push_back(-1);
            else
                v.push_back(St.top());
        }
        St.push(arr[i]);
    }
    return v;
}
vector<int> Nearest_smaller_to_right(int arr[],int n)
{
    vector<int> v;
    stack<int> St;
    for(int i=n-1;i>=0;i--)
    {
        if(St.empty())
            v.push_back(-1);
        else if(St.top()<arr[i])
            v.push_back(St.top());
        else
        {
            while(!St.empty())
            {
                if(St.top()<arr[i])
                    break;
                St.pop();
            }
            if(St.empty())
                v.push_back(-1);
            else
                v.push_back(St.top());
        }
        St.push(arr[i]);
    }
    reverse(v.begin(),v.end());
    return v;
}
