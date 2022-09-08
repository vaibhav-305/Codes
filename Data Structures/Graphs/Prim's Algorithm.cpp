//Time Complexity: O(E*log(V))
#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <iterator>
#include <cstring>
using namespace std;

vector<vector<int>> PrimsMST(vector<int> *,int ,map<pair<int,int>,int>,int);

void printGraph(vector<int> adj_list[],int V)
{
    cout<<"Adjacency List:--\n";
    for(int i=1;i<=V;i++)
    {
        cout<<"\nAdjacencies of vertex "<<i<<":\n";
        for(int j=0;j<adj_list[i].size();j++)
            cout<<adj_list[i][j]<<" ";
    }
    cout<<"\n";
}

int main()
{
    int V,E,u,v,wt,src=1;
    cin>>V>>E;
    vector<int> adj_list[V+1];
    map<pair<int,int>,int> weights;
    map<pair<int,int>,int> :: iterator itr;
    pair<int,int> p;
    for(int i=1;i<=E;i++)
    {
        cin>>u>>v>>wt;
        if(v<u)
            swap(u,v);
        p=make_pair(u,v);
        itr=weights.find(p);
        if(itr==weights.end())
        {
            adj_list[u].push_back(v);
            adj_list[v].push_back(u);
            weights.insert(make_pair(make_pair(u,v),wt));
        }
        else
        {
            if((itr->second)>wt)
                itr->second=wt;
        }
    }

    vector<vector<int>> mst=PrimsMST(adj_list,V,weights,src);
    cout<<"Adjacency List of MST:--\n";
    for(int i=1;i<=V;i++)
    {
        cout<<"\nAdjacencies of vertex "<<i<<":\n";
        for(int j=0;j<mst[i].size();j++)
            cout<<mst[i][j]<<" ";
    }
    cout<<"\n";
    //printGraph(adj_list,V);
    //for(itr=weights.begin();itr!=weights.end();itr++)
      //  cout<<(itr->first).first<<" - "<<(itr->first).second<<" "<<itr->second<<endl;
  return 0;
}
inline int getEdgeWt(map<pair<int,int>,int> weights,int u,int v){
    if(v<u)
        swap(u,v);
    return weights[{u,v}];
}
vector<vector<int>> PrimsMST(vector<int> adj_list[],int V,map<pair<int,int>,int> weights,int src)
{
    int *dist=new int[V+1];
    fill(dist,dist+(V+1),INT_MAX);

    bool *processed=new bool[V+1];
    memset(processed,false,sizeof(processed));

    int *parent=new int[V+1];
    fill(parent,parent+(V+1),-1);  //here memeset will generate error

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pQ;

    pQ.push(make_pair(0,src));
    dist[src] = 0;

    int u,wt,VinMst=0;
    vector<int> vec;
    while(!pQ.empty())
    {
        u=pQ.top().second;
        pQ.pop();
        processed[u]=true;
        VinMst++;
        if(VinMst==V)
            break;

        vec=adj_list[u];
        for(int v:vec)
        {
            if(!processed[v])
            {
                wt=getEdgeWt(weights,u,v);
                if(wt<dist[v])
                {
                    dist[v] = wt;
				    pQ.push(make_pair(dist[v], v));
				    parent[v]=u;
                }
            }
        }
    }
    /*for(int i=1;i<=V;i++)
        cout<<parent[i]<<" ";
    cout<<endl;*/
    vector<vector<int>> mst(V+1);
    for(int i=1;i<=V;i++)
    {
        if(parent[i]!=-1)
        {
            mst[i].push_back(parent[i]);
            mst[parent[i]].push_back(i);
        }
    }
    delete dist;
    delete processed;
    delete parent;

    return mst;
}
/*
9 16
1 2 4
1 8 8
8 7 1
7 6 2
4 5 9
6 3 4
9 3 2
3 4 6
7 8 10
8 2 11
6 5 10
4 6 14
5 5 3
7 9 6
2 3 8
8 9 7

          8        7
    (2)-------(3)-------(9)
    /|         |         |\
  4/ |         | 2       | \9  ___
  /  |        (9)        |  \ /   |
(1)  |11     / |       14|  (5)   |3
  \  |     /   |6        |  / \___|
  8\ |   / 7   |         | /10
    \| /       |         |/
    (8)_______(7)_______(6)
      \   1   /     2
       \_____/
          10
Note :  There are two possible MSTs, the other
        MST includes edge 0-7 in place of 1-2.
*/
