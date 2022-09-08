#include <iostream>
#include <vector>
using namespace std;
struct Edge
{
    int dest,cost;
};

void add_Edge(vector<vector<Edge>>& adj_list,int u,int v,int cos)
{
    adj_list[u].push_back({v,cos});
    adj_list[v].push_back({u,cos});
}

void printGraph(vector<vector<Edge>>& adj_list,int V)
{
    cout<<"Adjacency List: ";
    //as 0 is not considered as vertex
    for(int i=1;i<V;i++)
    {
        cout<<"\nAdjacencies of "<<i<<" :\n";
        for(int j=0;j<adj_list[i].size();j++)
            cout<<"("<<adj_list[i][j].dest<<", "<<adj_list[i][j].cost<<") ";
    }
}
int main()
{
    int V,E,u,v,cos;
    cin>>V>>E;
    vector<vector<Edge>> adj_list(V+1);
    //graph has vertexes numbered form 1 to V
    for(int i=1;i<=E;i++)
    {
        cin>>u>>v>>cos;
        add_Edge(adj_list,u,v,cos);
    }
    printGraph(adj_list,V+1);
  return 0;
}
