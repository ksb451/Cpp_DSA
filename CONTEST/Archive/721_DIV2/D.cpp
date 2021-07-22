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

vector<ll>adj[MAXN];
vector<ll>parent;
vector<ll>ans;
vector<ll>sz;

ll dfs0(ll u, ll par)
{
	sz[u] =1;
	for(auto v:adj[u])
	{
		if(v!=par)
		{
			parent[v]=u;
			sz[u]+= dfs0(v,u);
		}
	}
	return sz[u];
}

void solve()
{
	ll n;
    cin>>n;
    for(int i=0;i<n+5;i++)
    {
    	adj[i].clear();
    }
    for(int i=0;i<n-1;i++)
	{
	    ll a,b;
	    cin>>a>>b;
	    adj[a].push_back(b);
	    adj[b].push_back(a);
	}
	ans = vll (n+1,0);
	sz = vll(n,0);
	parent = vector<ll>(n,-1);
	dfs0(0,-1);
	// write(sz);
	// write(parent);
	for(auto i:adj[0])
	{
		ans[0] += ((sz[i]*(sz[i]-1))/2);
	}
	ll tot = (n*(n-1))/2;
	tot -= ans[0];
	ll tem= 1;
	while(parent[tem]!=0)
	{
		tem = parent[tem];
	}

	tot -= (sz[1]*(sz[0]-sz[tem]));
	ans[1] = tot;

	ll a=0,b=0;
	vll path(n,0);
	ll i=1;
	path[0]=1;
	for(;i<n;i++)
	{
		ll curr = i;
		while(path[curr]==0)
		{
			path[curr]=1;
			curr = parent[curr];
		}
		// cout<<i<<" "<<curr<<endl;
		if(curr == a)
		{
			a = i;
		}
		else if(curr == b)
		{
			b=i;
		}
		else{
			break;
		}
		ll x=1,y=1;
		for(auto v : adj[a])
		{
			if(path[v]==0)
			{
				x+=sz[v];
			}
		}
		for(auto v : adj[b])
		{
			if(path[v]==0)
			{
				y+=sz[v];
			}
		}
		// cout<<"a"<<a<<" "<<"b"<<b<<endl;
		// cout<<"x"<<x<<" "<<"y"<<y<<endl;
		ll nxt = i+1;
		if(nxt<n)
		{
			tem = nxt;
			while(path[tem]==0)
			{
				tem = parent[tem];
			}
			if(tem == a)
			{
				x -= sz[nxt];
			}
			else if(tem ==b)
			{
				y-= sz[nxt];
			}
			//cout<<"x"<<x<<" "<<"y"<<y<<endl;
			ans[nxt] = x*y;
		}
		else{
			ans[n] = 1;
		}

	}
	
	write(ans);
	return;
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
    IN tc;
    while (tc--)
    {
        solve();
        cout.flush();
    }
    return 0;
}