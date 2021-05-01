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
// #define endl "\n"
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

const ll MAXN = 505;

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
ll n;
ll arr[MAXN][MAXN];
ll node[2*MAXN];
ll nxt;
vector<pll>edge;

ll rec(vector<ll>curr)
{
	if(curr.size() == 1)
	{
		return curr[0];
	}
	ll res = -1;
	for(int i= 0;i<curr.size();i++)
	{
		for(int j=0;j<curr.size();j++)
		{
			if(i!=j)
			{
				res = max(res, arr[curr[i]][curr[j]]);
			}
		}
	}
	vector<vll>ch;
	ch.push_back({curr[0]});
	for(int i=1;i<curr.size();i++)
	{
		ll v = curr[i];
		ll grp = -1;
		for(int j=0;j<ch.size();j++)
		{
			if(arr[v][ch[j][0]]!=res)
			{
				grp = j;
				break;
			}
		}
		if(grp==-1)
		{
			grp = ch.size();
			ch.push_back({});
		}
		ch[grp].push_back(v);
	}
	ll curr_n = nxt;
	nxt++;
	node[curr_n] = res;
	for(int i=0;i<ch.size();i++)
	{
		ll u  = rec(ch[i]);
		edge.push_back({u,curr_n});
	}
	return curr_n;
}

void solve()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
    	for(int j=0;j<n;j++)
    	{
    		cin>>arr[i][j];
    	}
    }
    for(int i=0;i<n;i++)
    {
    	node[i]= arr[i][i];
    }
    nxt=n;
    // __print("done");nl();
    vector<ll>curr(n);
    iota(all(curr),0);
    ll k = rec(curr);
    cout<<nxt<<endl;
    for(int i=0;i<nxt;i++)
    {
    	cout<<node[i]<<" ";
    }
    cout<<endl;
    cout<<k+1<<endl;
    for(auto i:edge)
    {
    	cout<<i.first+1<<" "<<i.second+1<<endl;
    }
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