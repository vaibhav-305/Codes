#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool detectCycle(vector<vector<int>> adj_list,int V);

int main()
{
    int V,E,u,v;
    cin>>V>>E;
    vector<vector<int>> adj_list(V+1);
    for(int i=0;i<E;i++)
    {
        cin>>u>>v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    cout<<detectCycle(adj_list,V);
  return 0;
}
bool hasCycle_BFS(vector<vector<int>> adj_list,int start,vector<bool>& visited)
{
    //Applying BFS
    queue<pair<int,int>> Q;
    Q.push({start,-1});       //storing element and its parent
    visited[start]=true;
    pair<int,int> temp;
    while(!Q.empty())
    {
        temp=Q.front();
        Q.pop();

        for(int v: adj_list[temp.first])
        {
            if(!visited[v]){
                Q.push({v,temp.first});
                visited[v]=true;
            }
            else{
                if(v!=temp.second)       //if v is visited and v is not parent then that means there is cycle
                    return true;
            }
        }
    }
    return false;
}
void DFS(vector<vector<int>>& adj,vector<bool>& visited,int vrtx,int prev,bool &verdict){
    if(verdict)
        return;
    visited[vrtx]=true;
    for(int i:adj[vrtx]){
        if(visited[i] && i!=prev){
            verdict= true;
            return;
        }
        if(!visited[i])
            DFS(adj,visited,i,vrtx,verdict);
    }
}
bool detectCycle(vector<vector<int>> adj,int V)
{
    vector<bool> visited(V+1,false);
    // With BFS
    for(int i=1;i<=V;i++)              //we did this so that is graph have non-connected components then we can traverse through all those components
    {
        if(!visited[i])
        {
            if(hasCycle_BFS(adj,i,visited))
                return true;
        }
    }
    /*  With DFS
    bool verdict=false;
    for(int i=1;i<=V;i++){
        if(!visited[i]){
            DFS(adj,visited,i,-1,verdict);
            if(verdict)
                return 1;
        }
    }*/
    return false;
}
