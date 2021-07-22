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

class DSU
{
    ll N;
    ll total_components;
    vector<ll> sz;
    vector<ll> parent;

public:
    DSU(ll n)
    {
        N = n;
        total_components = n;
        sz = vector<ll>(n, 1);
        for (ll i = 0; i < n; i++)
        {
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

    ll component_size(int x)
    {
        return sz[find_set(x)];
    }

    ll size()
    {
        return N;
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
        }
    }
};

struct FenTree {
    vector<int> bit;  // binary indexed tree
    int n;

    FenTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    FenTree(vector<int> a) : FenTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    int sum(int l, int r) {
    	if(l==0)
    	{
    		return sum(r);
    	}
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};

void solve()
{
	ll n;
    cin>>n;
    DSU dsu(n);
    vector<vll>old;
	for(int i=0;i<n-1;i++)
	{
	    int a,b;
	    cin>>a>>b;
	    a--,b--;
	    if(dsu.find_set(a)==dsu.find_set(b))
	    {
	    	old.push_back({a,b});
	    }
	    else{
	    	dsu.unify(a,b);
	    }
	}
	set<int>S;
	for(int i=0;i<n;i++)
	{
		S.insert(dsu.find_set(i));
	}
	cout<<S.size()-1<<endl;
	while(S.size()>1)
	{
		int x = *S.begin();
		S.erase(S.begin());
		int y = *(S.begin());
		cout<<old.back()[0]+1<<" "<<old.back()[1]+1<<" "<<x+1<<" "<<y+1<<endl;
		old.pop_back();
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