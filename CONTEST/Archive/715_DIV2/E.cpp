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

ll MAX = (ll)1e18+2LL;

vector<ll>ans;
ll binpow(ll a, ll b)
{
	if(b>60)
	{
		return MAX;
	}
	ll res =1;
	while(b>0)
	{
		if(b&1)
			res *=a;
		a = a*a;
		b>>=1;
	}
	return res;
}

void rec(ll n,ll k)
{
	//cout<<n<<" "<<k<<endl;
	if(n==0 || k==0)
	{
		return;
	}
	for(int i=1;i<=n;i++)
	{
		ll curr;
		if(i==n)
		{
			curr=1;
		}
		else
			curr = binpow(2, n-i-1);
		if(curr >= k)
		{
			ans.push_back(i);
			rec(n-i, k);
			return;
		}
		else{
			k-=curr;
		}
	}	
}

void solve()
{
	ll n,k;
    cin>>n>>k;
    if(binpow(2, n-1) < k)
    {
    	cout<<-1<<endl;
    	return;
    }
    ans.clear();
    rec(n , k);
    ll s = 1;
    for(auto i:ans)
    {
    	ll x = s+i-1;
    	for(int j=x;j>=s;j--)
    	{
    		cout<<j<<" ";
    	}
    	s = x+1;
    }
    cout<<endl;
    //write(ans);
    return;
}

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