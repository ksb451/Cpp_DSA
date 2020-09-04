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
ll n,m;
vector<int>adj[200002];
int visited[200002];

void dfs(int curr)
{
	visited[curr]=1;
	for(auto j:adj[curr])
	{
		if(!visited[j])
		{
			dfs(j);
		}
	}
}
void solve()
{
    cin>>n>>m;
    vector<ll>arr(n);
    for(int i=0;i<m;i++)
	{
    	int a,b;
    	cin>>a>>b;
    	//a--,b--;
    	adj[a].push_back(b);
    	adj[b].push_back(a);
	}
	memset(visited,0,sizeof(visited));
	vi ans;
	for(int i=1;i<=n;i++)
	{
		if(!visited[i])
		{
			ans.push_back(i);
			dfs(i);
		}
	}
	int sz=ans.size();
	cout<<sz-1<<endl;
	for(int i=0;i<sz-1;i++)
	{
		cout<<ans[i]<<" "<<ans[i+1]<<endl;
	}
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