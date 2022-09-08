#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool isBipartite(vector<vector<int>> , int );

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

    cout<<isBipartite(adj_list, V);
    return 0;
}
bool isBipartite(vector<vector<int>> adj_list, int V)
{
    if(V < 3)         //graph having number of vertices < 3 will be bipartite
        return true;

    //Doing BFS                               //we choose red and blue color for coloring
    vector<char> color(V+1,'n');              // n->not colored
    queue<int> Q;                             // r->red colored
    Q.push(1);                                // b->blue colored
    color[1]='r';
    int temp;
    while(!Q.empty())
    {
        temp=Q.front();
        Q.pop();
        for(int vrtx: adj_list[temp])
        {
            if(color[vrtx]=='n'){
                Q.push(vrtx);
                if(color[temp]=='r') color[vrtx]='b';
                else if(color[temp]=='b') color[vrtx]='r';
            }
            else if(color[temp]==color[vrtx])
                return false;
        }
    }
    return true;
}
/*
    1---2
    |\  |
    | \ |          Not Bipartite
    |  \|
    4---3

    1---2
    |   |          Bipartite
    |   |
    4---3
*/
