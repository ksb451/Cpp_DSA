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
const int MAX_N = 1001;
vector<vector<int>>adj[MAX_N];
vector<vector<int>>edge;

void disktras()
{
	
}

void solve()
{
	for(int i=0;i<MAX_N;i++)
	{
		adj[i].clear();
	}
	edge.clear();
	ll n,m,k;
    cin>>n>>m>>k;

	for(int i=0;i<m;i++)
	{
	    int a,b,c;
	    cin>>a>>b>>c;
	    a--,b--;
	    adj[a].push_back({b,c,i});
	    adj[b].push_back({a,c,i});
	    edge.push_back({c,0});
	}
	while(k--)
	{
		int a,b;
		cin>>a>>b;
		disktras(a,b);
	}
}

int main()
{
    fast;
    ll tc = 1;
    IN tc;
    while (tc--)
    {
        solve();
    }
    return 0;
}