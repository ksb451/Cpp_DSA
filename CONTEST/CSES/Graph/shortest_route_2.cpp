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
const ll INF = ll(1e15);
ll n, m ,q;

void solve()
{
    cin>>n>>m>>q;
    vector<vll> adj(n,(vll(n,INF))); 
    for(int i=0;i<m;i++)
    {
    	ll a,b,c;
    	cin>>a>>b>>c;
    	a--,b--;
    	adj[a][b]=min(adj[a][b],c);
    	adj[b][a]=min(adj[b][a],c);
    }
    for(int i=0;i<n;i++)
    {
    	adj[i][i]=0;
    }
    for(int k=0;k<n;k++)
    {
    	for(int i = 0;i<n;i++)
    	{
    		for(int j=0;j<n;j++)
    		{
    			if(adj[i][k]<INF && adj[k][j]<INF)
    			{
    				adj[i][j]=min(adj[i][j],adj[i][k]+adj[k][j]);
    			}
    		}
    	}
    }
    while(q--)
    {
    	ll a,b;
    	cin>>a>>b;
    	a--;b--;
    	if(adj[a][b]<INF)
    	{
    		cout<<adj[a][b]<<endl;
    	}
    	else{
    		cout<<-1<<endl;
       	}
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