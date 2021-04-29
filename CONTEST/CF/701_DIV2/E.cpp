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
vector<set<ll>>ST;
vector<ll>adj[MAXN];
vector<ll>dep;
vector<ll>val;
map<tuple<ll,ll,ll>,ll>dp;
ll n, d;

ll rec(ll depth, ll r, ll b)
{
	if(depth == d)
	{
		return 0;
	}
	else if(dp.find({depth, r, b})==dp.end())
	{
		ll ans=0;
		for(auto i:adj[ind])
		{
			ll curr = max(abs(val[i]-(*ST[depth+1].begin())), abs(val[i]- *(prev(ST[depth+1].end()))));
			curr+=rec(depth+1, i);
			ans = max(ans,curr);
		}
		return dp[{depth,r,b}]=ans;
	}
	else{
		return dp[{depth,r,b}];
	}
}

void solve()
{
    cin>>n;
    for(int i=0;i<n+1;i++)
    {
    	adj[i].clear();
    }
    dep = vector<ll>(n+1,0);
    for(ll i=0;i<n-1;i++){
		ll x;
		cin>>x;
		adj[x].push_back(i+2);
    }
    val = vll(n+1);
    for(int i=0;i<n-1;i++)
    {
    	ll x;cin>>x;
    	val[i+2]=x;
    }
    queue<ll>Q;
    Q.push(1);
    d= 0;
    while(!Q.empty())
    {
    	ll curr = Q.front();
    	Q.pop();
    	for(auto i:adj[curr])
    	{
    		Q.push(i);
    		dep[i]=dep[curr]+1;
    		d= max(d,dep[i]);
    	}
    }
    ST = vector<set<ll>>(d+1);
    for(int i=2;i<=n;i++)
    {
    	ST[dep[i]].insert({val[i],i});
    }
    dp.clear();
    cout<<rec(0,1,1)<<endl;
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