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

vector<int> arr;
vector<bool> visited;
int dfs(int curr, int parity, int &size, vector<int> adj[])
{
    visited[curr] = true;
    if ((arr[curr] & 1) == parity)
        size++;
    for (int j : adj[curr])
    {
        if (visited[j] == false)
        {
            dfs(j, parity, size, adj);
        }
    }
    return size;
}
void solve()
{
    int n, m;
    cin >> n >> m;
    arr.clear();
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    vector<int> adj[n];
    visited = vector<bool>(n, false);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int EVEN = INT_MIN, ODD = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == false && ((arr[i] & 1) == 0))
        {
            int size = 0;
            dfs(i, 0, size, adj);
            EVEN = max(EVEN, size);
        }
    }
    for (int i = 0; i < n; i++)
        visited[i] = false;
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == false && ((arr[i] & 1) == 1))
        {
            int size = 0;
            dfs(i, 1, size, adj);
            ODD = max(ODD, size);
        }
    }
    int q;
    cin >> q;
    while (q--)
    {
        int ch, K;
        cin >> ch >> K;
        if (ch == 1 && ((K & 1) == 1))
        {
            cout << EVEN << "\n";
        }

        if (ch == 1 && ((K & 1) == 0))
        {
            cout << ODD << "\n";
        }

        if (ch == 2 && ((K & 1) == 1))
        {
            cout << ODD << "\n";
        }

        if (ch == 2 && ((K & 1) == 0))
        {
            cout << EVEN << "\n";
        }
    }
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