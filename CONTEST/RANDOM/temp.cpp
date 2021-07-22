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

const ll MAXN = 123460;
set<ll>adj[MAXN];
ll n,m;
ll degree[MAXN];
bool monster[MAXN];
ll dist[MAXN];
ll dist1[MAXN];
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


bool hamiltonian(vector<vector<int>>&adj)
{
	ll n = adj.size();
	ll N  = 1<<n;
	vector<vector<int>>dp(N, vector<int>(n,0));
	for(int i=0;i<n;i++)
	{
		dp[1<<i][i]=1;
	}
	for(int i=0;i<(1<<n);i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i&(1<<j))
			{
				for(int k=0;k<n;k++)
				{
					if((i&(1<<k)) && (adj[k][j]) && (dp[i^(1<<j)][k]))
					{
						dp[i][j]=true;
						break;
					}
				}
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		if(dp[(1<<n)-1][i])
		{
			return true;
		}
	}
	return false;
}


ll nn;
void dfs(ll u, ll par)
{
	nn++;
	if(par!=-1)
	{
		dist[u]=dist[par]+1;
	}
	for(auto v:adj[u])
	{
		if(v!=par)
		{
			dfs(v,u);
		}
	}
}
void dfs1(ll u, ll par)
{
	if(par!=-1)
	{
		dist1[u]=dist1[par]+1;
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
	memset(degree, 0, sizeof(degree));
	memset(monster, 0 ,sizeof(monster));
    cin>>n>>m;
    for(int i=0;i<n-1;i++){
    	int a,b;
	    cin>>a>>b;
	    a--,b--;
	    adj[a].insert(b);
	    adj[b].insert(a);
	    degree[a]++;
	    degree[b]++;
    }
    for(int i=0;i<m;i++)
    {

    	ll a;
    	cin>>a;
    	if(m==1)
    	{
    		cout<<a<<endl;
    		cout<<0<<endl;
    		return;
    	}
    	a--;
    	monster[a]=1;
    }
    queue<ll>Q;
    for(int i=0;i<n;i++)
    {
    	if(degree[i]==1){
    		Q.push(i);
    	}
    }
    while(!Q.empty())
    {
		ll u =Q.front();
		Q.pop();
		if(monster[u]==0)
		{
			// cout<<u<<endl;
			for(auto x:adj[u])
			{
				adj[x].erase(u);
				degree[x]--;
				if(degree[x]==1){
					Q.push(x);
				}
			}
			adj[u].clear();
		}	
    }
    // cout<<endl;
    memset(dist, -1 ,sizeof(dist));
    nn=0;
    for(int i=0;i<n;i++)
    {
    	if(adj[i].size()>0)
    	{
    		dist[i]=0;
    		dfs(i,-1);
    		break;
    	}
    }
    // cout<<"NN";
    // cout<<nn<<endl;
    memset(dist1, -1 ,sizeof(dist1));
    ll mx =INT_MIN;
    ll ans=n;
    for(int i=0;i<n;i++)
    {
    	mx = max(mx,dist[i]);
    }
    for(int i=0;i<n;i++)
    {
    	if(dist[i]==mx)
    	{
    		ans=i;
    		dist1[i]=0;
    		dfs1(i,-1);
    		break;
    	}
    }
    mx =INT_MIN;
    for(int i=0;i<n;i++)
    {
    	mx = max(mx,dist1[i]);
    }
    
    for(ll i=0;i<n;i++)
    {
    	if(dist1[i]==mx)
    	{
    		ans = min(ans, i);
    	}
    }
    // cout<<mx<<endl;
    cout<<ans+1<<endl;
    cout<< (nn*2)-2-mx <<endl;

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