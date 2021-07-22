//**sn0wrus**//
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops, no-stack-protector")
#pragma GCC target("avx,avx2,fma")

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

const ll MAXN = 2e7+13;

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
  
// stores smallest prime factor for every number
ll mind[MAXN];
ll val[MAXN];	

// Calculating SPF (Smallest Prime Factor) for every
// number till MAXN.
// Time Complexity : O(nloglogn)
void sieve()
{
    mind[1] = 1;
    for (ll i=2; i<MAXN; i++)
        mind[i] = i;
    for (ll i=2; i*i<MAXN; i++)
    {
        if (mind[i] == i)
        {
            for (ll j=i*i; j<MAXN; j+=i)
                if (mind[j]==j)
                    mind[j] = i;
        }
    }
    val[1]=0;
    for(int i=2;i<MAXN;i++)
    {
    	int j = i/mind[i];
    	val[i] = val[j]+(mind[i]!=mind[j]);
    }

}
  

void solve()
{
	ll c,d,x;
	cin>>c>>d>>x;
	ll ans=0;
	for(ll i =1;i<=sqrt(x);i++)
	{
		if((x%i)==0)
		{
			ll gcd = i;
			if((((d*gcd)+x)%c)== 0)
			{
				ll lcm = ((d*gcd)+x)/c;
				// cout<<lcm<<" "<<gcd<<endl;
				if((lcm%gcd)==0)
					ans+=pow(2,val[lcm/gcd]);
			}
			gcd = x/i;
			if(gcd==i)
				continue;
			if((((d*gcd)+x)%c)== 0)
			{
				ll lcm = ((d*gcd)+x)/c;
				// cout<<lcm<<" "<<gcd<<endl;
				if((lcm%gcd)==0)
					ans+=pow(2,val[lcm/gcd]);
			}
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
    IN tc;
    sieve();
    while (tc--)
    {
        solve();
    }
    return 0;
}	