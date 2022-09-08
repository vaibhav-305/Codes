//Works for both directed as well as undirected graph with non -ve weight cycle
//T.C.=O(E.V)~O(n*n)
//!  Here Implemented for directed weighted graph
#include <iostream>
#include <map>
#include <vector>
#include <iterator>
#include <cstring>
using namespace std;

void BellmanFordShortestPath(int ,map<pair<int,int>,int> ,int );

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
    vector<vector<int>> adj_list(V+1); //No need for adj_list in this algo
    map<pair<int,int>,int> weights;
    map<pair<int,int>,int> :: iterator itr;
    pair<int,int> p;
    for(int i=1;i<=E;i++)
    {
        cin>>u>>v>>wt;  //u-->v
        p=make_pair(u,v);
        itr=weights.find(p);
        if(itr==weights.end())
        {
            adj_list[u].push_back(v);
            weights.insert(make_pair(make_pair(u,v),wt));
        }
        else
        {
            if((itr->second)>wt)
                itr->second=wt;
        }
    }
    //printGraph(adj_list,V+1);
    //for(itr=weights.begin();itr!=weights.end();itr++)
     //   cout<<(itr->first).first<<" - "<<(itr->first).second<<" "<<itr->second<<endl;

    BellmanFordShortestPath(V,weights,src);
  return 0;
}
inline void printPath(int parent[], int j){
    // Base Case : If j is source
    if (parent[j] == - 1)
        return;
    printPath(parent, parent[j]);
    cout<<j<<" ";
}
void BellmanFordShortestPath(int V,map<pair<int,int>,int> weights,int src)
{
    // Step 1: Initialize distances from src to all other vertices
    // as INFINITE
    int *dist=new int[V+1];
    fill(dist,dist+(V+1),INT_MAX);

    int *parent=new int[V+1];
    fill(parent,parent+(V+1),-1);

    dist[src]=0;

    map<pair<int,int>,int> :: iterator itr;
    int u,v,edge_wt;

    // Step 2: Relax all edges |V| - 1 times. A simple shortest
    // path from src to any other vertex can have at-most |V| - 1
    // edges
    for(int i=1;i<=V-1;i++)  //Relaxing V-1 times
    {
        for(itr=weights.begin();itr!=weights.end();itr++)
        {
            u=(itr->first).first;
            v=(itr->first).second;
            edge_wt=itr->second;
            if (dist[u] != INT_MAX && dist[u] + edge_wt < dist[v])
            {
                // update distance to the new lower value
                dist[v] = dist[u] + edge_wt;
                // set v's parent as u
                parent[v] = u;
            }
        }
    }
    // Step 3: check for negative-weight cycles.  The above step
    // guarantees shortest distances if graph doesn't contain
    // negative weight cycle.  If we get a shorter path, then there
    // is a cycle.
    for(itr=weights.begin();itr!=weights.end();itr++)
    {
        u=(itr->first).first;
        v=(itr->first).second;
        edge_wt=itr->second;
        if (dist[u] != INT_MAX && dist[u] + edge_wt < dist[v])
        {
            cout<<"Graph Contains a -ve cycle";
            return ;
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

    delete parent;
    delete dist;
    return;
}
/*
5 8
1 2 -1
1 3 4
2 3 3
2 4 2
2 5 2
4 2 1
4 3 5
5 4 -3  //change -3 => -10 for -ve cycle
     (  2  )
     ^ |\^  \
    /  | \\   \  2
 -1/   |  \\    \
  /    |   \\    \
(1)   3|    \\2   v
  \    |    1\\   (5)
  4\   |      \\   |
    \  |       \\  |-3
     v v        v\ v
     (3)<-------( 4 )
            5
*/
