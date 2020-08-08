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
    int n;
    string a, b;
    cin >> n >> a >> b;
    bool flag = false;
    vector<int> adj[20];
    for (int i = 0; i < n; i++)
    {
        if (a[i] != b[i])
        {
            if (a[i] > b[i])
            {
                cout << "-1" << endl;
                return;
            }
            else
            {
                adj[a[i] - 'a'].push_back(b[i] - 'a');
                adj[b[i] - 'a'].push_back(a[i] - 'a');
            }
        }
    }
    vector<bool> visited(20, false);
    function<void(int)> dfs = [&](int u) {
        visited[u] = true;
        for (auto v : adj[u])
            if (!visited[v])
                dfs(v);
    };
    int ans = 20;
    for (int i = 0; i < 20; i++)
    {
        if (!visited[i])
        {
            //cout << i << " ";
            dfs(i);
            ans--;
        }
    }
    cout << ans << endl;
    return;
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