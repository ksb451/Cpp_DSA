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

class DSU{
private:
	int N;
	vector<int>par;
	vector<int>sz;
public:
	DSU(int n)
	{
		N=n;
		par.clear();
		for(int i=0;i<n;i++)
		{
			par.push_back(i);
		}
		sz=vector<int>(n,1);
	}

	int find(int x)
	{
		int t=x;
		while(par[t]!=t)
		{
			t=par[t];
		}
		while(x!=par[x])
		{
			int a=par[x];
			par[x]=t;
			x=a;
		}
		return t;
	}

	void merge(int x,int y)
	{
		int a = find(x);
		int b = find(y);
		if(a==b)
		{
			return;
		}
		else{
			if(sz[a]<=sz[b])
			{
				par[a]=b;
				sz[b]+=sz[a];
				N--;
			}
			else{
				par[b]=a;
				sz[a]+=sz[b];
				N--;	
			}
		}
	}
	int total_components()
	{
		return N;
	}
};


const int MAXN=1e5;
const ll MAX_LEN = 1e15;
ll n, m;
vector<ll>adj[MAXN];
vector<vector<ll>>edge;
//vector<pll>adj[MAXN];
vector<int>vis;

void dfs(int u)
{
    vis[u]=1;
    for(auto v :adj[u])
    {
        if(!vis[v])
        {
            dfs(v);
        }
    }
    vis = vector<int>(n,0);
}

bool mycompare(vector<ll>&a, vector<ll>&b)
{
	return a[0]<b[0];
}

void solve()
{
    cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		ll a,b,c;
		cin>>a>>b>>c;
		a--,b--;
		edge.push_back({c,a,b});
	}
	sort(all(edge), mycompare);
	ll ans = 0;
	DSU S(n);
	for(int i=0;i<edge.size();i++)
	{
		if(S.find(edge[i][1]) == S.find(edge[i][2]))
		{
			continue;
		}
		else{
			ans+=edge[i][0];
			S.merge(edge[i][1], edge[i][2]);
		}
	}
	if(S.total_components() != 1)
	{
		cout<<"IMPOSSIBLE"<<endl;
		return;
	}
	cout<<ans<<endl;
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