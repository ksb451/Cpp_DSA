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
const ll MAXN=2501;
ll n, m;
vector<pll>adj[MAXN];
vector<ll>adj2[MAXN];
ll d[MAXN];
ll ans[MAXN];
bool vis1[MAXN],vis2[MAXN];

void dfs1(ll curr)
{
	vis1[curr]=1;
	for(auto j:adj[curr])
	{
		if(!vis1[j.first])
			dfs1(j.first);
	}
}

void dfs2(ll curr)
{
	vis2[curr]=1;
	for(auto j:adj2[curr])
	{
		if(!vis2[j])
			dfs2(j);
	}
}

void solve()
{
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
    	ll a,b,c;
    	cin>>a>>b>>c;
    	a--,b--;
    	adj[a].push_back({b,c});
    	adj2[b].push_back(a);
    }
    fill_n(d,MAXN,-1e15);
    memset(vis1, 0,sizeof(vis1));
    memset(vis2, 0,sizeof(vis2));
    //vis1[0]=1;
    dfs1(0);
    //vis2[n-1]=1;
    dfs2(n-1);
    d[0]=0;
    for(int i=0;i<n;i++)
    {
    	for(int j=0;j<n;j++)
    	{
    		for(auto k:adj[j])
    		{
    			//cout<<i<<" "<<" "<<j<<" "<<k.first<<" "<<d[k.first]<<" "<<d[j]+k.second<<endl;
    			if(d[k.first]<d[j]+k.second)
    			{
    					if(i==n-1)
    					{
    						if(vis1[k.first]&&vis2[k.first])
    						{
    							cout<<-1<<endl;
    							return;
    						}
    					}
    					d[k.first]=d[j]+k.second;
    				}
    		}
    	}
    }
    cout<<d[n-1]<<endl;
    return;
}

int main()
{
    ll tc = 1;
    //IN tc;
    while (tc--)
    {
        solve();
    }
    return 0;
}