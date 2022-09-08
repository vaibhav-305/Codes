/*
works on DAG only
For Lexicographically Smallest Topological Ordering T.C.=O(V*log(V)+E)
For Normal TopSort T.C.=O(V+E)
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void kahnTopSort(vector<vector<int>> ,int );

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
    kahnTopSort(adj_list,V);
  return 0;
}
void kahnTopSort(vector<vector<int>> adj_list,int V)
{
    //! Step 1:find in-degree(incoming edges) for each vertex
    // Traverse adjacency lists to fill in-degrees of vertices
    // This step takes O(V+E) time
    int *inDegree=new int[V+1];
    fill(inDegree,inDegree+(V+1),0);
    for(int i=1;i<=V;i++)
    {
        for(int j=0;j<adj_list[i].size();j++)
            inDegree[adj_list[i][j]]++;
    }
    //! Step 2: create a queue, push all the elements having 0 inEdges into queue
    // For Lexicographically Smallest Topological Ordering use set/priority queue
    priority_queue<int,vector<int>,greater<int>> Q;
    for(int i=1;i<=V;i++)
    {
        if(inDegree[i]==0)
            Q.push(i);
    }
    vector<int> topSortOrder;

    // Initialize count of visited vertices
    int cnt = 0;

    int vertx;

    //! Step 3: One by one pop vertices from queue and insert adjacents if indegree of adjacent becomes 0
    //Basically BFS
    while(!Q.empty())
    {
        vertx=Q.top();
        Q.pop();
        topSortOrder.push_back(vertx);

        // Iterate through all the neighbouring nodes
        // of poped node and decrease their in-degree
        // by 1
        for(int i:adj_list[vertx])
        {
            inDegree[i]--;
            // If in-degree becomes zero, add it to queue
            if(inDegree[i]==0)
                Q.push(i);
        }
        cnt++;
    }
     // Check if there was a cycle
    if (cnt != V) {
        cout << -1;
        delete inDegree;
        return;
    }

    cout<<"Output:\n";
    for(int i:topSortOrder)
        cout<<i<<" ";

    delete inDegree;
    return ;
}
/*
8 9
1 4
1 2
4 2
4 3
3 2
5 2
3 5
8 2
8 6
Lexicographically Smallest Topological Ordering: 1 4 3 5 7 8 2 6
*/
