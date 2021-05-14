#include <bits/stdc++.h>
#include <algorithm>
using namespace std;


#define fast                          \
    ios_base::sync_with_stdio(false); \
    cout.tie(NULL);                   \
    cin.tie(NULL);


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

vll dist;

long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

void dfs1(ll u,ll par)
{
	if(par != -1)
	{
		dist[u] = dist[par]+ 1;
	}
	for(auto v:adj[u])
	{
		if(v!=par)
		{
			dfs1(v,u);
		}
	}
}


void solve2(ll n)
{
	ans = n;
	dist.resize(n,0);
	for(int i=0;i<n;i++)
	{
		dist[i]=0;
		dfs1(i,-1);
		// __print(dist);
		for(int j=i+1;j<n;j++)
		{
			ll x = dist[j] -1;
			// __print(i,j,x);nl();
			ans+= binpow(2,x,MOD);
			ans%=MOD;
		}	
	}
	cout<<ans%MOD<<endl;
}

/*
1.check for ll for all variables. 
2.check brackets in all equation and order of conditions.
3.check custom compare funtions if any.
4.check logic carefully.
5.Dont get stuck on one approch.
*/

int main()
{
    fast;
    ll tc = 1;
    IN tc;
    while (tc--)
    {
    	ll n;
	    cin>>n;
	    for(int i=0;i<n+3;i++)
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
        solve2(n);
        //cout.flush();
    }
    return 0;
}