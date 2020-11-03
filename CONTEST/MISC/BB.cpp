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

ll _sieve_size;
bitset<10000010> bs;
vi primes;

void sieve(ll upperbound) {

_sieve_size = upperbound + 1;

bs.set();

bs[0] = bs[1] = 0;
for (ll i = 2; i <= _sieve_size; i++) if (bs[i]) {

for (ll j = i * i; j <= _sieve_size; j += i) bs[j] = 0;
primes.push_back((int)i);

} }


bool isprime(ll N) {

if (N <= _sieve_size) return bs[N];

for (int i = 0; i < (int)primes.size(); i++)
	if (N % primes[i] == 0) return false;
	return true;
}

void solve()
{
	ll n;
    cin>>n;
    if(isprime(n))
    {
    	for(int i=0;i<n;i++)
    	{
    		for(int j=0;j<n;j++)
    		{
    			cout<<1<<" ";
    		}
    		cout<<endl;
    	}
    }
    else{
    	int x=n+1;
    	while(true)
    	{
    		if(isprime(x))
    		{
    			if(!isprime(x-n+1))
    				break;
    		}
    		x++;
    	}
    	int y=x-n+1;
    	int z=y*(n-1);
    	while(true)
    	{
    		if(isprime(z))
    		{
    			if(!isprime(z-y*(n-1)))
    				break;
    		}
    		z++;
    	}
    	z = z-y*(n-1); 
    	for(int i=0;i<n;i++)
    	{
    		for(int j=0;j<n;j++)
    		{
    			if(i==n-1&&j==n-1)
    			{
    				cout<<z<<" ";
    			}
    			else if(i==n-1 || j==n-1)
    			{
    				cout<<y<<" ";
    			}
    			else{
    				cout<<1<<" ";
    			}
    		}
    		cout<<endl;
    	}
    }
}

int main()
{
    fast;
    ll tc = 1;
    IN tc;
    sieve(10000);
    while (tc--)
    {
        solve();
    }
    return 0;
}