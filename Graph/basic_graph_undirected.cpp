#include <iostream>
#include <vector>
#include <list>
using namespace std;

//bfs of an undirected or directed graph
vector<int> bfs(vector<int> adj[], int N)
{
    vector<int> ans;
    vector<int> parent(N, -1); //can use this parent to calculate the pathh.
    list<int> queue;
    queue.push_back(0);
    parent[0] = 0;
    while (queue.empty() == false)
    {
        int s = queue.front();
        ans.push_back(s);
        queue.pop_front();
        for (auto i : adj[s])
        {
            if (parent[i] == -1)
            {
                parent[i] = s;
                queue.push_back(i);
            }
        }
    }
    return ans;
    // Your code here
}

//utility function for depth first search
void dfsutil(vector<int> g[], vector<int> &ans, int i, vector<bool> &visited)
{
    visited[i] = true;
    ans.push_back(i);
    for (auto j : g[i])
    {
        if (visited[j] == false)
        {
            dfsutil(g, ans, j, visited);
        }
    }
}
vector<int> dfs(vector<int> g[], int N)
{
    vector<int> ans;
    vector<bool> visited(N, false); //to keep track of visited node
    for (int i = 0; i < N; i++)
    {
        if (visited[i] == false)
        {
            dfsutil(g, ans, i, visited);
        }
    }
    return ans;
    // Your code here
}

void build_graph(vector<int> adj[], vector<vector<int>> &adm, int v, int n) //undirected
{
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        if (a >= v || b >= v)
        {
            cout << "invalid" << endl;
            i--;
            continue;
        }
        adj[a].push_back(b);
        //adj[b].push_back(a);//comment this line to make it a directed graph;
        adm[a][b] = 1;
        //adm[b][a]=1;//comment this line to make it a directed graph
    }
}

int main()
{
    int v;
    cin >> v;
    vector<int> adj[v];
    vector<vector<int>> adm(v, vector<int>(v, 0));
    int n;
    cin >> n;
    build_graph(adj, adm, v, n);
    vector<int> bfs_traverse = bfs(adj, v);
    vector<int> dfs_traverse = dfs(adj, v);
    for (int i = 0; i < bfs_traverse.size(); i++)
    {
        cout << bfs_traverse[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < dfs_traverse.size(); i++)
    {
        cout << dfs_traverse[i] << " ";
    }
    cout << endl;
}