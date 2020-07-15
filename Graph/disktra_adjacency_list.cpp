#include <iostream>
#include <vector>
#include <set>
#include <utility>
#include <climits>
#include <queue>
using namespace std;
typedef pair<int, int> ipair;

vector<int> disktra_2(vector<ipair> adj[], int V, int src)
{
    vector<int> dist(V, INT_MAX);
    priority_queue<ipair, vector<ipair>, greater<ipair>> pq;
    pq.push(make_pair(0, src));
    dist[src] = 0;
    while (pq.empty() == false)
    {
        int u = pq.top().second;
        pq.pop();
        for (auto j : adj[u])
        {
            int v = j.first;
            int w = j.second;
            if (dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
    return dist;
}

vector<int> disktra(vector<ipair> adj[], int V, int src)
{
    set<ipair> setds; //dist,node
    vector<int> dist(V, INT_MAX);
    setds.insert(make_pair(0, src));
    dist[src] = 0;
    while (setds.empty() == false)
    {
        ipair curr = *setds.begin();
        setds.erase(setds.begin());
        int u = curr.second;
        for (auto j : adj[u])
        {
            int v = j.first;
            int wt = j.second;
            if (dist[v] > dist[u] + wt)
            {
                dist[v] = dist[u] + wt;
                setds.insert(make_pair(dist[v], v));
            }
        }
    }
    return dist;
}

int main()
{
    int V;
    cin >> V;
    vector<ipair> adj[V];
    int n;
    cin >> n;
    while (n--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }
    int src;
    cin >> src;
    vector<int> ans = disktra(adj, V, src);
    vector<int> ans1 = disktra_2(adj, V, src);
    if (ans == ans1) //if both implemantation of algorithm give the same ans
    {
        cout << "success" << endl;
        return 0;
    }
    cout << "failed" << endl;
    return 0;
}