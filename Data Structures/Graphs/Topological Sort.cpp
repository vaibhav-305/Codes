/*Topological sorting for Directed Acyclic Graph (DAG) is a linear
ordering of vertices such that for every directed edge uv, vertex u
comes before v in the ordering. Topological Sorting for a graph is not
possible if  the graph is not a DAG.*/
#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <unordered_set>
using namespace std;

//void topologicalSortDFS(vector<vector<int>> ,int ,unordered_set<int>& ,list<int>& );
void DFS(vector<vector<int>> adj_list,int vertx,int visited[],list<int>& graphOrder);

void printGraph(vector<vector<int>> adj_list,int V){
    cout<<"Adjacency List:";
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
    int V,E,src,dest,vertx;
    cin>>V>>E;
    vector<vector<int>> adj_list(V+1);
    for(int i=1;i<=E;i++)
    {
        cin>>src>>dest;  //(src)--->(dest)
        adj_list[src].push_back(dest);
    }
    printGraph(adj_list,V);
    /*unordered_set<int> unvisited;
    for(int i=1;i<=V;i++)
        unvisited.insert(i);*/
    int *visited=new int[V+1];
    fill(visited,visited+(V+1),false);

    list<int> graphOrder;
    /*while(!unvisited.empty())
    {
        vertx=*(unvisited.begin());
        topologicalSort(adj_list,vertx,unvisited,graphOrder);
    }*/
    for(int i=1;i<=V;i++)
    {
        if(!visited[i])
            DFS(adj_list,i,visited,graphOrder);
    }
    for(auto itr=graphOrder.begin();itr!=graphOrder.end();itr++)
        cout<<*itr<<" ";
  return 0;
}
vector<int> v;
//void topologicalSortDFS(vector<vector<int>> adj_list,int vertx,unordered_set<int>& unvisited,list<int>& graphOrder)
void DFS(vector<vector<int>> adj_list,int vertx,int visited[],list<int>& graphOrder)
{
    //if(unvisited.empty())
      //  return ;

    //unvisited.erase(vertx); //set visited[vertx]=true
    visited[vertx]=true;
    v=adj_list[vertx];
    for(int i:v)
    {
        //if(unvisited.find(i)!=unvisited.end())
        if(!visited[i])
            DFS(adj_list,i,visited,graphOrder);
    }
    graphOrder.push_front(vertx);
}
/*
6 6
6 3
6 1
5 1
5 2
3 4
4 2

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
1 4 3 5 7 8 2 6
*/
