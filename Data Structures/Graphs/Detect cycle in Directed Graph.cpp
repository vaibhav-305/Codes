#include <iostream>
#include <vector>
using namespace std;

bool detect_cycle(vector<vector<int>> ,int );

void printGraph(vector<vector<int>> adj_list,int V)
{
    cout<<"Adjacency List:-";
    for(int i=1;i<=V;i++)
    {
        cout<<"\nAdjacencies of "<<i<<" :\n";
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
    for(int i=1;i<=E;i++)
    {
        cin>>u>>v;  //u-->v
        adj_list[u].push_back(v);
    }
    //printGraph(adj_list,V);
    if(detect_cycle(adj_list,V))
        cout<<"Cycle exists";
    else
        cout<<"Cycle doesn't exist";
  return 0;
}
bool DFS_hasCycle(vector<vector<int>> adj_list,int vertx,vector<int>& visited)
{
    if(visited[vertx]==-1)
    {
        // Mark the current node as visited and part of recursion stack
        visited[vertx]=0;

        for(int i:adj_list[vertx])
        {
            if(visited[i]==0)       //If the element is in the stack and it comes again, then its a cycle
                return true;
            else if(visited[i]==-1 && DFS_hasCycle(adj_list,i,visited))
                return true;
        }

    }
    //mark vertex visited and popped out of call-stack
    visited[vertx]=1;
    return false;
}
bool detect_cycle(vector<vector<int>> adj_list,int V)
{
    vector<int> visited(V+1,-1);
    //-1->unvisited
    // 0->visited and in call-stack
    // 1->visited and popped out of call-stack

    for(int i=1;i<=V;i++)
    {
        if(visited[i]==-1){
            if(DFS_hasCycle(adj_list,i,visited))
                return true;
        }
    }
    for(int i:visited)
        cout<<i<<" ";
    cout<<"\n";
    return false;
}
