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
//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
//#pragma GCC optimization("unroll-loops")

using ll = long long int;
using ld = long double;
using pll = pair<ll, ll>;
using pii = pair<int, int>;
using vll = vector<ll>;
using vi = vector<int>;
const ll mod = (ll)(1e9) + 7LL;
const ll M = 988244353LL;

int dp[3002][3002];
int next_count(int a, int i, int n)
{
    return dp[a][n - 1] - dp[a][i - 1];
}

int prev_count(int a, int i)
{
    return dp[a][i - 1];
}

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; i++)
    {
        dp[arr[i]][i] = 1;
    }
    for (int i = 0; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dp[i][j] += dp[i][j - 1];
        }
    }
    long long int ans = 0;
    for (int i = 1; i < n - 2; i++)
    {
        for (int j = i + 1; j < n - 1; j++)
        {
            ans += (prev_count(arr[j], i) * next_count(arr[i], j + 1, n));
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