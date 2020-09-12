//**sn0wrus**//
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cout.tie(NULL);                   \
    cin.tie(NULL);

#define IN cin >>
#define OUT cout <<
#define endl "\n"
#define all(a) (a).begin(), (a).end()
#define pb push_back
using ll = long long int;
using ld = long double;
using pll = pair<ll, ll>;
using pii = pair<int, int>;
using vll = vector<ll>;
using vi = vector<int>;
const ll mod = (ll)(1e9) + 7LL;
const ll M = 998244353LL;

const int dir8[8][2]={{1,0},{0,1},{-1,0},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
const int dir4[4][2]={{1,0},{0,1},{-1,0},{0,-1}};

/*
for(int i=0;i<n-1;i++)
{
    int a,b;
    cin>>a>>b;
    a--,b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
}
*/

const int maxn = 1e6 + 1;

vector<int> bg[maxn], rg[maxn];
int b[maxn], r[maxn], d[maxn], col[maxn];
int n, m;

void solve()
{
	cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, t;
        cin >> u >> v >> t;
        --u; --v;
        if (!t) bg[v].push_back(u);
        else rg[v].push_back(u);
    }
    for (int i = 0; i < n; i++)
        d[i] = b[i] = r[i] = n;
    queue<int> q;
    q.push(n - 1);
    d[n - 1] = r[n - 1] = b[n - 1] = 0;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (auto to : bg[x]) {
            if (b[to] < n) continue;
            b[to] = d[x] + 1;
            if (max(b[to], r[to]) < n) {
                q.push(to);
                d[to] = max(b[to], r[to]);
            }
        }
        for (auto to : rg[x]) {
            if (r[to] < n) continue;
            r[to] = d[x] + 1;
            if (max(b[to], r[to]) < n) {
                q.push(to);
                d[to] = max(b[to], r[to]);
            }
        }
    }
    if (d[0] == n) cout << "-1\n";
    else cout << d[0] << '\n';
    for (int i = 0; i < n; i++) {
        if (b[i] > r[i]) col[i] = 0;
        else col[i] = 1;
        cout << col[i];
    }
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