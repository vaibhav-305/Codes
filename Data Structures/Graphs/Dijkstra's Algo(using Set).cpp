#include <bits/stdc++.h>
using namespace std;
struct adjacency
{
    int dest,cost;
};
struct Edge
{
    int src,dest;
};

void add_Edge(vector<list<adjacency>>& adj_list,int u,int v,int cos)
{
    adj_list[u].push_back({v,cos});
    adj_list[v].push_back({u,cos});
}
void printGraph(vector<list<adjacency>> adj_list)
{
    cout<<"Adjacency List: ";
    //as 0 is not considered as vertex
    for(int i=1;i<adj_list.size();i++)
    {
        cout<<"\nAdjacencies of "<<i<<" :\n";
        for(auto j=adj_list[i].begin();j!=adj_list[i].end();j++)
            cout<<"("<<j->dest<<", "<<j->cost<<") ";
    }
    cout<<"\n";
}
int main()
{
    int V,E,u,v,cost;
    cin>>V>>E;
    vector<list<adjacency>> adj_list(V+1);
    for(int i=1;i<=E;i++)
    {
        cin>>u>>v>>cost;
        add_Edge(adj_list,u,v,cost);
    }
    printGraph(adj_list);
  return 0;
}
