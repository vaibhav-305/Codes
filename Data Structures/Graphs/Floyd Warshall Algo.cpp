/*
-> It is an all-pair shortest path algorithm i.e. it finds shortest path of
   all vertices to all vertices .
-> It works with adjacency matrix only.
-> Works for both directed as well as undirected graph with non -ve weight cycle
-> T.C.=O(V*V*V)
*/
//!  Here implemented for directed weighted graph.
#include <iostream>
#include <vector>
#define INF INT_MAX
using namespace std;

void FWAShortestPaths(vector<vector<int>> ,int );

void printGraph(vector<vector<int>> adj_matrix,int V)
{
    cout<<"Adjacency List:\n";
    for(int i=1;i<=V;i++)
    {
        for(int j=1;j<=V;j++){
            if(adj_matrix[i][j]==INT_MAX)
                cout<<"INF"<<"\t";
            else
                cout<<adj_matrix[i][j]<<"\t";
        }
        cout<<"\n";
    }
}
int main()
{
    int V,E,u,v,wt;
    cin>>V>>E;
    vector<vector<int>> adj_matrix(V+1,vector<int> (V+1,INT_MAX));
    for(int i=1;i<=V;i++)
        adj_matrix[i][i]=0;
    for(int i=1;i<=E;i++)
    {
        cin>>u>>v>>wt;
        if(u!=v && wt<adj_matrix[u][v])
            adj_matrix[u][v]=wt;
    }
    //printGraph(adj_matrix,V);
    FWAShortestPaths(adj_matrix,V);
  return 0;
}
inline void printPath(vector<vector<int>> parent, int i, int j){
    if (parent[i][j] == i)
        return;

    printPath(parent, i, parent[i][j]);
    cout << parent[i][j] << " ";
}
void FWAShortestPaths(vector<vector<int>> adj_matrix,int V)
{
    int dist[V+1][V+1];
    vector<vector<int>> parent(V+1,vector<int> (V+1,-1));
    //!initialize
    //If the path exists between two nodes then parent[u][v] = u else we set parent[u][v] = -1
    //
    for(int i=1;i<=V;i++)
    {
        for(int j=1;j<=V;j++)
        {
            dist[i][j]=adj_matrix[i][j];

            if(adj_matrix[i][j]!=INT_MAX)
                parent[i][j]=i;
            else
                parent[i][j]=-1;
        }
    }
    //!Run Floyd Warshall Algo
    //
    for(int k=1;k<=V;k++)
    {
        for(int i=1;i<=V;i++)
        {
            for(int j=1;j<=V;j++)
            {
                // We cannot travel through
                // edge that doesn't exist
                if(dist[i][k] == INF  || dist[k][j] == INF)
                    continue;

                if(dist[i][j]>dist[i][k]+dist[k][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    parent[i][j] = parent[k][j];
                }
            }
            // if diagonal elements become negative, the
            // graph contains a negative weight cycle
            if (dist[i][i] < 0)
            {
                cout << "Negative Weight Cycle Found!!";
                return;
            }

        }
    }
    cout<<"Output:\n";
    cout<<"Vertex\t\tDistance\tPath\n";
    for(int i=1;i<=V;i++)
    {
        for(int j=1;j<=V;j++)
        {
            if(i!=j && parent[i][j]!=-1){
                printf("%d -> %d \t\t %d\t\t%d ",
                      i, j, dist[i][j], i);
                printPath(parent,i,j);
                cout<<j<<"\n";
            }
        }
    }
}
/*
dataset:
4 8
2 1 8
1 2 3
1 4 7
2 3 2
3 1 5
4 1 2
3 4 1
3 1 8 //Parallel edge

     _____8_____>
( 1 )<----------(2)
 ^ |^      3     |
 | | \           |
 | |   \         |
7| |    5\       |2
 | |2      \     |
 | |         \   |
 | V           \ V
( 4 )<----------(3)
   ^      1     /
    \__________/
          6

dataset 2:
4 5
1 3 -2
2 1 4
2 3 3
3 4 2
4 2 -1

       4
(1)<---------( 2 )
  \          ^ |
   \        /  |
  -2\    -1/   |
     \    /    |
      \  /     |
       \/      |3
       /\      |
      /  \     |
     /    \    |
    /      \   |
   /        \  |
  /    2     v V
(4)<--------( 3 )

*/
