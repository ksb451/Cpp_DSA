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

vector<vector<int>> adj;
vector<int> inplace;
int ans = 0;
vector<int> processed;

void dfs(int curr, int parent)
{
    for (int j : adj[curr])
    {
        if (j != parent)
        {
            dfs(j, curr);
        }
    }
    if (inplace[curr] == curr)
    {
        ans += 2;
        if (parent != -1)
        {
            int temp = inplace[curr];
            inplace[curr] = inplace[parent];
            inplace[parent] = temp;
        }
        else
        {
            int x = adj[curr][0];
            int temp = inplace[curr];
            inplace[curr] = inplace[x];
            inplace[x] = temp;
        }
    }
}

void solve()
{
    int n;
    cin >> n;
    processed = inplace = vector<int>(n, 0);
    adj = vector<vector<int>>(n);
    for (int i = 0; i < n - 1; i++)
    {
        inplace[i] = i;
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    inplace[n - 1] = n - 1;
    ans = 0;
    dfs(0, -1);
    cout << ans << endl;
    for (auto i : inplace)
    {
        cout << i + 1 << " ";
    }
    cout << endl;
}

int main()
{
    ll tc = 1;
    //IN tc;
    while (tc--)
    {
        solve();
    }
    return 0;
}