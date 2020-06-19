#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>

using namespace std;
class graph{
    int V;
    unordered_set<int>* adjlist;
    public:
    graph(int v)
    {
        V=v;
        adjlist=new unordered_set<int>[v];
    }
    void buildgraph(int n);
};

void graph::buildgraph(int n)
{
    while(n--)
    {
        int a, b;
        cin>>a>>b;
        adjlist[a].insert(b);
    }
}

int main()
{
    int v;
    cin>>v;
    graph g(v);
    int n;
    cin>>n;
    g.buildgraph(n);
    int parent[v];
}