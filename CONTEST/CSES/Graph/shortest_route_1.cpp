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
const ll MAX= 100000000000000LL;
ll n,m;
vector<pll>adj[100002];
vector<ll>ans;

void disktra(int start)
{
	ans = vll(n,(MAX));
	ans[start]=0;
	set<pll>q;
	q.insert({0,start});
	while(!q.empty())
	{
		int v = q.begin()->second;
		q.erase(q.begin());
		for(auto j: adj[v])
		{
			int to = j.first;
			ll len = j.second;
			if(ans[v]+len<ans[to])
			{
				q.erase({ans[to],to});
				ans[to]=ans[v]+len;
				q.insert({ans[to],to});
			}
		}
	}
}

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
	disktra(0);
	for(int i=0;i<n;i++)
	{
		cout<<ans[i]<<" ";
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