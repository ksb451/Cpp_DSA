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

pii bfs(vector<int> adj[], int n, int start)
{
    vector<bool> visited(n, false);
    queue<int> Q;
    Q.push(start);
    visited[start] = true;
    int lvl = 0;
    int next = start;
    while (!Q.empty())
    {
        int q = Q.size();
        while (q--)
        {
            int curr = Q.front();
            Q.pop();
            next = curr;
            for (int j : adj[curr])
            {
                if (!visited[j])
                {
                    visited[j] = true;
                    Q.push(j);
                }
            }
        }
        lvl++;
    }
    return {lvl, next};
}

void solve()
{
    int n;
    cin >> n;
    vector<int> adj[n];
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    pii next = bfs(adj, n, 0);
    //cout << next.first << " " << next.second << endl;
    pii ans = bfs(adj, n, next.second);
    //cout << ans.first << " " << ans.second << endl;
    cout << (ans.first - 1) * 3 << endl;
}

int main()
{
    fast;
    ll tc = 1;
    //IN tc;
    while (tc--)
    {
        solve();
    }
    return 0;
}