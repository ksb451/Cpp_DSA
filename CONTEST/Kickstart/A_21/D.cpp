//**sn0wrus**//
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cout.tie(NULL);                   \
    cin.tie(NULL);
#define write(a)          \
    for (auto x : a)      \
    {                     \
        cout << x << " "; \
    }                     \
    cout << endl;
#define read(a)       \
    for (auto &x : a) \
    {                 \
        cin >> x;     \
    }
#define IN cin >>
#define OUT cout <<
#define endl "\n"
#define all(a) (a).begin(), (a).end()
#define allr(a) (a).rbegin(), (a).rend()
#define pb push_back
#define fi first
#define se second

using ll = long long int;
using ld = long double;
using pll = pair<ll, ll>;   
using pii = pair<int, int>;
using plll  = pair<ll,pll>;
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
const ll MAXN= 50002;

ll gcd(ll a, ll b)
{
    if(b==0)
    {
        return a;
    }
    return gcd(b,a%b);
}

ll t[4*MAXN];

ll combine (ll a,ll b)
{
    return gcd(a,b);
}

void build(vll &arr, ll v, ll tl , ll tr)
{
    if(tl == tr)
    {
        t[v] = arr[tl];
    }
    else{
        ll tm = (tl+tr)/2;
        build(arr, v*2,tl,tm);
        build(arr,v*2+1,tm+1, tr);
        t[v] = combine(t[v*2] , t[v*2+1]);
    }
}

ll query(ll v, ll tl, ll tr, ll l, ll r)
{
    if(l>r)
    {
        return 0;
    }
    if(l == tl && r==tr)
    {
        return t[v];
    }
    else{
        ll tm = (tl+tr)/2;
        return combine(query(v*2, tl, tm , l ,min(r,tm)), query(v*2+1, tm+1, tr, max(l, tm+1), r));
    }
}

void update(ll v, ll tl, ll tr, ll pos, ll new_val)
{
    if(tl == tr)
    {
        t[v] = new_val;
    }
    else{
        ll tm = (tl+tr)/2;
        if(pos<=tm)
        {
            update(v*2, tl, tm, pos, new_val);
        }
        else{
            update(v*2+1, tm+1, tr, pos, new_val);
        }
        t[v] = combine(t[v*2] , t[v*2+1]);
    }
}

vector<ll>Q;
vector<vector<tuple<ll,ll,ll>>>arr;
unordered_map<ll,ll>ind;
vector<vector<pll>>queries;
vector<ll>ans;
ll n,q;
void dfs(ll curr, ll par)
{
    // cout<<curr<<endl;
    // cout<<curr<<endl;
    // cout<<queries[curr].size()<<endl;
    for(auto i: queries[curr])
    {
        auto temp = upper_bound(all(Q),i.second);
        ll x = temp - Q.begin() -1;

        ans[i.first] = query(1,0,n-1,0, x);
    }
    for(auto i:arr[curr])
    {
        if(get<0>(i) == par)
        {
            continue;
        }
        else{
            ll next = get<0>(i);
            ll Li = get<1>(i);
            ll Ai = get<2>(i);
            // cout<<next<<" "<<Li<<" "<<Ai<<endl;
            ll id = ind[Li];
            // cout<<id<<endl;
            update(1,0,n-1, id, Ai);
            // cout<<t[1]<<endl;
            dfs(next, curr);
            update(1,0,n-1, id, 0);
        }
    }
}


void solve()
{
    cin>>n>>q;
    arr = vector<vector<tuple<ll,ll,ll>>>(n);
    Q.clear();
    memset(t,0,sizeof(t));
    for(int i=0;i<n-1;i++)
    {
        ll a,b,c,d;
        cin>>a>>b>>c>>d;
        a--;
        b--;
        arr[a].push_back({b,c,d});
        arr[b].push_back({a,c,d});
        Q.push_back(c);
    }
    // for(int i=0;i<4*n;i++)
    // {
    //     cout<<t[i]<<" ";
    // }
    // cout<<endl;
    // for(int i=0;i<n;i++)
    //{
        // cout<<i<<" "<<arr[i].size()<<endl;
    // }
    sort(all(Q));
    ind.clear();
    for(int i=0;i<n-1;i++)
    {
        ind[Q[i]]=i;
    }
    queries=vector<vector<pll>>(n);
    for(int i=0;i<q;i++){
        ll a,b;
        cin>>a>>b;
        queries[a-1].push_back({i,b});
    }
    ans = vector<ll>(q,0);
    dfs(0,-1);
    write(ans);
    return;
}

int main()
{
    fast;
    ll tc = 1;
    IN tc;
    for (int i = 1; i <= tc; i++)
    {
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}