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

vector<ll>wt, cnt;
vector<vector<pll>>adj;

void dfs(ll v, ll p=-1)
{
    if (adj[v].size()==1 && p!=-1)cnt[p]=1;
    for (auto u:adj[v])
    {
        if (u.second==p)continue;
        dfs(u.first, u.second);
        if (p!=-1)cnt[p]+=cnt[u.second];
    }
}

ll getdiff(ll i)
{
    return (wt[i]*cnt[i])-(wt[i]/2*cnt[i]);
}

void solve()
{
    ll n, sum;
    cin>>n>>sum;
    wt=cnt=vector<ll>(n-1, 0);
    adj=vector<vector<pll>>(n);
    for (ll i = 0;i < n-1; i++)
    {
        ll x, y;
        cin>>x>>y>>wt[i];
        x--, y--;
        adj[x].push_back({ y, i });
        adj[y].push_back({ x, i });
    }
    dfs(0);
    set<pll, greater<pll>>st;
    ll curr=0;
    for (int i=0;i<n-1;i++)
    {
        st.insert({ getdiff(i), i });
        curr+=wt[i]*cnt[i];
    }
    //cerr<<curr<<endl;
    int ans=0;
    while (curr>sum)
    {
        ll id = st.begin()->second;
        st.erase(st.begin());
        curr-=getdiff(id);
        wt[id]/=2;
        st.insert({ getdiff(id), id });
        ans++;
    }
    cout<<ans<<endl;
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