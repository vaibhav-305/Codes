//Time Complexity: O(E*log(V))
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
using namespace std;
struct adjacency
{
    int dest,cost;
};
struct Edge
{
    int u, v;
};

vector<vector<adjacency>> KruskalMST(vector<vector<adjacency>>);

void add_Edge(vector<vector<adjacency>>& adj_list,int u,int v,int cos)
{
    adj_list[u].push_back({v,cos});
    adj_list[v].push_back({u,cos});
}
void printGraph(vector<vector<adjacency>> adj_list)
{
    cout<<"Adjacency List: ";
    //as 0 is not considered as vertex
    for(int i=1;i<adj_list.size();i++)
    {
        cout<<"\nAdjacencies of "<<i<<" :\n";
        for(int j=0;j<adj_list[i].size();j++)
            cout<<"("<<adj_list[i][j].dest<<", "<<adj_list[i][j].cost<<") ";
    }
    cout<<"\n";
}
int main()
{
    int V,E,u,v,cos;
    cin>>V>>E;
    vector<vector<adjacency>> adj_list(V+1);
    //graph has vertexes numbered form 1 to V
    for(int i=1;i<=E;i++)
    {
        cin>>u>>v>>cos;
        add_Edge(adj_list,u,v,cos);
    }
    printGraph(adj_list);
    vector<vector<adjacency>> MSTadj_list=KruskalMST(adj_list);
    printGraph(MSTadj_list);
  return 0;
}

char itochar(int a){
    char k=(char)(a+48);
    return k;
}
string stringMaker(int u,int v){
    string s;
    int rem=0;
    while(u)
    {
        rem=u%10;
        s.push_back(itochar(rem));
        u=u/10;
    }
    s.push_back('-');
    while(v)
    {
        rem=v%10;
        s.push_back(itochar(rem));
        v=v/10;
    }
    return s;
}
vector<pair<int,Edge>>  getEdgeList(vector<vector<adjacency>> adj_list){
    vector<pair<int,Edge>> edge_list;
    unordered_map<string,int> VisitedEdge; //stores egde info and its index in edge_list
    int cos,indx;
    Edge e;
    vector<adjacency> q;
    string s;
    for(int i=1;i<adj_list.size();i++)
    {
        q=adj_list[i];
        for(int j=0;j<q.size();j++)
        {
            if(i<q[j].dest)
            {
                e.u=i;
                e.v=q[j].dest;
            }
            else
            {
                e.u=q[j].dest;
                e.v=i;
            }
            cos=q[j].cost;
            if(e.u!=e.v)
            {
                s=stringMaker(e.u,e.v);
                if(VisitedEdge.find(s)==VisitedEdge.end())
                {
                    edge_list.push_back({cos,e});
                    VisitedEdge.insert(pair<string,int> (s,edge_list.size()-1));
                }
                else
                {
                    indx=VisitedEdge[s];
                    if(cos<edge_list[indx].first)
                        edge_list[indx].first=cos;
                }
            }
        }
    }
    return edge_list;
}
bool comp(pair<int,Edge> a,pair<int,Edge> b){
    return (a.first<b.first);
}
int Find(int disj[], int i){
    // find root and make root as parent of i
    // (path compression)
    if(disj[i]<0)
        return i;

    disj[i]=Find(disj,disj[i]);
    return disj[i];
}
void Union(int *disj,int parU,int parV){
    int rankU=abs(disj[parU]);
    int rankv=abs(disj[parV]);

    if(rankU<rankv)
    {
        disj[parV]+=disj[parU];
        disj[parU]=parV;
    }
    else
    {
        disj[parU]+=disj[parV];
        disj[parV]=parU;
    }
}
vector<vector<adjacency>> KruskalMST(vector<vector<adjacency>> adj_list)
{
    vector<pair<int,Edge>> edge_list=getEdgeList(adj_list); //returns edge list removes self loops and resolve parallel edges
    sort(edge_list.begin(),edge_list.end(),comp);
    for(int i=0;i<edge_list.size();i++)
        cout<<edge_list[i].first<<", "<<(edge_list[i].second).u<<", "<<(edge_list[i].second).v<<endl;
    int *disjointSet=new int[adj_list.size()];
    fill(disjointSet,disjointSet+adj_list.size(),-1);
    cout<<endl;
    int cos;
    Edge e;
    int parU,parV;
    vector<vector<adjacency>> MSTadj_list(adj_list.size());
    for(int i=0;i<edge_list.size();i++)
    {
        cos=edge_list[i].first;
        e=edge_list[i].second;
        parU=Find(disjointSet,e.u);
        parV=Find(disjointSet,e.v);
        if(parU!=parV)
        {
            add_Edge(MSTadj_list,e.u,e.v,cos);
            Union(disjointSet,parU,parV);
        }
    }
    delete disjointSet;
    return MSTadj_list;
}
/*
Dataset with self loop and a parallel edge:
6 11
1 2 2
1 3 1
2 3 3
2 4 5
3 5 6
3 4 3
3 5 3
4 5 8
4 6 4
5 6 1
6 6 3
           5
   (2)------------(4)
   /|             /|\
2 / |           /  | \ 4  ___
 /  |         /    |  \  /   |
(1) |3     3/     8|   (6)   |3
 \  |     /        |   / \___|
1 \ |   /          |  /1
   \| /     6      | /
   (3)------------(5)
     \            /
      \__________/
            3
*/
