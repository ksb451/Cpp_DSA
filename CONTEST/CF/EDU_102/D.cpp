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
const ll MAXN = 200005;
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


ll logn[MAXN+1];
void pre()
{
logn[1] = 0;
for (int i = 2; i <= MAXN; i++)
    logn[i] = logn[i/2] + 1;
}

void solve()
{
	ll n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    vector<ll>arr;
    ll x=0;
    for(int i=0;i<n;i++)
    {
    	if(s[i]=='+')
    	{
    		x++;
    	}
    	else{
    		x--;
    	}
    	arr.push_back(x);
    	//cout<<arr[i]<<" ";
    }
    //cout<<endl;
    ll k =logn[n]+1;
    ll st[n+1][k+1];
    for (int i = 0; i < n; i++)
    st[i][0] = arr[i];

	for (int j = 1; j <= k; j++)
	    for (int i = 0; i + (1 << j) <= n; i++)
	        st[i][j] = min(st[i][j-1], st[i + (1 << (j - 1))][j - 1]);

	ll st1[n+1][k+1];
    for (int i = 0; i < n; i++)
    st1[i][0] = arr[i];

	for (int j = 1; j <= k; j++)
	    for (int i = 0; i + (1 << j) <= n; i++)
	        st1[i][j] = max(st1[i][j-1], st1[i + (1 << (j - 1))][j - 1]);

    while(m--)
    {
    	ll l,r;
    	cin>>l>>r;
    	l--;r--;
    	ll mn=0;
    	ll mx =0;

    	if(l>0)
    	{
    		ll L=0;
    		ll R=l-1;
    		ll j = logn[R - L + 1];
			ll minimum = min(st[L][j], st[R - (1 << j) + 1][j]);
			ll maximum = max(st1[L][j], st1[R - (1 << j) + 1][j]);
			//cout<<1<<" "<<L<<" "<<R<< " "<<" "<<minimum<<" "<<maximum<<endl;
			mn = min(mn, minimum);
			mx = max(mx,maximum);
    	}
    	if(r<n-1)
    	{
    		ll L=r+1;
    		ll R=n-1;
    		ll j = logn[R - L + 1];
			ll minimum = min(st[L][j], st[R - (1 << j) + 1][j]);
			ll maximum = max(st1[L][j], st1[R - (1 << j) + 1][j]);
			//cout<<2<<" "<<L<<" "<<R<< " "<<" "<<minimum<<" "<<maximum<<endl;
			ll dec  = arr[r]-minimum;
			ll inc = maximum - arr[r];

			ll val = (l>0)?arr[l-1]:0;
			mx = max(mx, val+inc);
			mn = min(mn, val-dec);
    	}

		ll ans= mx-mn+1;
		cout<<ans<<endl;

    }
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