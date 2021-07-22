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

const ll MAXN = 400005;

ll bit[MAXN];

void add(ll idx, ll val) {
    for (++idx; idx < MAXN; idx += idx & -idx)
        bit[idx] += val;
}

void range_add(ll l, ll r, ll val) {
    add(l, val);
    add(r + 1LL, -val);
}

ll point_query(ll idx) {
    ll ret = 0LL;
    for (++idx; idx > 0LL; idx -= idx & -idx)
        ret += bit[idx];
    return ret;
}

void solve()
{
	memset(bit,0,sizeof(bit));
    ll n,C;
    cin>>n>>C;
    vector<vll>arr(n,vll(2));
    for(int i=0;i<n;i++)cin>>arr[i][0]>>arr[i][1];

    set<ll>points;
	
	for(auto i:arr)
	{
		points.insert(i[0]);
		points.insert(i[1]);
		points.insert(i[0]+1);
		points.insert(i[1]-1);
	}
	unordered_map<ll,ll>UM;
	unordered_map<ll,ll>UM1;
	for(auto i:points)
	{
		UM[i] = UM.size();
	}
	for(auto i:UM)
	{
		UM1[i.second]=i.first;
	}
	for(auto interval : arr)
	{
		if(interval[1]-interval[0] > 1)
		{
			range_add(UM[interval[0]+1], UM[interval[1]-1], 1);
		}
	}
	vector<ll>point_count(MAXN,0);
	vector<ll>cnt(MAXN,0);
	
    for(int i=0;i<MAXN;i++)
    {
    	point_count[i] = point_query(i);
    	// cout<<point_count[i]<<" "<<UM1[i]<<endl;
    	cnt[point_count[i]]++;
    	if(i>0)
    	{
    		if(point_count[i]==point_count[i-1])
    		{
    			ll gap = (UM1[i] - UM1[i-1]-1);
    			if(gap>0)
    			{
    				cnt[point_count[i]]+=gap;
    			}	
    		}
    	}
    }
    // cout<<endl<<endl;
    map<ll,ll>M;
    for(int i=0;i<MAXN;i++)
    {
    	// cout<<i<<" "<<cnt[i]<<endl;
    	if(cnt[i]>0)
    		M[i] = cnt[i];
    }
    ll ans = n;
    while(C)
    {
    	if(M.empty())break;
    	auto x = *(prev(M.end()));
    	ll count = x.second;
    	ll val = x.first;
    	// cout<<val<<" "<<count<<endl;
    	ll temp = min(count, C);
    	C-=temp;
    	ans += (temp*val);
    	M[val]-=count;
    	if(M[val]==0)
    	{
    		M.erase(val);
    	}
    }

    cout<<ans<<endl;
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
    ios_base::sync_with_stdio(false); 
    cout.tie(NULL);
    cin.tie(NULL);
    ll tc = 1;
    IN tc;
    for (int i = 1; i <= tc; i++)
    {
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}