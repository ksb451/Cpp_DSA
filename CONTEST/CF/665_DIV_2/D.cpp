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

vector<ll> adj[100005];
vector<pii> dp;
vector<bool> visited;
vector<ll> cnt;
ll dfs(ll curr)
{
    ll x = 1;
    visited[curr] = true;
    for (ll j : adj[curr])
    {
        if (visited[j] == false)
            x += dfs(j);
    }
    return cnt[curr] = x;
}

void solve()
{
    dp.clear();
    visited.clear();
    cnt.clear();
    ll n;
    cin >> n;
    for (ll i = 0; i < n + 2; i++)
    {
        adj[i].clear();
    }
    for (ll i = 0; i < n - 1; i++)
    {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
        dp.push_back({a, b});
    }
    ll m;
    cin >> m;
    vector<ll> arr(m);
    for (ll i = 0; i < m; i++)
        cin >> arr[i];
    visited = vector<bool>(n, false);
    cnt = vector<ll>(n, 0);
    dfs(0);
    vector<ll> val;
    for (auto i : dp)
    {
        ll x = min(cnt[i.first], cnt[i.second]);
        ll qw = x * (n - x);
        val.push_back(qw);
        //cout << x << " ";
    }
    //cout << endl;
    sort(all(val));
    sort(all(arr));
    ll ans = 0;
    if (m <= n - 1)
    {
        int x = n - 1 - m;
        for (int i = 0; i < x; i++)
        {
            ans += val[i];
            ans %= mod;
        }
        for (int i = 0; i < m; i++)
        {
            ll q = arr[i] * val[i + x];
            q %= mod;
            ans += q;
            ans %= mod;
        }
    }
    else
    {
        ll q = 1;
        for (int i = n - 2; i < m; i++)
        {
            q *= arr[i - 1];
            q %= mod;
        }
        arr.erase(arr.begin() + n - 2, arr.end());
        arr.push_back(q);
        for (int i = 0; i < n - 1; i++)
        {
            ll x = arr[i] * val[i];
            x %= mod;
            ans += x;
            ans %= mod;
        }
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