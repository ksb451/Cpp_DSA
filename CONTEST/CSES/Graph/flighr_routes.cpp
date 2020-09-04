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
ll n, m;
vector<pll>adj[MAXN];
ll d[MAXN];
ll cnt[MAXN];
void solve()
{
	ll k;
    cin>>n>>m>>k;
	for(int i=0;i<m;i++)
	{
		ll a,b,c;
		cin>>a>>b>>c;
		a--,b--;
		adj[a].push_back({b,c});
	}
	fill_n(d,MAXN,1e15);
	fill_n(cnt,MAXN,0);
	multiset<pll>S;
	vector<ll>ans;
	S.insert({0,0});
	while((!S.empty())&&cnt[n-1]<=k)
	{
		ll j = S.begin()->second;
		ll dj= S.begin()->first;
		S.erase(S.begin());
		if(cnt[j]<=k)
			for(auto ed: adj[j])
			{
				ll to = ed.first;
				ll len = ed.second;
				//cout<<j<<" "<<to<<" "<<dj+len<<endl;
				if(to==n-1)
				{
					ans.push_back(dj+len);
				}
				S.insert({dj+len, to});
			}
		cnt[j]++;
	}
	sort(all(ans));
	for(int i=0;i<k;i++)
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