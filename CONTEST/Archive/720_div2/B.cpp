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

ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
     
}

void solve()
{
	ll n;
    cin>>n;
    vector<ll>arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    if(n==1)
    {
    	cout<<0<<endl;
    	return;
    }
    if(n==2)
    {
		cout<<1<<endl;
		cout<<"1 2 "<<min(arr[0], arr[1])<<" "<<min(arr[0], arr[1])+1<<endl;
		return;
    }
    ll x = arr[0];
	ll ind = 0;
	for(int i=0;i<n;i++)
	{
		if(x > arr[i])
		{
			x= arr[i];
			ind =i;
		}
	}
    vector<vll>ans;
    ll q= ind;
    if(ind<n-1)
    {
    	ans.push_back({ind+1,ind+2,arr[ind], arr[ind]});
    	arr[ind+1]=arr[ind];
    }
    for(int i=ind-1;i>=0;i--)
    {
    	swap(arr[i],arr[i+1]);
		arr[i+1] = x+q;
		q--;
		ans.push_back({i+1,i+2,arr[i], arr[i+1]});

    }
    for(int i=ind+1;i<n-1;i++)
    {
    	swap(arr[i], arr[i+1]);
		arr[i] = arr[i-1]+1;

		ans.push_back({i+1,i+2,arr[i], arr[i+1]});
    }
	while((gcd(arr[n-2], arr[n-3])!=1) || (gcd(arr[n-2], arr[n-1])!=1))
	{
		arr[n-2]++;
	}
	ans.push_back({n-1,n,arr[n-2], arr[n-1]});
    cout<<ans.size()<<endl;
    for(auto i:ans)
    {
    	for(auto j:i)
    	{
    		cout<<j<<" ";
    	}
    	cout<<endl;
    }
    // write(arr);
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
    IN tc;
    while (tc--)
    {
        solve();
    }
    return 0;
}