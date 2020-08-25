#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

#define MAX = 1000000;

class TSP
{
private:
    long long int N;
    long long int limit;
    vector<vector<long long int>> adj;
    vector<vector<long long int>> dp;
    vector<vector<long long int>> parent;

public:
    TSP(long long int n)
    {
        N = n;
        limit = ((1 << N) - 1);
        adj = vector<vector<long long int>>(N, vector<long long int>(N, INT_MAX));
        dp = vector<vector<long long int>>(N, vector<long long int>(limit + 1, -1));
        parent = vector<vector<long long int>>(N, vector<long long int>(limit + 1, -1));
    }

    void add_path(int a, int b, int c)
    {
        adj[a][b] = c;
    }

    void solve()
    {
        long long int ans = rec(0, 1);

        cout << "MIN COST OF PATH IS : " << ans << endl;

        vector<int> path(N);

        int curr_mask = 1;
        path[0] = parent[0][curr_mask];
        curr_mask = (curr_mask | (1 << path[0]));
        int curr_node = path[0];
        while (curr_node != 0)
        {
            path[curr_node] = parent[curr_node][curr_mask];
            curr_mask = (curr_mask | (1 << path[curr_node]));
            curr_node = path[curr_node];
        }

        curr_node = 0;
        do
        {
            cout << path[curr_node] << " ";
            curr_node = path[curr_node];
        } while (curr_node != 0);
        cout << endl;

        return;
    }

    int rec(long long int curr, long long int mask)
    {
        if (mask == limit)
        {
            parent[curr][mask] = 0LL;
            return adj[curr][0];
        }
        else if (dp[curr][mask] != -1)
        {
            return dp[curr][mask];
        }
        else
        {
            long long int ans = INT_MAX;
            for (long long int i = 0; i < N; i++)
            {
                if (i == curr)
                {
                    continue;
                }
                if ((((1 << i) & mask) == 0) && adj[curr][i] != INT_MAX)
                {
                    long long int cur_value = adj[curr][i] + rec(i, mask | (1 << i));
                    if (ans > cur_value)
                    {
                        ans = cur_value;
                        parent[curr][mask] = i;
                    }
                }
            }
            return dp[curr][mask] = ans;
        }
    }
};

int main()
{
    long long int n;
    cin >> n;
    TSP tsp = TSP(n);
    long long int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        tsp.add_path(a, b, c);
    }
    tsp.solve();
    return 0;
}