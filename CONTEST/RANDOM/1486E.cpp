//**sn0wrus**//
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cout.tie(NULL);                   \
    cin.tie(NULL);
#define write(a)          \
    for (auto x : a)      \
    {                     \
        cout << x << " "; \
    }                     \
    cout << endl;
#define read(a)       \
    for (auto &x : a) \
    {                 \
        cin >> x;     \
    }
#define IN cin >>
#define OUT cout <<
#define endl "\n"
#define all(a) (a).begin(), (a).end()
#define allr(a) (a).rbegin(), (a).rend()
#define pb push_back
#define fi first;
#define se second;

using ll = long long int;
using ld = long double;
using pll = pair<ll, ll>;   
using pii = pair<int, int>;
using plll  = pair<ll,pll>;
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
const ll N = 100005;
vector<pll>adj[N];


void solve()
{
	ll n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
    	adj[i].clear();
    }
    for(int i=0;i<m;i++)
	{
	    ll a,b,c;
	    cin>>a>>b>>c;
	    a--,b--;
	    adj[a].push_back({b,c});
	    adj[b].push_back({a,c});
	}
	set<pll>S;
	vector<ll>ans(n,INT_MAX);
	ans[0]=0;
	S.insert({0,0});
	while(!S.empty())
	{
		ll curr = S.begin()->second;
		S.erase(S.begin());
		ll curr_cst = ans[curr];
		for(auto mid:adj[curr])
		{
			for(auto nxt:adj[mid.first])
			{
				ll cst = curr_cst+(mid.second+nxt.second)*(mid.second+nxt.second);
				if(cst<ans[nxt.first])
				{
					S.erase({ans[nxt.first],nxt.first});
					ans[nxt.first]=cst;
					S.insert({ans[nxt.first],nxt.first});
				}
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		if(ans[i]==INT_MAX)
		{
			cout<<-1<<" ";
		}
		else{
			cout<<ans[i]<<" ";
		}
	}
	cout<<endl;
	return;
}

int main()
{
    fast;
    ll tc = 1;
    //IN tc;
    while (tc--)
    {
        solve();
    }
    return 0;
}