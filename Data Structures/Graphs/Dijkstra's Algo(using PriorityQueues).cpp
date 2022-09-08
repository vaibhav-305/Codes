//Works for both directed as well as undirected graph with non -ve edge weights
//T.C.=O((V+E)log(V))
//!  Here Implemented for Undirected weighted graph
#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <iterator>
#include <cstring>
#define INF INT_MAX
using namespace std;

void DijkstraShortestPath(vector<vector<int>> ,int ,map<pair<int,int>,int> ,int );

void printGraph(vector<vector<int>> adj_list,int adj_listSz)
{
    cout<<"Adjacency List:--\n";
    for(int i=1;i<adj_listSz;i++)
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
    vector<vector<int>> adj_list(V+1);
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
    DijkstraShortestPath(adj_list,V,weights,src); //here src=0
    //DijkstraShortestPath(adj_list,V+1,weights,src,dest);
    //printGraph(adj_list,V+1);
    //for(itr=weights.begin();itr!=weights.end();itr++)
    //    cout<<(itr->first).first<<" - "<<(itr->first).second<<" "<<itr->second<<endl;
  return 0;
}
inline int getEdgeWt(map<pair<int,int>,int> weights,int u,int v){
    if(v<u)
        swap(u,v);
    return weights[{u,v}];
}
inline void printPath(int parent[], int j){
    // Base Case : If j is source
    if (parent[j] == - 1)
        return;
    printPath(parent, parent[j]);
    cout<<j<<" ";
}
void DijkstraShortestPath(vector<vector<int>> adj_list,int V,map<pair<int,int>,int> weights,int src) //,dest if given
{
    int *dist=new int[V+1];
    fill(dist,dist+(V+1),INT_MAX);

    bool *processed=new bool[V+1];
    memset(processed,false,sizeof(processed));

    int *parent=new int[V+1];
    fill(parent,parent+(V+1),-1);


    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pQ;

    pQ.push(make_pair(0,src));
    dist[src] = 0;

    int u,wt;
    vector<int> vec;
    while(!pQ.empty())
    {
        u=pQ.top().second;
        pQ.pop();
        processed[u]=true;
        //if(processed[dest])
         //   break;

        vec=adj_list[u];
        for(int v:vec)
        {
            if(!processed[v])
            {
                wt=getEdgeWt(weights,u,v);
                //cout<<dist[u]+wt<<" ";
                if(dist[u]+wt<dist[v])
                {
                    dist[v] = dist[u] + wt;
				    pQ.push(make_pair(dist[v], v));
				    parent[v]=u;
                }
            }
        }

    }
    cout<<"Output:\n";
    cout<<"Vertex\t\tDistance\tPath";
    for(int i=1;i<=V;i++)
    {
        printf("\n%d -> %d \t\t %d\t\t%d ",
                      src, i, dist[i], src);
        printPath(parent, i);
    }
    delete dist;
    delete processed;
    delete parent;
}
/*
dataset :
9 16
1 2 4
1 8 8
8 7 1
7 6 2
4 5 9
6 3 4
9 3 2
3 4 7
7 8 10 //Parallel edge
8 2 11
6 5 10
4 6 14
5 5 3  //self loop
7 9 6
2 3 8
8 9 7

          8        7
    (2)-------(3)-------(4)
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
*/
