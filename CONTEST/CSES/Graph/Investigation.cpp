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
ll MAX_LEN = 1e15;
ll n, m;
//vector<ll>adj[MAXN];
vector<pll>adj[MAXN];
vector<int>vis;
struct node{
	ll a;
	ll b;
	ll c;
};
void solve()
{
    cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		ll a,b,c;
		cin>>a>>b>>c;
		a--,b--;
		adj[a].push_back({b,c});
	}
	set<pair<ll, ll>>S;
	vector<node>info(n,{0,n+1,0});
	info[0]={1,1,1};
	vector<ll>dist(n,MAX_LEN);
	dist[0]=0LL;
	S.insert({0,0});
	while(!S.empty())
	{
		int curr = S.begin()->second;
		S.erase(S.begin());
		for(auto edge : adj[curr])
		{
			int v=edge.first;
			ll wt = edge.second;
			if(dist[v]>dist[curr]+wt)
			{
				S.erase({dist[v],v});
				dist[v] = dist[curr]+wt;
				S.insert({dist[v],v});
				ll a =info[curr].a;
				ll b =info[curr].b+1;
				ll c= info[curr].c+1;
				info[v]={a,b,c};
			}
			else if(dist[v]==dist[curr]+wt)
			{

				ll a =(info[v].a+info[curr].a)%mod;
				ll b = min(info[curr].b+1, info[v].b);
				ll c= max(info[curr].c+1,info[v].c);
				info[v]={a,b,c};
			}
		}
	}
	cout<<dist[n-1]<<" "<<info[n-1].a<<" "<<info[n-1].b-1<<" "<<info[n-1].c-1<<endl;
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