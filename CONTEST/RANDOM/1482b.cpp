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

    bool x=false;
    for(ll i=0;i<n-1;i++)
    {
    	if(arr[i]==arr[i+1])
    	{
    		x=true;
    	}
    }
    for(ll i=0;i<n-1;i++)
    {
    	if(x)
    	{
    		if(arr[i]!=arr[i+1])
    		{
    			cout<<-1<<endl;
    			return;
    		}
    	}
    }
    if(x==true)
    {
    	cout<<0<<endl;
    	return;
    }
    vector<ll>diff;
    for(ll i=0;i<n-1;i++)
    {
    	diff.push_back(arr[i+1]-arr[i]);
    }
    // __print(diff);
    sort(all(diff));
    if(diff[0] == diff[n-2])
    {
    	cout<<0<<endl;
    	return;
    }
    // __print(diff);
    for(ll i=0;i<n-2;i++)
    {
    	if(((diff[i]<0) && (diff[i+1]<0)) || ((diff[i]>0) && (diff[i+1]>0)))
    	{
    		if(diff[i] != diff[i+1])
    		{
    			// cout<<i<<endl;
    			cout<<-1<<endl;
    			return;
    		}
    	}
    }
    ll m = abs(diff[0])+abs(diff[n-2]);
    ll c = diff[n-2];
    // cout<<m<<" "<<c<<endl;
    if(arr[0]>=m)
    {
    	cout<<-1<<endl;
    	return;
    }
    for(ll i=1;i<n;i++)
    {
    	if(((arr[i-1]+c)%m) == arr[i])
    	{
    		continue;
    	}
    	else{
    		cout<<-1<<endl;
    		return;
    	}
    }
    cout<<m<<" "<<c<<endl;
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
        // cout<<endl;
    }
    return 0;
}