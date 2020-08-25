#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cout.tie(NULL);                   \
    cin.tie(NULL);

#define IN cin >>
#define OUT cout <<
#define nl "\n"
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define write(a)          \
    for (auto x : a)      \
    {                     \
        cout << x << " "; \
    }                     \
    cout << nl;
#define read(a)       \
    for (auto &x : a) \
    {                 \
        cin >> x;     \
    }
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")

using ll = long long int;
using ld = long double;
using pll = pair<ll, ll>;
using pii = pair<int, int>;
using vll = vector<ll>;
using vi = vector<int>;
const ll mod = (ll)(1e9) + 7LL;
const ll M = 988244353LL;

int dp[3002][3002];
vector<int> loc[3003];
int count(int a, int i, int j)
{
    return dp[a][j] - dp[a][i - 1];
}

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < 3003; i++)
    {
        loc[i].clear();
    }
    for (int i = 0; i < n; i++)
    {
        dp[arr[i]][i] = 1;
        loc[arr[i]].push_back(i);
    }
    for (int i = 0; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dp[i][j] += dp[i][j - 1];
        }
    }
    int ans = 0;
    for (int i = 0; i < 3003; i++)
    {
        if (loc[i].size() >= 2)
        {
            int nn = loc[i].size();
            for (int ii = 0; ii < nn; ii++)
            {
                for (int jj = ii + 1; jj < nn; jj++)
                {
                    int x = loc[i][ii];
                    int y = loc[i][jj];
                    for (int k = x + 1; k < y; k++)
                    {
                        // if (count(arr[k], y + 1, n - 1) > 0)
                        // {
                        //     cout << arr[k] << " " << x << " " << y << endl;
                        // }
                        ans += count(arr[k], y + 1, n - 1);
                    }
                }
            }
        }
    }
    cout << ans << endl;
}

int main()
{
    fast;
    ll tc = 1;
    IN tc;
    while (tc--)
    {
        solve();
    }
    return 0;
}