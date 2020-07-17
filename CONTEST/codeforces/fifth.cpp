#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
typedef long long int lli;

int topsort(vector<lli> &indegree, lli n, vector<lli> adj[], vector<lli> &ans)
{
    queue<lli> Q;
    for (lli i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
        {
            Q.push(i);
        }
    }
    lli visited = 0;
    while (!Q.empty())
    {
        lli x = Q.front();
        Q.pop();
        ans.push_back(x);
        visited++;
        for (auto i : adj[x])
        {
            indegree[i]--;
            if (indegree[i] == 0)
                Q.push(i);
        }
    }
    return visited;
}
int main()
{
    int t = 1;
    cin >> t;
    while (t--)
    {
        lli n, m;
        cin >> n >> m;
        vector<lli> adj[n];
        vector<pair<lli, lli>> edges;
        vector<lli> indegree(n, 0);
        for (int i = 0; i < m; i++)
        {
            int t, a, b;
            cin >> t >> a >> b;
            if (t)
            {
                adj[a - 1].push_back(b - 1);
                indegree[b - 1]++;
            }
            else
            {
                edges.push_back({a - 1, b - 1});
            }
        }
        vector<lli> toporder;
        lli visited = topsort(indegree, n, adj, toporder);
        if (visited != n)
        {
            cout << "NO" << endl;
            return 0;
        }
        unordered_map<lli, lli> mp;
        for (int i = 0; i < n; i++)
        {
            mp[toporder[i]] = i;
        }
        cout << "YES" << endl;
        for (auto r : edges)
        {
            if (mp[r.first] > mp[r.second])
            {
                cout << r.second + 1 << " " << r.first + 1 << endl;
            }
            else
            {
                cout << r.first + 1 << " " << r.second + 1 << endl;
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (auto j : adj[i])
            {
                cout << i + 1 << " " << j + 1 << endl;
            }
        }
    }
    return 0;
}