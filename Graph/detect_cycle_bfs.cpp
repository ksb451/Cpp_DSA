#include<bits/stdc++.h>
using namespace std;

bool bfscycle(vector<int>g[],int i, vector<bool>&visited,int V)
{
    visited[i]=true;
    queue<int>Q;
    Q.push(i);
    vector<int>parent(V,-1);
    while(Q.empty()==false)
    {
        int curr=Q.front();
        visited[curr]=true;
        Q.pop();
        for(auto j:g[curr])
        {
            if(visited[j]==false)
            {
                Q.push(j);
                parent[j]=curr;
            }
            else
            {
                if(j!=parent[curr])
                    return true;
            }
        }
    }
    return false;
}
bool isCyclic(vector<int> g[], int V)
{
    vector<bool>visited(V,false);
    for(int i=0;i<V;i++)
    {
        if(visited[i]==false)
        {
            if(bfscycle(g,i,visited,V))
                return true;
        }
    }
    return false;
   // Your code here
   
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int V, E;
        cin>>V>>E;
        
        // array of vectors to represent graph
        vector<int> adj[V];
        
        int u, v;
        for(int i=0;i<E;i++)
        {
            cin>>u>>v;
            
            // adding edge to the graph
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        cout << isCyclic(adj, V)<<endl;

    }
}
