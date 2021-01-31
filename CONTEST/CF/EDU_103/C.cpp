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

void solve()
{
	ll n;
    cin>>n;
    vector<ll>arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    vector<ll>linkf;
	vector<ll>links;
	for(int i=0;i<n;i++)
	{
		ll a;
		cin>>a;
		linkf.push_back(a);
	}
	for(int i=0;i<n;i++)
	{
		ll a;
		cin>>a;
		links.push_back(a);
	}
	ll ans=0;
	ll cont=0;
	for(int i=1;i<n;i++)
	{
		ll a = arr[i];
		ll b = abs(linkf[i] - links[i]) + 1;
		ll curr  = a+b;
		//cout<<curr<<" "<<a<<" "<<b<<endl;
		if(b==1)
		{
			cont = curr;
			ans = max(curr,ans);
		}
		else{
			ans= max(curr,ans);
			ll curr_cont = (cont+a-b+2);
			//cout<<curr_cont<<endl;
			ans = max(ans,curr_cont);
			cont = max(curr, curr_cont);
		}
	}
	cout<<ans<<endl;
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