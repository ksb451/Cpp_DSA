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
stack<int>S;
vector<int>rec_stack;
bool flag=true;
void dfs(int u)
{
	visited[u]=1;
	rec_stack[u]=1;
	for(int v:adj[u])
	{
		if(rec_stack[v]==1)
		{
			flag=false;
		}
		if(visited[v]==0)
		{
			dfs(v);
		}
	}
	rec_stack[u]=0;
	S.push(u);
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
	while(S.empty()==false)
	{
		S.pop();
	}
	visited = vector<int>(n,0);
	rec_stack = vector<int>(n,0);
	flag=true;
	for(int i=0;i<n;i++)
	{
		if(visited[i]==0)
		{
			dfs(i);
		}
	}
	if(flag)
	{
		while(S.empty()==false)
		{
			cout<<S.top()+1<<" ";
			S.pop();
		}
		cout<<endl;

		return;
	}
	cout<<"IMPOSSIBLE"<<endl;
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