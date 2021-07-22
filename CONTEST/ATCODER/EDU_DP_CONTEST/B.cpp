//**sn0wrus**//
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

//#pragma GCC optimize("Ofast")
//#pragma GCC optimization("unroll-loops, no-stack-protector")
//#pragma GCC target("avx,avx2,fma")

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
#define for0(i,n) for(int i=0;i<n;i++)
#define forn(i,n) for(int i=n-1;i>=0;i++)
#define IN cin >>
#define OUT cout <<
#define endl "\n"
#define all(a) (a).begin(), (a).end()
#define allr(a) (a).rbegin(), (a).rend()
#define pb push_back

#define fi first
#define se second

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x ;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}'<<endl;}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}"<<endl;}
template<typename T, typename... Args>
void __print(T t, Args... args) // recursive variadic function
{
    cout << t <<" " ;
    __print(args...) ;
}
void nl()
{
    cout<<endl;
}

using ll = long long int;
using ld = long double;
using pll = pair<ll, ll>;   
using pii = pair<int, int>;
using plll  = pair<ll,pll>;
using vll = vector<ll>;
using vi = vector<int>;

const ll MOD = (ll)(1e9) + 7LL;
const ll MM = 998244353LL;
const ll INF  = INT_MAX;

const int dir8[8][2]={{1,0},{0,1},{-1,0},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
const int dir4[4][2]={{1,0},{0,1},{-1,0},{0,-1}};

const ll MAXN = 200005;
const ll LOGN = 20;
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


ll BINDP[MAXN][LOGN];
ll lvl[MAXN];
void dfs_bl_0(ll u, ll par)
{
    for(auto v:adj[u])
    {
        if(v!=BINDP[u][0])
        {
            BINDP[v][0]=u;
            lvl[v]=lvl[u]+1;
            dfs_bl_0(v,u);
        }
    }
}
void preprocess()
{
    lvl[0]=0;
    BINDP[0][0]=0;
    dfs_bl_0(0,-1);
    for(int k=1;k<LOGN;k++)
    {
        for(int i=0;i<n;i++)
        {
            BINDP[i][k] = BINDP[BINDP[i][k-1]][k-1];
        }
    }
}
ll lca(ll a,ll b)
{
    if(lvl[a]>lvl[b])swap(a,b);
    ll d= lvl[b]-lvl[a];
    for(int i=0;i<LOGN;i++)
    {
        if(d&(1<<i))
        {
            b = BINDP[i][b];
        }
    }
    if(a==b)return a;
    for(int i=LOGN-1;i>=0;i--)
    {
        if(BINDP[a][i]!=BINDP[b][i])
        {
            a = BINDP[a][i];
            b = BINDP[b][i];
        }
    }
    return BINDP[a][0];
}
ll dist(ll a, ll b)
{
    return lvl[a] + lvl[b] - 2*(lvl[lca(a,b)]);
}




void solve()
{
	ll n,m;
    cin>>n>>m;
    vector<vll>arr(n,vll(m));
    for(int i=0;i<n;i++)
    {
    	for(int j=0;j<m;j++)
    	{
    		cin>>arr[i][j];
    	}
    }
    vll min(m+n,INT_MAX);
    vector<vll>rep(n,vll(m));
    ll k=0;
    for(int i=m-1;i>=0;i++)
    {
    	int y = i+1;
    	int x=0;
    	ll mn = INT_MAX;
    	while(x<n && y<m)
    	{
    		rep[x][y]=k;
    	}
    }
}

/*
1.check for ll for all variables. 
2.chec for return satement in correct places.
3.check brackets in all equation and order of conditions.
4.check custom compare funtions if any.
5.check logic carefully.
6.Dont get stuck on one approch.
*/

int main()
{
    fast;
    ll tc = 1;
    // IN tc;
    while (tc--)
    {
        solve();
        cout.flush();
    }
    return 0;
}