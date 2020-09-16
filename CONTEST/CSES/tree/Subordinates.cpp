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
vector<int>sub;

int dfs(int u,int par)
{
	sub[u]=0;
    for(auto v :adj[u])
    {
        if(v==par)
        {
        	continue;
        }
        sub[u]+=dfs(v,u);
    }
    return sub[u]+1;
}

void solve()
{
    cin>>n;
	for(int i=0;i<n-1;i++)
	{
		ll a;
		cin>>a;
		a--;
		adj[a].push_back(i+1);
		adj[i+1].push_back(a);
	}
	sub = vector<int>(n,0);
	sub[0]=dfs(0,-1)-1;
	for(auto i: sub)
	{
		cout<<i<<" ";
	}
	cout<<endl;
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