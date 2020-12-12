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
    }                     
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
vector<vector<ll>>edge;
vector<ll>a;
vector<ll>b, used;
vector<ll>order[2];
ll ans=0;

void dfs(int v)
{
    used[v]=1;
    for (int i:edge[v])
    {
        if (!used[i])
        {
            dfs(i);
        }
    }
    ans+=a[v];
    if (b[v]!=-1&&a[v]>0) {
        a[b[v]]+=a[v];
    }
    if (a[v]>0) {
        order[0].push_back(v+1);
    }
    else {
        order[1].push_back(v+1);
    }
}

void solve()
{
    ll n;
    cin>>n;
    //cout<<"done1";
    used=b=a=vll(n);
    read(a);
    edge=vector<vll>(n);
    //cout<<"done2";
    for (int i=0;i<n;i++)
    {
        ll x;
        cin>>x;
        if (x!=-1)
        {
            --x;
            edge[x].push_back(i);
        }
        b[i]=x;
    }
    ans=0;
    for (int i=0;i<n;i++) {
        if (!used[i])
        {
            dfs(i);
        }
    }
    cout<<ans<<endl;
    reverse(all(order[1]));
    write(order[0]);
    write(order[1]);
    cout<<endl;
}

int main()
{
    fast;
    //
    ll tc = 1;
    //IN tc;
    while (tc--)
    {
        solve();
    }
    return 0;
}