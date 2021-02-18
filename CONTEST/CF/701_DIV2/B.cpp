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
	ll n,q,k;
    cin>>n>>q>>k;
    vector<ll>arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];

    vector<ll>beg(n,0);
	vector<ll>end(n,0);
	vector<ll>mid(n,0);

	for(int i=0;i<n;i++)
	{
		if(i==(n-1))
		{
			beg[i]=k-1;
		}
		else{
			ll x = arr[i+1];
			beg[i]=x-2;
		}
	}
	//write(beg);
	for(int i=1;i<n-1;i++)
	{
		ll x=arr[i-1];
		ll y = arr[i+1];
		mid[i]=y-x-2;
		mid[i]+=mid[i-1];
	}
	//write(mid);
	mid[n-1]+=mid[n-2];
	for(int i=0;i<n;i++)
	{
		if(i==0)
		{
			end[i]=k-1;
		}
		else{
			ll x = arr[i-1];
			end[i]=k-x-1;
		}
	}
	//write(end);
    while(q--)
    {
    	ll l,r;
    	
    	cin>>l>>r;
    	l--;r--;
    	if(l==r)
    	{
    		cout<<k-1<<endl;
    		continue;
    	}
    	ll ans=0;
    	ans+=beg[l];
    	ans+=end[r];
    	ans+=(mid[r-1]-mid[l]);
    	cout<<ans<<endl;
    }
    return;
}

int main()
{
    fast;
    ll tc = 1;
    //IN tc;
    while (tc--)
    {
        solve();
    }
    return 0;
}