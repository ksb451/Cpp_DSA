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
const ll MAXN = 2e5+5LL;
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
	ll n;
	cin>>n;
	ll ans=0;
	vector<ll>zeros(32,0);
	vector<ll>ones(32,0);
	for(int i=0;i<n;i++)
	{
		ll x;
		cin>>x;
		for(int j=0;j<32;j++)
		{
			if(x&(1LL<<j))
			{
				ones[j]++;
			}
			else{
				zeros[j]++;
			}
		}
	}
	for(int i=0;i<32;i++)
	{
		ans+=(binpow(2,ones[i]-1)*binpow(2,i)*binpow(2,zeros[i]));
		ans%=M;
	}
	cout<<ans<<endl;
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