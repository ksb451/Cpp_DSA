#include <bits/stdc++.h>
using namespace std;
int dfs(int curr, int depth)
{
    visited[curr] = true;
    for (int j : adj[curr])
    {
        if (!visited[j])
        {
            depth = dfs(j, depth + 1);
        }
    }
    return depth;
}

vector<vector<int>> adj;
vector<bool> visited;
int solve(vector<int> p)
{
    int n = p.size();
    if (n == 1)
    {
        return -1;
    }
    adj = vector<vector<int>>(n);
    for (int i = 0; i < n; i++)
    {
        adj[p[i] - 1].push_back(i);
    }
    visited = vector<bool>(n, false);
    vector<int> cycles;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            int x = dfs(i, 1);
            cycles.push_back(x);
        }
    }
    sort(cycles.rbegin(), cycles.rend());
    int first = cycles[0];
    int next = (first + 1) / 2;
    if (cycles.size() == 1)
    {
        return next;
    }
    int second = cycles[1];
    if (max(next, second) == first)
    {
        return -1;
    }
    return max(next, second);
}