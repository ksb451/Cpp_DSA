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


class seg_tree{
	vector<pll>t;
	ll DEF;
public:
	seg_tree()
	{
		t = vector<pll>(MAXN*4, {0,-1});
		DEF = -INF;
	}
	seg_tree(vll &arr)
	{
		ll n = arr.size();
		DEF =-INF;
		t = vector<pll>(MAXN*4, {0,-1});
		build(arr, 1, 0, n-1);
	}

	pll combine (pll a,pll b)
	{
		if(a.first > b.first)
		{
			return a;
		}
		else if(b.first > a.first)
		{
			return b;
		}
		else{
			if(a.second < b.second)
			{
				return a;
			}
			return b;
		}
	}

	void build(vll &arr, ll v, ll tl , ll tr)
	{
		if(tl == tr)
		{
			t[v] = {arr[tl], tl};
		}
		else{
			ll tm = (tl+tr)/2;
			build(arr, v*2,tl,tm);
			build(arr,v*2+1,tm+1, tr);
			t[v] = combine(t[v*2] , t[v*2+1]);
		}
	}

	ll query(ll v, ll tl, ll tr, ll x)
	{
		if(t[v].first < x)
		{
			return -1;
		}
		if(tl ==tr)
		{
			return t[v].second;
		}
		ll tm = (tl+tr)/2;
		if(t[v*2].first >= x)
		{
			return query(v*2, tl, tm, x);
		}
		else if(t[v*2+1].first >= x){
			return query(v*2+1, tm+1, tr, x);
		}
		else{
			return -1;
		}
	}

	void update(ll v, ll tl, ll tr, ll pos, ll new_val)
	{
		if(tl == tr)
		{
			t[v].first = new_val;
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



void solve()
{
	ll n,m;
    cin>>n>>m;
    vector<ll>arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];

    seg_tree S(arr);
	for(int i=0;i<m;i++)
	{
		ll x;
		cin>>x;

		ll mx = S.query(1,0,n-1,x);
		if(mx == -1)
		{
			cout<<0<<" ";
			continue;
		}
		else{
			cout<<mx+1<<" ";
		}
		arr[mx]-=x;
		S.update(1,0,n-1, mx,arr[mx]);
	}
	cout<<endl;
	return;
}

int main()
{
    fast;
    ll tc = 1;
    //IN tc;
    while (tc--)
    {
        solve();
    }
    return 0;
}