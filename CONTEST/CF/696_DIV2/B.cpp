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

const ll mxn=1e7;
vector<ll>prime;
void pre()
{
	vector<bool> is_prime(mxn+1,true);
	is_prime[0] = is_prime[1] = false;
	for (ll i = 2; i <= mxn; i++) {
	    if (is_prime[i] && (long long)i * i <= mxn) {
	        for (ll j = i * i; j <= mxn; j += i)
	            is_prime[j] = false;
	    }
	}
	for(ll i=2;i<mxn;i++)
	{
		if(is_prime[i])
		{
			prime.push_back(i);
		}
	}
}

void solve()
{
	ll n;
    cin>>n;
    ll ans=1;
    ll curr=1;
    ll z=1;
    //cout<<prime.size()<<endl;
    for(ll i=0;i<prime.size();i++)
    {
    	if(prime[i]>= (curr+n))
    	{
    		//cout<<prime[i]<<" ";
    		ans*=prime[i];
    		curr=prime[i];
    		z++;
    	}
    	if(z==3)
    	{
    		break;
    	}
    }
    cout<<ans<<endl;
}

int main()
{
    fast;
    ll tc = 1;
    IN tc;
    pre();
    while (tc--)
    {
        solve();
    }
    return 0;
}