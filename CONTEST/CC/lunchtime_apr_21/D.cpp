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

ll n,k,A;
vector<ll> adj[MAXN];
vector<ll>spec;
vector<ll>dist;
vector<pll>ans;



pll maxx(pll a, pll b)
{
	if(a.first > b.first)
	{
		return a;
	}
	return b;
}

ll dfs(ll u, ll par, ll up)
{
	// __print(u, par, up);nl();
	if(par == -1)
	{
	}
	else{
		dist[u] = dist[par]+1;
	}
	ll down=-1;
	if(spec[u])
	{
		ans[u] = {dist[u], u};
	}
	if(up!=-1)
	{
		ll a = dist[up] - (dist[u]-dist[up]);
		ll b = up;
		ans[u] = max(ans[u],{a,b});
		// cout<<u<<" "<<ans[u].first<<" "<<ans[u].second<<endl;
	}
	if(spec[u])
	{
		up=u;
	}
	for(auto v :adj[u])
	{
		if(v!=par)
		{
			down = max(down,dfs(v,u,up));
		}
	}
	// cout<<u<<" "<<down<<endl;
	if(down!=-1)
	{
		// __print(u, down);nl();
		ll a = dist[u];
		ll b = down;
		ans[u] = max(ans[u],{a,b});
	}
	if(spec[u])
	{
		ans[u] = max(ans[u],{dist[u], u});
		return u;
	}
	else{
		return down;
	}
}

void dfs1(ll u, ll par)
{
	if(par != -1)
	{
		dist[u] = dist[par]+1;
	}
	for(auto v :adj[u])
	{
		if(v!=par)
		{
			dfs1(v,u);
		}
	}
}


void solve2()
{
    
	ans= vector<pll>(n,{INT_MIN,-1});
	dist = vector<ll>(n,-1);
	dist[A]=0;

	ll x = dfs(A,-1,-1);

	for(int i=0;i<n;i++)
	{
		if(ans[i].first <= (INT_MIN+10))
		{
			cout<<(-1*dist[i])<<" ";
			continue;
		}
		cout<<ans[i].first<<" ";
	}
	nl();
	for(auto i:ans)
	{
		if(i.first <= (INT_MIN+10))
		{
			cout<<x+1<<" ";
			continue;
		}
		cout<<i.second+1<<" ";
	}
	nl();
	return;
}

void solve1(vector<ll>&special)
{
	ans =vector<pll>(n,{INT_MIN,-1});
	for(auto i :special)
	{
		dist= vector<ll>(n,-1);
		dist[i-1]=0;
		dfs1(i-1,-1);
		// __print(dist);
		for(int j=0;j<n;j++)
		{
			ll a= dist[A]-dist[j];
			ll b= i-1;
			// cout<<j<<" "<<a<<" "<<b<<endl;
			ans[j] = maxx(ans[j], {a,b});
		}
	}
	for(auto i:ans)
	{
		cout<<i.first<<" ";
	}
	nl();
	for(auto i:ans)
	{
		cout<<i.second+1<<" ";
	}
	nl();
	return;
}

void solve()
{
	cin>>n>>k>>A;
    A--;
    for(int i=0;i<=n;i++)
    {
    	adj[i].clear();
    }
    spec = vector<ll>(n,0);
    vector<ll>special;
   	for(int i=0;i<k;i++){
   		ll a;
   		cin>>a;
   		special.push_back(a);
   		a--;
   		spec[a]=1;
   	}
   	ll flag=1;
    for(int i=0;i<n-1;i++)
	{
	    ll a,b;
	    cin>>a>>b;
	    a--,b--;
	    adj[a].push_back(b);
	    adj[b].push_back(a);
	    if(abs(a-b) != 1)
	    {
	    	flag=0;
	    }
	}
	if(flag)
	{
		solve2();
		return;
	}	
	solve1(special);
	return;
}

/*
1.check for ll for all variables. 
2.check brackets in all equation and order of conditions.
3.check custom compare funtions if any.
4.check logic carefully.
5.Dont get stuck on one approch.
*/

int main()
{
    fast;
    ll tc = 1;
    IN tc;
    while (tc--)
    {
        solve();
    }
    return 0;
}