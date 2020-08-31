/******************************************
* AUTHOR : Keshab Agrawal *
* NICK : sn0wrus *
******************************************/
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
#define write(a)          \
    for (auto x : a)      \
    {                     \
        cout << x << " "; \
    }                     \
    cout << nl;
#define read(a)       \
    for (auto &x : a) \
    {                 \
        cin >> x;     \
    }
using ll = long long int;
using ld = long double;
using pll = pair<ll, ll>;
using pii = pair<int, int>;
using vll = vector<ll>;
using vi = vector<int>;
const ll mod = (ll)(1e9) + 7LL;
const ll M = 988244353LL;

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
vector<int>adj[100005];
vector<int>visited;

int dfs(int curr)
{
	visited[curr]=true;
	int sz=1;
	for(int j:adj[curr])
	{
		if(visited[j]==false)
		{
			sz+=dfs(j);
		}
	}
	return sz;	
}

void solve()
{
	int n,m;
    cin>>n>>m;
    for(int i=0;i<n+3;i++)
    {
    	adj[i].clear();
    }
    for(int i=0;i<m;i++)
	{
	    int a,b;
	    cin>>a>>b;
	    a--,b--;
	    adj[a].push_back(b);
	    adj[b].push_back(a);
	}
	int ans=0;
	visited=vector<int>(n,false);
	for(int i=0;i<n;i++)
	{
		if(visited[i]==false)
		{
			int x=dfs(i);
			ans+=(x-1);
		}
	}
	cout<<(m-ans)<<endl;
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