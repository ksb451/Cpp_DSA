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

void solve()
{
	ll n,k;
    cin>>n>>k;
    vector<ll>arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    vector<pll>H(n);
	H[0].first = arr[0];
	H[0].second = arr[0];
	for(int i=1;i < n;i++)
	{
		ll low = 0;
		ll high = INT_MAX;
		low = max(low, arr[i]);
		high = min(high, arr[i]+ k-1);
		if(i==n-1)
		{
			low = arr[i];
			high = arr[i];
		}
		low = max(low, H[i-1].first-k+1);
		high = min(high, H[i-1].second+k-1);
		if(low>high)
		{
			cout<<"NO"<<endl;
			return;
		}
		H[i].first = low;
		H[i].second = high;
	}	
	cout<<"YES"<<endl;
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