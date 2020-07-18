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

vector<set<int>> g;
vector<set<int>> leaves;

struct comp
{
    bool operator()(ll a, ll b) const
    {
        if (leaves[a].size() == leaves[b].size())
            return a < b;
        return leaves[a].size() > leaves[b].size();
    }
};

void solve()
{
    int n, k;
    cin >> n >> k;
    g = leaves = vector<set<int>>(n);
    for (int i = 0; i < n - 1; ++i)
    {
        int x, y;
        cin >> x >> y;
        --x, --y;
        g[x].insert(y);
        g[y].insert(x);
    }
    for (int i = 0; i < n; ++i)
    {
        if (g[i].size() == 1)
        {
            leaves[*g[i].begin()].insert(i);
        }
    }
    set<int, comp> st;
    for (int i = 0; i < n; ++i)
    {
        st.insert(i);
    }
    int ans = 0;
    while (true)
    {
        int v = *st.begin();
        if (int(leaves[v].size()) < k)
            break;
        for (int i = 0; i < k; ++i)
        {
            int leaf = *leaves[v].begin();
            g[leaf].erase(v);
            g[v].erase(leaf);
            st.erase(v);
            st.erase(leaf);
            leaves[v].erase(leaf);
            if (leaves[leaf].count(v))
                leaves[leaf].erase(v);
            if (g[v].size() == 1)
            {
                int to = *g[v].begin();
                st.erase(to);
                leaves[to].insert(v);
                st.insert(to);
            }
            st.insert(v);
            st.insert(leaf);
        }
        ans += 1;
    }
    cout << ans << endl;
}

int main()
{
    ll tc = 1;
    cin >> tc;
    while (tc--)
    {
        solve();
    }
    return 0;
}