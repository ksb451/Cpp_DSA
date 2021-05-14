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

const ll MAXN = 100005;

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

vll adj[MAXN];
ll ans;

vll dist;

ll dfs(ll u, ll par=-1)
{
	ll curr = 1;
	ans++;
	ans%=MOD;
	ll wocurr=0;
	for(auto v:adj[u])
	{
		if(v!=par)
		{
			ll x = dfs(v,u);
			ans+=(x*wocurr);
			ans%=MOD;
			if(wocurr>0)
			{
				ans+=(x*wocurr);
				ans%=MOD;
			}
			ans+=x;
			ans%=MOD;
			wocurr+=x;
			curr+= (x*2);
		}
	}
	return curr;
}

void dfs1(ll u,ll par)
{
	if(dist[u]==-1)
	{
		dist[u] = dist[par] + 1;
	}
	for(auto v:adj[u])
	{
		if(v!=par)
		{
			dfs1(v,u);
		}
	}
}


void solve()
{
	
	ans=0;
	dfs(0);
	cout<<ans%MOD<<endl;
}

void solve2(ll n)
{
	ans = n;
	for(int i=0;i<n;i++)
	{
		dist = vll(n,-1);
		// __print(dist);
		dist[i]=0;
		dfs1(i,-1);
		// __print(dist);
		for(int j=i+1;j<n;j++)
		{
			ll x = dist[j] -1;
			// __print(i,j,x);nl();
			ans+= pow(2,x);
			ans%=MOD;
		}	
	}
	cout<<ans%MOD<<endl;
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
    	ll n;
	    cin>>n;
	    for0(i,n+3)
	    {
	    	adj[i].clear();
	    }
	    for(int i=0;i<n-1;i++)
		{
		    int a,b;
		    cin>>a>>b;
		    a--,b--;
		    adj[a].push_back(b);
		    adj[b].push_back(a);
		}
        solve();
        solve2(n);
        //cout.flush();
    }
    return 0;
}