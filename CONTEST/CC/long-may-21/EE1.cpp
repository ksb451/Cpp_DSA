#include <bits/stdc++.h>
#include <algorithm>
using namespace std;


#define fast                          \
    ios_base::sync_with_stdio(false); \
    cout.tie(NULL);                   \
    cin.tie(NULL);

#define for0(i,n) for(int i=0;i<n;i++)
#define forn(i,n) for(int i=n-1;i>=0;i++)
#define IN cin >>
#define OUT cout <<
#define endl "\n"



using ll = long long int;
using ld = long double;
using pll = pair<ll, ll>;   
using pii = pair<int, int>;
using plll  = pair<ll,pll>;
using vll = vector<ll>;
using vi = vector<int>;

const ll MOD = (ll)(1e9) + 7LL;
const ll MM = 998244353LL;
const ll INF  = INT_MAX;

const ll MAXN = 100005;

vll adj[MAXN];
ll ans;


ll dfs(ll u, ll par=-1)
{
	ll curr = 1;
	ans++;
	ans%=MOD;
	ll wocurr=0;
	for(auto v:adj[u])
	{
		if(v!=par)
		{
			ll x = dfs(v,u);
			ans+=(x*wocurr);
			ans%=MOD;
			if(wocurr>0)
			{
				ans+=(x*wocurr);
				ans%=MOD;
			}
			ans+=x;
			ans%=MOD;
			wocurr+=x;
			curr+= (x*2);
		}
	}
	return curr;
}

void solve()
{
	ll n;
    cin>>n;
    for0(i,n+3)
    {
    	adj[i].clear();
    }
    for(int i=0;i<n-1;i++)
	{
	    int a,b;
	    cin>>a>>b;
	    a--,b--;
	    adj[a].push_back(b);
	    adj[b].push_back(a);
	}	
	ans=0;
	dfs(0);
	cout<<ans%MOD<<endl;
}

int main()
{
    fast;
    ll tc = 1;
    IN tc;
    while (tc--)
    {
    	
        solve();
        //cout.flush();
    }
    return 0;
}