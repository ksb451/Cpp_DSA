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

void solve()
{
	ll n,m;
    cin>>n>>m;
    vector<pll>adj[n];
    for(int i=0;i<m;i++){
    	ll a,b,c;
    	cin>>a>>b>>c;
    	a--,b--;
    	adj[a].push_back({b,c});
    	adj[b].push_back({a,c});
    }
    ll dist[n][2][2];
    for(int i=0;i<n;i++)
    {
    	for(int j=0;j<2;j++)
    	{
    		for(int k=0;k<2;k++)
    		{
    			dist[i][j][k]=(ll)1e18;
    		}
    	}
    }
    multiset <pair<ll,tuple<ll,ll,ll>>>S;
    dist[0][0][0]=0;
    S.insert({0,{0,0,0}});
    while(!S.empty()){
    	auto curr = *S.begin();\
    	S.erase(S.begin());
    	ll d = curr.first;
    	ll u = get<0>(curr.second);
    	ll f1 = get<1>(curr.second);
    	ll f2 = get<2>(curr.second);
    	for(auto edge : adj[u])
    	{
    		ll v = edge.first;
    		ll cost = edge.second;
    		if(dist[v][f1][f2] > d+cost)
    		{
    			S.erase({dist[v][f1][f2],{v,f1,f2}});
    			dist[v][f1][f2] = d+cost;
    			S.insert({dist[v][f1][f2],{v,f1,f2}});
    		}
    		if(f1==0)
    		{
    			if(dist[v][1][f2] > d+cost+cost)
    			{
    				S.erase({dist[v][1][f2],{v,1,f2}});
					dist[v][1][f2] = d+cost+cost;
					S.insert({dist[v][1][f2],{v,1,f2}});
    			}
    		}
    		if(f2==0)
    		{
    			if(dist[v][f1][1] > d+cost-cost)
    			{
    				S.erase({dist[v][f1][1],{v,f1,1}});
					dist[v][f1][1] = d+cost-cost;
					S.insert({dist[v][f1][1],{v,f1,1}});
    			}
    		}
    		if((f1==0) && (f2==0))
    		{
    			if(dist[v][1][1] > d+cost)
	    		{
	    			S.erase({dist[v][1][1],{v,1,1}});
	    			dist[v][1][1] = d+cost;
	    			S.insert({dist[v][1][1],{v,1,1}});
	    		}
    		}
    	}
    }
    for(int i=1;i<n;i++)
    {
    	cout<<dist[i][1][1]<<" ";
    }
    cout<<endl;
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
    // IN tc;
    while (tc--)
    {
        solve();
    }
    return 0;
}