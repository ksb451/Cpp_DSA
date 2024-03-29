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
	ll n,k;
    cin>>n>>k;
    vector<ll>arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];

    ll l=1, r=n+1;
	while((r-l)>1)
	{
		ll m =(l+r)/2;

		vector<ll>b(n);
		for(int i=0;i<n;i++)
		{
			if(arr[i]<m)
			{
				b[i]=-1;
			}
			else{
				b[i]=1;
			}
		}
		for(int i=1;i<n;i++)
		{
			b[i]+=b[i-1];
		}
		ll mn = 0;
		ll mx = b[k-1];
		for(int i=k;i<n;i++)
		{
			mn = min(mn, b[i-k]);
			mx = max(mx, b[i]-mn);
		}
		if(mx>0)
		{
			l=m;
		}
		else{
			r=m;
		}
	}
	cout<<l<<endl;
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