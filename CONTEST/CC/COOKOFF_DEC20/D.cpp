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
ll gcd (ll a, ll b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}
void solve()
{
	ll n,m;
    cin>>n>>m;
    vector<ll>arr(m);
    for(int i=0;i<m;i++)cin>>arr[i];
    if(n==1)
    {
    	cout<<0<<endl;
    	return;
    }
    else{
    	ll x=arr[0];
    	for(int i=1;i<m;i++)
    	{
    		x = gcd(x,arr[i]);
    	}
    	ll min_p = *min_element(all(arr));
    	ll ans = min(min_p,n);
    	if(x>ans)
    	{
    		set<ll> v;
    		for (ll i = 1; i <= sqrt(x); i++) 
    		{
        	if (x % i == 0) 
	        	{
	            	v.insert(i);
	            	v.insert(x/i);
	            }
        	}
            ll sm = *(--v.upper_bound(ans));
            ans = min(ans,sm);
            cout<<n-ans<<endl;
       	}
    	else{
    		cout<<n-x<<endl;
    	}
    }
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