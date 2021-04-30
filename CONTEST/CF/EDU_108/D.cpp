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
	ll n;
    cin>>n;
    vector<ll>arr(n);
    vector<ll>brr(n);
    for(ll i=0;i<n;i++)cin>>arr[i];
    for(ll i=0;i<n;i++)cin>>brr[i];

    vector<ll>left(n);
    vector<ll>right(n);
    for(ll i=0;i<n;i++)
    {
    	ll curr = arr[i]*brr[i];
    	left[i]=curr;
    	if(i>0)
    	{
    		left[i]+=left[i-1];
    	}
    }
    for(ll i=n-1;i>=0;i--)
    {
    	right[i] = arr[i]*brr[i];
    	
    	if(i<n-1)
    	{
    		right[i]+=right[i+1];
    	}
    }
    // __print(left);
    // __print(right);
    ll ans=left[n-1];
    for(ll i=0;i<n;i++)
    {
    	ll curr = arr[i]*brr[i];
    	for(ll j=1;j<=min(i, n-i-1);j++)
    	{
    		curr+= (arr[i-j]*brr[i+j]);
    		curr+= (arr[i+j]*brr[i-j]);
    		ll curr_ans=curr;
    		if((i-j-1) >= 0)
    		{
    			curr_ans+=left[i-j-1];
    		}
    		if((i+j+1) <= (n-1))
    		{
    			curr_ans+=right[i+j+1];
    		}
    		ans = max(ans,curr_ans);
    		// cout<<i<<" "<<j<<" "<<curr_ans<<endl;
    	}
    }
    for(ll i=0;i<n-1;i++)
    {
    	ll curr = (arr[i]*brr[i+1]);
    	curr+= (arr[i+1]*brr[i]);
    	ll curr_ans=curr;
    	if((i-1) >= 0)
    	{
    		curr_ans+=left[i-1];
    	}
    	if((i+2) <= (n-1))
    	{
    		curr_ans+=right[i+2];
    	}
    	ans = max(ans,curr_ans);
    	// cout<<i<<" "<<curr_ans<<endl;
    	for(ll j=1;j<=min(i, n-i-2);j++)
    	{
    		curr+= (arr[i-j]*brr[i+1+j]);
    		curr+= (arr[i+1+j]*brr[i-j]);
    		curr_ans=curr;
    		if((i-j-1) >= 0)
    		{
    			curr_ans+=left[i-j-1];
    		}
    		if((i+j+2) <= (n-1))
    		{
    			curr_ans+=right[i+j+2];
    		}
    		// cout<<i<<" "<<j<<" "<<curr_ans<<endl;
    		ans = max(ans,curr_ans);
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
    fast;
    ll tc = 1;
    // IN tc;
    while (tc--)
    {
        solve();
    }
    return 0;
}