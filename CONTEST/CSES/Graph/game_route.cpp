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
//vector<pll>adj[MAXN];
vector<int>visited;
vector<int>S;
void dfs(int u)
{
	visited[u]=1;
	for(int v:adj[u])
	{
		if(visited[v]==0)
		{
			dfs(v);
		}
	}
	S.push_back(u);
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
	}
	S.clear();
	visited = vector<int>(n,0);
	
	for(int i=0;i<n;i++)
	{
		if(visited[i]==0)
		{
			dfs(i);
		}
	}
	reverse(all(S));
	vector<ll>dp(n,0);
	vector<int>curr;
	dp[0]=1;
	for(int i=0;i<n;i++)
	{
		int u=S[i];
		for(int v:adj[u])
		{
			dp[v]+=dp[u];
			dp[v]%=mod;
		}
	}
	cout<<dp[n-1]<<endl;
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