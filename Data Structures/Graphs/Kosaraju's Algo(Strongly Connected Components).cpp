//T.C.=O(V+E) :3 Traversals
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void KosarajuSCC(vector<vector<int>> ,int );
void DFS_I(vector<vector<int>> adj_list,int vertx,bool visited[],stack<int>& S);
void DFS_II(vector<vector<int>> adj_list,int vertx,bool visited[],vector<int>& vec);

void printGraph(vector<vector<int>> adj_list,int V)
{
    cout<<"\nAdjacency List:-";
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
    KosarajuSCC(adj_list,V);
  return 0;
}
void showStack(stack<int> S){
    while(!S.empty()){
        cout<<S.top()<<" ";
        S.pop();
    }
    cout<<"\n";
}
void KosarajuSCC(vector<vector<int>> adj_list,int V)
{
    bool *visited=new bool[V+1];
    fill(visited,visited+(V+1),false);

    stack<int> S;

    vector<vector<int>> SCC; ///ans

    /// Step 1: DFS
    //Create an empty stack ‘S’ and do DFS traversal of a graph. In DFS
    //traversal, after calling recursive DFS for adjacent vertices of a
    //vertex, push the vertex to stack.
    for(int i=1;i<=V;i++)
    {
        if(!visited[i])
            DFS_I(adj_list,i,visited,S);
    }
    //showStack(S);

    /// Step 2: Reversing all edges of graph
    //Reverse directions of all arcs to obtain the transpose graph.
    vector<vector<int>> reverseGraph(V+1);
    for(int u=1;u<=V;u++)
    {
        for(int v=adj_list[u].size()-1;v>=0;v--)
        {
            reverseGraph[adj_list[u][v]].push_back(u);
            adj_list[u].pop_back();
        }
    }
    adj_list.clear();
    //printGraph(reverseGraph,V);

    /// Step 3: DFS
    // One by one pop a vertex from S while S is not empty. Let the popped vertex
    //be ‘v’. Take v as source and do DFS (call DFS_II(v)). The DFS starting from v
    //prints strongly connected component of v
    fill(visited,visited+(V+1),false);
    int vertx;
    vector<int> vec;
    while(!S.empty())
    {
        vertx=S.top();
        S.pop();
        if(!visited[vertx]){
            vec.push_back(vertx);
            DFS_II(reverseGraph,vertx,visited,vec);
            SCC.push_back(vec);
            vec.clear();
        }
    }
    cout<<"Strongly Connected Components:\n";
    for(int i=0;i<SCC.size();i++)
    {
        for(int j:SCC[i])
            cout<<j<<" ";
        cout<<"\n";
    }
    delete visited;
}
void DFS_I(vector<vector<int>> adj_list,int vertx,bool visited[],stack<int>& S)
{
    visited[vertx]=true;
    for(int v:adj_list[vertx])
    {
        if(!visited[v])
            DFS_I(adj_list,v,visited,S);
    }
    S.push(vertx);
}
void DFS_II(vector<vector<int>> adj_list,int vertx,bool visited[],vector<int>& vec)
{
    visited[vertx]=true;
    for(int v:adj_list[vertx])
    {
        if(!visited[v]){
            vec.push_back(v);
            DFS_II(adj_list,v,visited,vec);
        }
    }
}
/*
11 13
1 2
2 3
2 4
3 1
4 5
5 6
6 4
7 6
7 8
8 9
9 10
10 7
10 11

dataset 2:
7 10
1 2
2 3
2 4
4 5
5 1
5 6
5 7
6 3
6 7
7 6
*/
