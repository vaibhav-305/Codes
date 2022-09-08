#include <iostream>
#include <stack>
using namespace std;

int max_rectangular_area_under_histogram1(int *,int );      //! O(4n) 2-pass soln
int max_rectangular_area_under_histogram2(int *,int );      //! O(2n) 1-pass soln (optimized one)

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    //cout<<max_rectangular_area_under_histogram1(arr,n)<<"\n";
    cout<<max_rectangular_area_under_histogram2(arr,n)<<"\n";
  return 0;
}
int max_rectangular_area_under_histogram2(int arr[],int n)   //! T.C.= O(n)+O(n)       S.C.= O(n)     Its a one-pass soln. Only once array and stack is traversed
{
    stack<int> S;           //for storing indexes of nearest smaller to left
    int mx=0,height,width;
    for(int i=0;i<n;i++)
    {
        if(S.empty() || arr[S.top()]<=arr[i])          //pushing elements of increasing order(1,2,3..topElement) so automatically the element just below stack.top() will be its nearest smaller to left.
            S.push(i);

        else         //this will break when stack.top() element will be greater than than arr[i] which is actually the nearest smaller to right.
        {
            while( !S.empty() && arr[S.top()]>arr[i])
            {
                height=arr[S.top()];
                S.pop();

                if(S.empty())
                    width=i;          //this means there is no nearest smaller element to left, so we'll take the width from the starting i.e. i-0 => i
                else
                    width=i-S.top()-1;        //rightsmallindx-leftsmallindx-1

                mx=max(mx, height*width);
            }
            S.push(i);
        }
    }
    // Now pop the remaining bars from stack and calculate area with every popped bar as the smallest bar
    // Now here for all the remaining the nearest smallest to right will be index n (where the histogram has finished aka arr[n]=0
    while(!S.empty())
    {
        height=arr[S.top()];
        S.pop();

        if(S.empty())
            width=n;          //this means there is no nearest smaller element to left, so we'll take the width from the starting i.e. n-0 => n
        else
            width=n-S.top()-1;

        mx=max(mx, height*width);
    }

    return mx;
}

int max_rectangular_area_under_histogram1(int *arr,int n)   //! T.C.= O(n)+O(n)+O(n)+O(n)    S.C.= O(2n)+O(n)         It is a 2 pass solution as array is traversed twice and so is the stack.
{
    stack<int> S1,S2;
    int l[n],r[n],lef,rig,mx=INT_MIN;
    //nearest smaller element to right
    for(int i=n-1;i>=0;i--)
    {
        if(S1.empty())
            r[i]=n;
        else if(arr[S1.top()]<arr[i])
            r[i]=S1.top();
        else
        {
            while(!S1.empty())
            {
                if(arr[S1.top()]<arr[i])
                    break;
                S1.pop();
            }
            if(S1.empty())
                r[i]=n;
            else
                r[i]=S1.top();
        }
        S1.push(i);
    }
    //for nearest smaller element to left
    for(int i=0;i<n;i++)
    {
        if(S2.empty())
            l[i]=-1;
        else if(arr[S2.top()]<arr[i])
            l[i]=S2.top();
        else
        {
            while(!S2.empty())
            {
                if(arr[S2.top()]<arr[i])
                    break;
                S2.pop();
            }
            if(S2.empty())
                l[i]=-1;
            else
                l[i]=S2.top();
        }
        S2.push(i);
    }
    /*for(int i=0;i<n;i++)
        cout<<r[i]<<" ";
    cout<<endl;
    for(int i=0;i<n;i++)
        cout<<l[i]<<" ";
    cout<<endl;*/
    for(int i=0;i<n;i++)
    {
        lef=l[i]+1;
        rig=r[i]-1;
        mx=max(mx,((rig-lef+1)*arr[i]));   //simplified to mx=max(mx, (r[i]-l[i]-1)*arr[i] )
    }
    return mx;
}
