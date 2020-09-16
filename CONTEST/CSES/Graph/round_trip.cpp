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
vector<int>ans;
vector<int>in_ans;
int dfs(int curr, int par)
{
	visited[curr] = 1;
	in_ans[curr] = 1;
	ans.push_back(curr);
	int x=-1;
	for(auto i:adj[curr])
	{
		if(visited[i]==1)
		{
			if((i!= par) && (par!=-1) && in_ans[i]==1)
			{
				return i;
			}
		}
		else{
				x= dfs(i,curr);
				if(x!=-1)
				{
					return x;
				}
			}
	}
	ans.pop_back();
	in_ans[curr] = 0;
	return -1;
}

void solve()
{
	ans.clear();
    cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		ll a,b;
		cin>>a>>b;
		a--,b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	visited = vector<int>(n,0);
	in_ans = std::vector<int> (n,0);
	int a=-1;
	for(int i=0;i<n;i++)
	{
		if(visited[i]==0)
		{
			ans.clear();
			a = dfs(i,-1);
			if(a!=-1)
			{
				break;
			}
		}
	}
	if(a==-1)
	{
		cout<<"IMPOSSIBLE"<<endl;
	}
	else{
		vector<int>f;
		bool flag=false;
		for(auto i:ans)
		{
			if(i==a)
			{
				flag=true;
			}
			if(flag)
				f.push_back(i);
		}
		cout<<f.size()+1<<endl;
		f.push_back(a);
		for(auto i: f)
		{
			cout<<i+1<<" ";
		}
		cout<<endl;
	}
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