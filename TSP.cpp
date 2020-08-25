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

public:
    TSP(long long int n)
    {
        N = n;
        limit = ((1 << N) - 1);
        adj = vector<vector<long long int>>(N, vector<long long int>(N, INT_MAX));
        dp = vector<vector<long long int>>(N, vector<long long int>(limit, -1));
    }

    void add_path(int a, int b, int c)
    {
        adj[a][b] = c;
    }

    void solve()
    {
        long long int ans = rec(0, 1);
        //cout << limit << endl;
        cout << "MIN COST OF PATH IS : " << ans << endl;
        return;
    }

    int rec(long long int curr, long long int mask)
    {
        if (mask == limit)
        {
            return adj[curr][0];
        }
        else if (dp[curr][mask] != -1)
        {
            return dp[curr][mask];
        }
        else
        {
            long long int ans = INT_MAX;
            for (int i = 0; i < N; i++)
            {
                if (i == curr)
                {
                    continue;
                }
                if ((((1 << i) & mask) == 0) && adj[curr][i] != INT_MAX)
                {
                    ans = min(ans, adj[curr][i] + rec(i, (mask | (1 << i))));
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