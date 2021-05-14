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
#define all(a) (a).begin(), (a).end()
#define allr(a) (a).rbegin(), (a).rend()
#define pb push_back

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

const ll MAXN = 300005;

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



vll adj[MAXN];
vll ans;
ll A;
vector<tuple<ll ,ll ,ll,ll>>arr[MAXN];

bool cmp(tuple<ll,ll,ll,ll>&a,tuple<ll,ll,ll,ll>&b)
{
	if((get<0>(a)) > (get<0>(b)))
	{
		return true;
	}
	else if((get<0>(a)) == (get<0>(b)))
	{
		if((get<1>(a)) > (get<1>(b)))
		{
			return true;
		}
		else if((get<1>(a)) == (get<1>(b)))
		{
			if((get<2>(a)) > (get<2>(b)))
			{
				return true;
			}
		}
	}
	return false;
}

tuple<ll,ll,ll,ll> dfs(ll u, ll par)
{
	ll a=1;
	ll b=adj[u].size()-1;
	ll c=0;
	for(auto v:adj[u])
	{
		if(v!=par)
		{
			auto p = dfs(v,u);
			a += (get<0>(p));
			b = max(b,get<1>(p));
			c = max(c,get<2>(p));
			arr[u].push_back(p);
		}
	}
	sort(all(arr[u]),cmp);
	return {a,b,c+1,u};
}

void dfs1 (ll u, ll par)
{
	ll x = ans[u];
	ll i=1;
	for(auto p:arr[u])
	{
		ans[get<3>(p)] = x*i;
		A+=(x*i);
		//__print(get<2>(p),x*i);nl();
		A%=MOD;
		i++;
	}
	for(auto v:adj[u])
	{
		if(v!=par)
		{
			dfs1(v,u);
		}
	}
}

void solve()
{
	ll n,x;
    cin>>n>>x;
    for(int i=0;i<n+4;i++)
    {
    	adj[i].clear();
    	arr[i].clear();
    }
    for(int i=0;i<n-1;i++)
	{
		int a,b;
		cin>>a>>b;
		a--,b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	A=x;
	A%=MOD;
	ans = vll(n,0);
	ans[0]=x;
	dfs(0,-1);
	dfs1(0,-1);
	cout<<A%MOD<<endl;
}

int main()
{
    fast;
    ll tc = 1;
    IN tc;
    while (tc--)
    {
        solve();
        cout.flush();
    }
    return 0;
}