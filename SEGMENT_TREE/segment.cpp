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
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}


using ll = long long int;
using ld = long double;
using pll = pair<ll, ll>;   
using pii = pair<int, int>;
using plll  = pair<ll,pll>;
using vll = vector<ll>;
using vi = vector<int>;

const ll MOD = (ll)(1e9) + 7LL;
const ll MM = 998244353LL;
const ll INF = INT_MAX;

const int dir8[8][2]={{1,0},{0,1},{-1,0},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
const int dir4[4][2]={{1,0},{0,1},{-1,0},{0,-1}};

const ll MAXN = 200005;

class seg_tree{
	vector<ll>t;
	ll DEF;
public:
	seg_tree()
	{
		t = vector<ll>(MAXN*4, 0);
		DEF = 0;
	}
	seg_tree(vll &arr)
	{
		ll n = arr.size();
		DEF =0;
		t = vector<ll>(MAXN*4, 0);
		build(arr, 1, 0, n-1);
	}

	ll combine (ll a,ll b)
	{
		return a+b;
	}

	void build(vll &arr, ll v, ll tl , ll tr)
	{
		if(tl == tr)
		{
			t[v] = arr[tl];
		}
		else{
			ll tm = (tl+tr)/2;
			build(arr, v*2,tl,tm);
			build(arr,v*2+1,tm+1, tr);
			t[v] = combine(t[v*2] , t[v*2+1]);
		}
	}

	ll query(ll v, ll tl, ll tr, ll l, ll r)
	{
		if(l>r)
		{
			return DEF;
		}
		if(l == tl && r==tr)
		{
			return t[v];
		}
		else{
			ll tm = (tl+tr)/2;
			return combine(query(v*2, tl, tm , l ,min(r,tm)), query(v*2+1, tm+1, tr, max(l, tm+1), r));
		}
	}

	void update(ll v, ll tl, ll tr, ll pos, ll new_val)
	{
		if(tl == tr)
		{
			t[v] = new_val;
		}
		else{
			ll tm = (tl+tr)/2;
			if(pos<=tm)
			{
				update(v*2, tl, tm, pos, new_val);
			}
			else{
				update(v*2+1, tm+1, tr, pos, new_val);
			}
			t[v] = combine(t[v*2] , t[v*2+1]);
		}
	}
};

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
	ll n,q;
    cin>>n>>q;
    vector<ll>arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];

    seg_tree s(arr);
	while(q--)
	{
		ll a,l,r;
		cin>>a>>l>>r;
		if(a==0)
		{
			cout<<s.query(1,0,n-1, l,r)<<endl;
		}
		else{
			s.update(1,0,n-1,l,r);
		}
	}
	return;
}

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