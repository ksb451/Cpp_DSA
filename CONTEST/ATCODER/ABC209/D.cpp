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

void solve()
{
	ll n,q;
    cin>>n>>q;
    for(int i=0;i<n-1;i++)
	{
	    ll a,b;
	    cin>>a>>b;
	    a--,b--;
	    adj[a].push_back(b);
	    adj[b].push_back(a);
	}
	ll par[n][20];
	vll height(n);
	height[0]=0;
	memset(par,-1,sizeof(par));
	queue<int>Q;
	Q.push(0);
	par[0][0]=-1;
	while(Q.empty()==false)
	{
		ll curr = Q.front();
		Q.pop();
		for(auto i:adj[curr])
		{
			if(i!=par[curr][0])
			{
				height[i]=height[curr]+1;
				par[i][0]=curr;
				Q.push(i);
			}
		}
	}

	for(int k=1;k<20;k++)
	{
		for(int i=0;i<n;i++)
		{
			if(par[i][k-1]!=-1)
				par[i][k] = par[par[i][k-1]][k-1];
		}
	}
	// for(int k=0;k<20;k++)
	// {
	// 	for(int i=0;i<n;i++)
	// 	{
	// 		cout<<par[i][k]<<" ";
	// 	}
	// 	cout<<endl;
	// }

	while(q--)
	{
		ll a,b;
		cin>>a>>b;
		a--,b--;
		ll ans=0;
		if(height[a]!=height[b])
		{

			ll node,dist;
			if(height[a]>height[b])
			{
				node=a;
				dist = height[a]-height[b];
			}
			else{
				node=b;
				dist = height[b]-height[a];
			}
			ans+=dist;
			for(int i=0;i<20;i++)
			{
				if((dist&(1<<i)))
				{
					node= par[node][i];
				}
			}
			if(height[a]>height[b])
			{
				a=node;
			}
			else{
				b=node;
			}
		}
		ll temp = height[a];
		// cout<<a<<" "<<b<<endl;
		for(int i=19;i>=0;i--)
		{
			if(par[a][i] == par[b][i])
			{
				continue;
			}
			else{
				a=par[a][i];
				b=par[b][i];
			}
		}
		while(a!=b)
		{
			a = par[a][0];
			b= par[b][0];
		}
		ans += ((temp-(height[a]))*2);
		if(ans&1)
		{
			cout<<"Road"<<endl;
		}
		else{
			cout<<"Town"<<endl;
		}
	}
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
    // IN tc;
    while (tc--)
    {
        solve();
        cout.flush();
    }
    return 0;
}