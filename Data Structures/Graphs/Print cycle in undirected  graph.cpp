#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void printCycles(vector<vector<int>>& adj_list, int V);

void printGraph(vector<vector<int>> adj_list,int V){
    cout<<"Adjacency List:";
    for(int i=1;i<=V;i++)
    {
        cout<<"\nAdjacencies of "<<i<<" : ";
        for(int j=0;j<adj_list[i].size();j++)
            cout<<adj_list[i][j]<<" ";
    }
    cout<<"\n";
}
int main()
{
    int V,E,u,v;
    cin>>V>>E;
    vector<vector<int>> adj_list(V+1);
    for(int i=0; i<E; i++)
    {
        cin>>u>>v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    printGraph(adj_list,V);
    printCycles(adj_list,V);
    return 0;
}
/*bool dfs(int v, int par)   // passing vertex and its parent vertex
{
    visited[v] = true;
    for (int u : adj[v])
    {
        if(u == par)
            continue; // skipping edge to parent vertex
        if (visited[u])
        {
            cycle_end = v;
            cycle_start = u;
            return true;
        }
        parent[u] = v;
        if (dfs(u, parent[u]))
            return true;
    }
    return false;
}*/
void hasCycle_DFS(vector<vector<int>> adj_list, int vertex, vector<bool>& visited,vector<int>& parent, int &start, int &endi)
{
    if(start!=-1)
        return;

    visited[vertex]=true;
    cout<<vertex<<" ";
    for(int i: adj_list[vertex])
    {
        if(!visited[i])
        {
            parent[i]=vertex;
            hasCycle_DFS(adj_list,i,visited,parent,start,endi);
        }
        else if(parent[vertex]!=i)
        {
            start=vertex;
            endi=i;
            return;
        }
    }
}
void printCycles(vector<vector<int>>& adj_list, int V)
{
    vector<bool> visited(V+1,false);
    vector<int> parent(V+1,-1);
    //set<vector<int>> S;

    /*for (int i=1;i<=V;i++)
    {
        if (!visited[i])
        {
            if(hasCycle_DFS(adj_list, i, parent))

        }
    }

    if (cycle_start == -1)
    {
        cout << "Acyclic" << endl;
    }
    else
    {
        vector<int> cycle;
        cycle.push_back(cycle_start);
        for (int v = cycle_end; v != cycle_start; v = parent[v])
            cycle.push_back(v);
        cycle.push_back(cycle_start);
        reverse(cycle.begin(), cycle.end());

        cout << "Cycle found: ";
        for (int v : cycle)
            cout << v << " ";
        cout << endl;
    }*/
    int start=-1,endi;
    hasCycle_DFS(adj_list, 1, visited, parent, start,endi);
    /*cout<<"\n";
    for(int i=1;i<=V;i++)
        cout<<parent[i]<<" ";
    */cout<<"\n"<<endi<<"-"<<start<<endl;
    while(start!=endi){

        cout<<endi<<"-"<<parent[endi]<<"\n";
        endi=parent[endi];
    }
    //cout<<start;
}
/*
     1-----2
    /       \
   8---------3
   |         |
   |         |
   7---------4
    \       /
     6-----5
5 5
1 2
2 3
3 4
1 4
1 5

*/
