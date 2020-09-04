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
const int  MAX= 100002;

vector<ll> dijsktras(int start, vector<pll>adj[],int n)
{
	vector<ll>dist(n+1,100000000000000LL);
	dist[start]=0;
	set<pll>q;
	q.insert({0,start});
	while(!q.empty())
	{
		int curr = q.begin()->second;
		q.erase(q.begin());
		for(auto j:adj[curr])
		{
			ll to = j.first;
			ll len = j.second;
			if(dist[curr]+len<dist[to])
			{
				q.erase({dist[to],to});
				dist[to]=dist[curr]+len;
				q.insert({dist[to],to});
			}
		}
	}
	return dist;
}

void solve()
{
	ll n,m;
    cin>>n>>m;
    vector<pll>adj[n+1];
	vector<pll>radj[n+1];
    for(int i=0;i<m;i++)
    {
    	ll a,b,c;
    	cin>>a>>b>>c;
    	adj[a].push_back({b,c});
    	radj[b].push_back({a,c});
    }
    vector<ll>dist=dijsktras(1,adj,n);
    vector<ll>rdist=dijsktras(n,radj,n);
    ll ans=LLONG_MAX;
    for(int i=1;i<=n;i++)
    {
    	for(auto j:adj[i])
    	{
    		int to =j.first;
    		ans= min(dist[i]+rdist[to]+(j.second/2),ans);	
    	}
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