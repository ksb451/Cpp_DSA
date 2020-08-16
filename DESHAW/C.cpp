#include <bits/stdc++.h>
using namespace std;
int dp[11][(1 << 10) + 1];
int target;

int rec(int curr, vector<vector<int>> &prices, int mask)
{
    if (mask == target)
    {
        return 0;
    }
    if (dp[curr][mask] != -1)
    {
        return dp[curr][mask];
    }
    else
    {
        int temp = 0;
        for (int i = 0; i < prices.size(); i++)
        {
            if (!(mask & (1 << i)))
            {
                temp = max(temp, prices[curr - 1][i] + rec(curr - 1, prices, (mask | (1 << i))));
            }
        }
        return dp[curr][mask] = temp;
    }
}

int maxprice(vector<vector<int>> prices)
{
    int n = prices.size();
    target = (1 << n) - 1;
    memset(dp, -1, sizeof(dp));
    return rec(n, prices, 0);
}