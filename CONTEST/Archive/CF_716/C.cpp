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
// #define endl "\n"
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
    if(n<=4)
    {
    	cout<<1<<endl;
    	cout<<1<<endl;
    	return;
    }
    vector<ll>arr(n, 1);
    for(ll i=2;i<n;i++)
    {
    	if(arr[i])
    	{
	    	if((n%i)==0)
	    	{
	    		arr[i]=0;
	    		for(ll j= i;j<n;j+=i)
	    		{
	    			arr[j]=0;
	    		}
	    	}
    	}
    }
    ll x=1;
   	vector<ll>ans;
   	for(int i=1;i<n-1;i++)
   	{
   		if(arr[i])
   		{
   			x*=i;
   			x%=n;
   			ans.push_back(i);
   		}
   	}
   	if(x!=1)
   	{
   		ans.push_back(n-1);
   	}
   	cout<<ans.size()<<endl;
   	write(ans);
}

int main()
{
    fast;
    ll tc = 1;
    // IN tc;
    while (tc--)
    {
        solve();
    }
    return 0;
}