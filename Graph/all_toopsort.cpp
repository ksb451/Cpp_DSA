#include<vector>
#include<queue>
#include<iostream>
using namespace std;

class Graph{
    int V;
    vector<int>* adj;
    vector<int>in_degree;
    void topsortutil(vector<vector<int>>&ans,vector<int>&,vector<int>&);
    public:
    Graph(int v)
    {
        V=v;
        adj=new vector<int>[v];
        in_degree=vector<int>(v,0);
    }
    void add_edge(int a,int b){
        adj[a].push_back(b);
        in_degree[b]++;
    }
    vector<vector<int>> alltopsort();
    ~Graph()//destructor
    {
        delete adj;
    }
};

void Graph::topsortutil(vector<vector<int>>&ans,vector<int>&cur, vector<int>&visited)
{
    bool flag=false;
    for(int i=0;i<V;i++)
    {
        if(in_degree[i]==0&&visited[i]==false)
        {
            for(auto j:adj[i])
            {
                in_degree[j]--;
            }
            cur.push_back(i);
            visited[i]=true;
            topsortutil(ans,cur,visited);
            visited[i]=false;
            cur.erase(cur.end()-1);
            for(auto j:adj[i])
            {
                in_degree[j]++;
            }
            flag=true;
        }
    }
    if(flag==false)
    {
        ans.push_back(cur);
    }
}

vector<vector<int>> Graph::alltopsort()
{
    vector<vector<int>>ans;
    vector<int>visited(V,0);
    vector<int>cur;
    topsortutil(ans,cur,visited);
    return ans;
}