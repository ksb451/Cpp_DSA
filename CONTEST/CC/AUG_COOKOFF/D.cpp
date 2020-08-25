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
    cin >> n;
    vector<int> adj[n];
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    string s;
    cin >> s;
    int red = 0, blue = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0')
        {
            red++;
        }
        else
        {
            blue++;
        }
    }
    vector<int> depth(n);
    depth[0] = 0;
    queue<int> Q;
    Q.push(0);
    vector<int> visited(n, 0);
    visited[0] = 1;
    vector<int> lvl;
    while (!Q.empty())
    {
        int k = Q.size();
        lvl.push_back(k);
        while (k--)
        {
            int curr = Q.front();
            Q.pop();
            for (int j : adj[curr])
            {
                if (visited[j] == 0)
                {
                    depth[j] = depth[curr] + 1;
                    visited[j] = 1;
                    Q.push(j);
                }
            }
        }
    }
    int even = 0, odd = 0;
    for (int i = 0; i < lvl.size(); i++)
    {
        if (i & 1)
        {
            odd += lvl[i];
        }
        else
        {
            even += lvl[i];
        }
    }
    string ans = "";
    if (even == red && odd == blue)
    {

        for (int i = 0; i < n; i++)
        {
            if (depth[i] & 1)
            {
                ans += '1';
            }
            else
            {
                ans += '0';
            }
        }
    }
    else if (odd == red && even == blue)
    {
        for (int i = 0; i < n; i++)
        {
            if (depth[i] & 1)
            {
                ans += '1';
            }
            else
            {
                ans += '0';
            }
        }
    }
    else
    {
        cout << -1 << endl;
        return;
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