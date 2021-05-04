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
ll x;
struct DSU
{
    ll N;
    ll total_components;
    vector<ll> sz;
    vector<ll> parent;
    vector<ll> tot;
    DSU(vector<ll>&arr)
    {
    	ll n = arr.size();
        N = n;
        total_components = n;
        sz = vector<ll>(n, 1);
        tot = vector<ll>(n);
        for (ll i = 0; i < n; i++)
        {
        	tot[i] = arr[i];
            parent.push_back(i);
        }
    }
    ll find_set(ll x)
    {
        if(x == parent[x])
        {
            return x;
        }
        return parent[x] = find_set(parent[x]);
    }

    ll component_size(ll x)
    {
        return sz[find_set(x)];
    }

    ll asphalt(ll x)
    {
        return tot[find_set(x)] ;
    }

    ll components()
    {
        return total_components;
    }

    void unify(ll p, ll q)
    {
        ll a = find_set(p);
        ll b = find_set(q);
        if (a != b)
        {
            if(sz[a]<sz[b])
                swap(a,b);
            parent[b] = a;
            sz[a]+=sz[b];
            total_components--;
            tot[a]+=tot[b];
            tot[a]-=x;
        }
    }
};

vector<ll>arr;

bool cmp(vll a, vll b)
{
	if(arr[a[0]]+arr[a[1]] > arr[b[0]]+arr[b[1]])
	{
		return true;
	}
	return false;
}

void solve()
{
	ll n,m;
    cin>>n>>m>>x;
    arr = vector<ll>(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    vector<vll>roads(m,vll(3,0));
	for(int i=0;i<m;i++)
	{
		ll a,b;
		cin>>a>>b;
		roads[i][0] = a-1;
		roads[i][1] = b-1;
		roads[i][2] = i;
	}
	ll total = accumulate(all(arr),0);
	if(total < (x*(n-1)))
	{
		cout<<"NO"<<endl;
		return;
	}
	sort(all(roads),cmp);

	DSU ds(arr);
	vll(ans);
	for(int k=0;k<n;k++)
	{
		bool flag=false;
		for(int i=0;i<m;i++)
		{
			ll a = roads[i][0];
			ll b = roads[i][1];
			ll aa = ds.find_set(a);
			ll bb = ds.find_set(b);
			if(aa!=bb)
			{
				if(ds.tot[aa]+ds.tot[bb] >= x)
				{
					flag=true;
					ds.unify(a,b);
					ans.push_back(roads[i][2]);
				}
			}
		}
		if(flag==false)
		{
			break;
		}
		if(ds.components()==1)
		{
			break;
		}
	}
	
	if(ds.components()>1)
	{
		cout<<"NO"<<endl;
		return;
	}
	cout<<"YES"<<endl;
	for(auto i:ans)
	{
		cout<<i+1<<endl;
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