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

const int MAXN=1e5;
const ll MAX_LEN = 1e15;
ll n, m;
vector<ll>adj[MAXN];
vector<ll>adj2[MAXN];
vector<ll>comp[MAXN];
vector<ll>comp2[MAXN];
//vector<pll>adj[MAXN];
vector<int>vis;
vector<int>vis2;
vector<int>S;
void dfs1(int u)
{
    vis[u]=1;
    for(auto v :adj[u])
    {
        if(!vis[v])
        {
            dfs1(v);
        }
    }
    S.push_back(u);
}

void dfs2(int u, int r)
{
    vis[u]=r;
    for(auto v :adj2[u])
    {
        if(vis[v]==-1)
        {
            dfs2(v,r);
        }
    }
}

void solve()
{
    cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		ll a,b;
		cin>>a>>b;
		a--,b--;
		adj[a].push_back(b);
		adj2[b].push_back(a);
	}
	vis = vector<int>(n,0);
	S.clear();
	for(int i=0;i<n;i++)
	{
		if(!vis[i])
		{
			dfs1(i);
		}
	}
	vis = vector<int>(n,-1);
	int rpr=0;
	reverse(all(S));
	for(auto curr:S)
	{
		if(vis[curr]==-1)
		{
			dfs2(curr,rpr);
			rpr++;
		}
	}
	cout<<rpr<<endl;
	for(auto i:vis)
	{
		cout<<i+1<<" ";
	}
	cout<<endl;
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