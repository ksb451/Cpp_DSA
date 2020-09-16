//**sn0wrus**//
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
#define all(a) (a).begin(), (a).end()
#define pb push_back
using ll = long long int;
using ld = long double;
using pll = pair<ll, ll>;
using pii = pair<int, int>;
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

const int MAXN=2e5;
const ll MAX_LEN = 1e15;
ll n, m;
vector<ll>adj[MAXN];
//vector<pll>adj[MAXN];
vector<int>dist;

void dfs(int u,int par,int x)
{
	dist[u]=x;
    for(auto v :adj[u])
    {
    	if(v == par)
    	{
    		continue;
    	}
        dfs(v,u,x+1);
    }
}

void solve()
{
    cin>>n;
	for(int i=0;i<n-1;i++)
	{
		ll a,b;
		cin>>a>>b;
		a--,b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dist = vector<int>(n);
	dfs(0,-1,0);
	int a=0;
	int b =0;
	for(int i=0;i<n;i++)
	{
		//cout<<dist[i]<<" ";
		if(dist[i]>a)
		{
			a=dist[i];
			b=i;
		}
	}
	//cout<<endl<<b<<endl;
	dfs(b,-1,0);
	for(int i=0;i<n;i++)
	{
		//cout<<dist[i]<<" ";
		if(dist[i]>a)
		{
			a=dist[i];
			b=i;
		}
	}
	//cout<<endl;
	cout<<a<<endl;
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