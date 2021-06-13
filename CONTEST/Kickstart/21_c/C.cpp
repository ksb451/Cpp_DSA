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

ll w,e;

ll exp(ll cc, ll ri, ll pi, ll si)
{
	if(cc==1)
	{
		return ((e*ri) + (0*pi) + (w*si));
	}
	if(cc==2)
	{
		return ((w*ri) + (e*pi) + (0*si));
	}
	if(cc==3)
	{
		return ((0*ri) + (w*pi) + (e*si));
	}
}

ld cal(string &s)
{
	ll pi=0,ri=0,si=0;
	ld ans= (ld)(w+e)/(ld)3 ;
	ll cnt=1;
	for(auto i:s)
	{
		if(i=='R')
		{
			ll q=exp(1,ri,pi,si);
			ans+=(ld)(q)/(ld)cnt;
			pi++;
		}
		if(i=='S')
		{
			ll q=exp(3,ri,pi,si);
			ans+=(ld)(q)/(ld)cnt;
			ri++;
		}
		if(i=='P')
		{
			ll q=exp(2,ri,pi,si);
			ans+=(ld)(q)/(ld)cnt;
			si++;
		}
		cnt++;
	}
	return ans;
}

void solve(ll x)
{
    cin>>w>>e;
   	
    string ans;
    ld expec=0;
    for(int i=0;i<1000;i++)
    {
    	string curr="";
    	for(int j=0;j<60;j++)
    	{
    		ll q = rand()%3 + 1;
    		if(q==1)
    		{
    			curr+='S';
    		}
    		if(q==2)
    		{
    			curr+='R';	
    		}
    		if(q==3)
    		{
    			curr+='P';
    		}
    	}
    	ld temp = cal(curr);
    	if(temp > expec)
    	{
    		expec = temp;
    		ans = curr;
    	}
    }
    cout<<expec<<endl;
    cout<<ans<<endl;
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
    ll x;
    IN tc;
    cin>>x;
    while (tc--)
    {
        solve(x);
        cout.flush();
    }
    return 0;
}