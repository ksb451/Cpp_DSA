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

vector<pll> adj[100007];
vector<ll> cnt, w, type;
void dfs(ll curr, ll parent)
{
    if (adj[curr].size() == 1)
        cnt[parent] = 1;
    for (auto j : adj[curr])
    {
        if (j.second == parent)
        {
            continue;
        }
        dfs(j.first, j.second);
        if (parent != -1)
            cnt[parent] += cnt[j.second];
    }
}

ll getdiff(ll i)
{
    return w[i] * 1LL * cnt[i] - (w[i] / 2) * 1LL * cnt[i];
}

ll getdiff2(ll i)
{
    return w[i] * 1LL * cnt[i] - (w[i] / 4) * 1LL * cnt[i];
}

void solve()
{
    ll n, s;
    cin >> n >> s;
    for (int i = 0; i < n + 5; i++)
    {
        adj[i].clear();
    }
    w = cnt = type = vector<ll>(n - 1, 0);
    for (ll i = 0; i < n - 1; i++)
    {
        ll a, b;
        cin >> a >> b >> w[i] >> type[i];
        a--, b--;
        adj[a].push_back({b, i});
        adj[b].push_back({a, i});
    }
    dfs(0, -1);
    set<pll> st1;
    set<pll> st2;
    long long curr_sum = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (type[i] == 1)
        {
            st1.insert({getdiff(i), i});
        }
        else
        {
            st2.insert({getdiff(i), i});
        }
        curr_sum += w[i] * cnt[i] * 1LL;
    }
    cerr << curr_sum << endl;
    ll ans = 0;
    while (curr_sum > s)
    {
        auto id1 = *(st1.rbegin());
        auto id2 = *(st2.rbegin());
        cerr << id1.second << " " << id2.second << " sum " << curr_sum << endl;
        cerr << id1.first << " " << id2.first << endl;
        if (curr_sum - (id1.first) <= s)
        {
            curr_sum -= (id1.first);
            ans++;
            st1.erase(prev(st1.end()));
            w[id1.second] /= 2;
            st1.insert({getdiff(id1.second), id1.second});
        }
        else
        {
            if (getdiff2(id1.second) > getdiff(id2.second))
            {
                cerr << "1twice" << endl;
                curr_sum -= getdiff2(id1.second);
                st1.erase(prev(st1.end()));
                w[id1.second] /= 4;
                st1.insert({getdiff(id1.second), id1.second});
                ans += 2;
            }
            else
            {
                curr_sum -= getdiff(id2.second);
                st2.erase(prev(st2.end()));
                w[id2.second] /= 2;
                st2.insert({getdiff(id2.second), id2.second});
                ans += 2;
            }
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