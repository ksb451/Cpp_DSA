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
using ll = long long int;
using ld = long double;
using pll = pair<ll, ll>;
using pii = pair<int, int>;
using vll = vector<ll>;
using vi = vector<int>;
const ll mod = (ll)(1e9) + 7LL;
const ll M = 988244353LL;

void solve()
{
    ll n, k;
    cin >> n >> k;
    ll a[n + 1];
    unordered_map<ll, ll> mp;
    ll ans = 0;
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    ll mat[n + 1][n + 1];
    memset(mat, 0, sizeof(mat));
    for (ll i = 0; i < n; i++)
    {
        mp.clear();
        for (ll j = i; j < n; j++)
        {
            mat[i][j] = (j == 0) ? 0 : mat[i][j - 1];
            if (mp.count(a[j]))
            {
                if (mp[a[j]] == 1)
                {
                    mat[i][j]++;
                }
                mat[i][j]++;
            }
            mp[a[j]]++;
        }
    }
    ans = 1e18;
    ll table = 100;
    ll dp[101][1001] = {0};
    memset(dp, 0, sizeof(dp));
    for (ll i = 1; i < n + 1; i++)
    {
        dp[1][i] = mat[0][i - 1];
    }
    for (ll i = 2; i <= table; i++)
    {
        for (ll j = 2; j <= n; j++)
        {
            ll best = 1e18;
            for (ll p = 1; p < j; p++)
            {
                best = min(best, dp[i - 1][p] + mat[p][j - 1]);
            }
            dp[i][j] = best;
        }
    }
    for (table = 1; table <= 100; table++)
    {
        ans = min(table * k + dp[table][n], ans);
    }
    cout << ans << endl;
}

int main()
{
    ll tc = 1;
    IN tc;
    while (tc--)
    {
        solve();
    }
    return 0;
}