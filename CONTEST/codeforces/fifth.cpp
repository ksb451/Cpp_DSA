#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
int main()
{
    int ts = 1;
    cin >> ts;
    while (ts--)
    {
        int n, m;
        cin >> n >> m;
        vector<int> adj[n + 1];
        vector<pair<int, int>> edges(m + 1);
        vector<bool> dir(m + 1);
        vector<int> indegree(n + 1, 0);
        for (int i = 1; i <= m; i++)
        {
            int t, a, b;
            cin >> t >> a >> b;
            if (t)
            {
                adj[a].push_back(b);
                indegree[b]++;
            }
            dir[i] = (t == 0);
            edges[i] = {a, b};
        }
        vector<int> toporder(n + 1, 0);
        queue<int> Q;
        for (int i = 1; i <= n; i++)
        {
            if (indegree[i] == 0)
            {
                Q.push(i);
            }
        }
        int timer = 0;
        while (!Q.empty())
        {
            int x = Q.front();
            Q.pop();
            timer++;
            toporder[x] = timer;
            for (auto i : adj[x])
            {
                indegree[i]--;
                if (indegree[i] == 0)
                    Q.push(i);
            }
        }
        if (timer != n)
        {
            cout << "NO" << endl;
            return 0;
        }
        cout << "YES" << endl;
        for (int i = 0; i < edges.size(); i++)
        {
            if (dir[i])
            {
                if (toporder[edges[i].first] > toporder[edges[i].second])
                {
                    swap(edges[i].first, edges[i].second);
                }
            }
        }
        for (int i = 1; i <= m; i++)
        {
            cout << edges[i].first << " " << edges[i].second << endl;
        }
    }
    return 0;
}