#include <iostream>
#include<stack>
#include<vector>
using namespace std;

vector <int> topoSort(int N, vector<int> adj[]);

//programm to check if topological sort is correct or not
bool check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;//add order of element in the topsort 
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return false;//check if en elment commin later is ancestor of the current node
        }
    }
    return true;
}

// Driver Code
int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }

        vector <int> res = topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
}// } Driver Code Ends


// The Graph structure is as folows

/*  Function which sorts the graph vertices in topological form
*   N: number of vertices
*   adj[]: input graph
*/
void toputil(vector<int>adj[],int curr, vector<bool>&visited, stack<int>&topsort)
{
    visited[curr]=true;
    for(auto j:adj[curr])
    {
        if(visited[j]==false)
            toputil(adj,j,visited,topsort);
    }
    topsort.push(curr);
    return;
}

vector<int> topoSort(int V, vector<int> adj[]) {
    
    stack<int>topsort;
    vector<bool>visited(V,false);
    for(int i=0;i<V;i++)
    {
        if(visited[i]==false)
            toputil(adj,i,visited,topsort);
    }
    vector<int>ans;
    while(!topsort.empty())
    {
        //cout<<topsort.top()<<" ";
        ans.push_back(topsort.top());
        topsort.pop();
    }
    return ans;
    // Your code here
}
