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
#define fi first;
#define se second;

using ll = long long int;
using ld = long double;
using pll = pair<ll, ll>;   
using pii = pair<int, int>;
using plll  = pair<ll,pll>;
using vll = vector<ll>;
using vi = vector<int>;
const ll mod = (ll)(1e9) + 7LL;
const ll M = 998244353LL;
const ll MAXN = 200002;
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

ll fact[MAXN];

void factpre()
{
	fact[0] = 1;
	for (ll i = 1; i < MAXN; i++) {
	    fact[i] = fact[i - 1] * i % M;
	}
}

ll binpow(ll a,ll b, ll m=M) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

ll inv(ll i)
{
	return binpow(i ,M-2);
}

ll binomial_coefficient(int n, int k) {
    return fact[n] * inv(fact[k] * fact[n - k] % M) % M;
}

void solve()
{
	ll m,n,k;
	cin>>m>>n>>k;
	if(m==1)
	{
		ll tot = binpow(k,n);
		ll totinv = inv(tot);
		ll num = 0;
		for(ll i = 1;i<=n;i++)
		{
			ll ans= binomial_coefficient(n-1, i-1)*(k*binpow(k-1,i-1)%M)%M;
			num += ans*i;
			num%=M;
		}
		cout<<(num*totinv%M)<<endl;
	}
	else{
		ll dp[m*n];
		dp[0]=1;
		for(int i=1;i<(m*n);i++)
		{
			dp[i]=dp[i-1]+binpow(k-1, i);
			dp[i]%=M;
		}
		ll ttt = (((n+1)*(n+1)%M)-2)%M;
		ll tot = binpow(k,n*m%M);
		cout<<tot<<endl;
		ll totinv = inv(tot);
		ll num=0;
		for(ll i = 1;i<=(n*m);i++)
		{
			ll ans;
			if(i==1)
			{
				ans=1*k%M;
			}
			else if(i==2)
			{
				ans = binomial_coefficient((ttt), 1) * (k*(k-1)%M)%M;
			}
			else
			{
				ans= binomial_coefficient((ttt), i-1)*((k*(k-1)%M)*(binpow(k-2,i-2)%M)*(dp[i-2]))%M;
			}
			num += ans*i;
			num%=M;
		}
		cout<<num<<endl;
		cout<<(num*totinv%M)<<endl;
	}
	return;
}

int main()
{

    fast;
    ll tc = 1;
    factpre();
    //IN tc;
    while (tc--)
    {
        solve();
    }
    return 0;
}