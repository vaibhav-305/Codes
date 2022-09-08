//for undirected graph only
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
using namespace std;

void DFS(vector<int> *,bool *,int);
void BFS(vector<int> *,bool *,int);

void print(vector<int> adj[],int v)
{
    cout<<"Adjacency List:--\n";
    for(int i=0;i<v;i++)
    {
        cout<<"\nAdjacencies of vertex "<<i<<":\n";
        for(int j=0;j<adj[i].size();j++)
            cout<<adj[i][j]<<" ";
    }
}
int main()
{
     int V,nv,inp,ini;
     cout<<"Enter no. of Vertices: ";
     cin>>V;
    // The below line may not work on all
    // compilers.  If it does not work on
    // your compiler, please replace it with
    // following
    // vector<int> *adj = new vector<int>[V];
    vector<int> adj[V];      //! array of vectors
    for(int i=0;i<V;i++)
    {
        cout<<"Enter no. of adjacencies for vertex "<<i<<": ";
        cin>>nv;
        if(nv!=0)
        {
            cout<<"Enter adjacencies:\n";
            for(int j=0;j<nv;j++)
            {
                cin>>inp;
                adj[i].push_back(inp);
            }
        }
        else
            adj[i].push_back(-1);    //in place of NULL we put -1
    }
    print(adj,V);
    bool *visited=new bool[V];
    for(int i=0;i<V;i++)
        visited[i]=false;
    cout<<"\n\nEnter initial node for DFS & BFS (0 to v-1): ";
    cin>>ini;
    cout<<"\nDFS:\n";
    DFS(adj,visited,ini);
    for(int i=0;i<V;i++)
        visited[i]=false;
    cout<<"\nBFS:\n";
    BFS(adj,visited,ini);
    delete visited;
  return 0;
}
void DFS(vector<int> adj[],bool *visited,int ini)
{
    vector<int> q;
    visited[ini]=true;
    cout<<ini<<" ";
    q=adj[ini];
    for(int i=0;i<q.size();i++)
    {
        if(visited[q[i]]==false)
            DFS(adj,visited,q[i]);
    }
}
void BFS(vector<int> adj[],bool *visited,int ini)
{
    int s;
    queue<int> Q;
    Q.push(ini);
    visited[ini]=true;
    vector<int> vec;
    while(!Q.empty())
    {
        s=Q.front();
        cout<<s<<" ";
        Q.pop();
        vec=adj[s];

        for (int i=0; i<vec.size();i++)
        {
            if(!visited[vec[i]])
            {
                visited[vec[i]]=true;
                Q.push(vec[i]);
            }
        }
    }

}
