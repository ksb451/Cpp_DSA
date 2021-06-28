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
	ll n,k;
    cin>>n>>k;
    ll ans=0;
    if((n%k)  == 0)
    {
    	for(int i=0;i<(n/k);i++)
    	{
    		cout<<"? ";
    		for(int j=0;j<k;j++)
    		{
    			cout<<(i*k+j+1)<<" ";
    		}
    		cout<<endl;
    		cout.flush();
    		ll x;
    		cin>>x;
    		ans^=x;
    	}
    	cout<<"! "<<ans<<endl;
    	return;
    }
    else{
    	ans=0;
    	ll step = INT_MAX;
    	ll KK,I;
    	for(int i=1;i<k;i++)
    	{
    		for(int kk=1;;kk+=2)
    		{
    			ll tot = i + (k-i)*kk;
    			if(tot > n)
    			{
    				break;
    			}
    			if(((n-tot)%k)==0)
    			{
    				ll steps = ((n-tot)/k)+kk;
    				if(steps < step)
    				{
    					step = steps;
    					I=i;
    					KK=kk;
    				}
    			}
    		}
    	}
    	if(step==INT_MAX)
    	{
    		cout<<-1<<endl;
    		return;
    	}

    	// cout<<step<<endl;
    	// cout<<I<<" "<<KK<<endl;
    	ll carr=I+1;
    	for(int i=0;i<KK;i++)
    	{
    		cout<<"? ";
    		for(int q=1;q<=I;q++)
    		{
    			cout<<q<<" ";
    		}
    		for(int q=I+1;q<=k;q++)
    		{
    			cout<<carr<<" ";
    			carr++;
    		}
    		cout<<endl;
    		cout.flush();
    		ll x;
    		cin>>x;
    		ans^=x;
    	}
    	for(int q=0;q<(step-KK);q++)
    	{
    		cout<<"? ";
    		for(int qq=0;qq<k;qq++)
    		{
    			cout<<carr<<" ";
    			carr++;
    		}
    		cout<<endl;
    		cout.flush();
    		ll x;
    		cin>>x;
    		ans^=x;
    	}
    	cout<<"! "<<ans<<endl;
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