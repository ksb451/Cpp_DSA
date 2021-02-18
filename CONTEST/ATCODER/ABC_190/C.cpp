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
ll n,m;
ll k;
ll ans;
vector<ll>S;

void rec(ll i, vector<pll>&pep, vector<pll>&test)
{
	if(i==k)
	{
		ll x=0;
		for(int j=0;j<m;j++)
		{
			if((S[test[j].first] > 0) && (S[test[j].second] > 0))
			{
				x++;
			}
		}
		ans=max(x,ans);
		return;
	}
	else{
		S[pep[i].first]++;
		rec(i+1, pep, test);
		S[pep[i].first]--;
		S[pep[i].second]++;
		rec(i+1, pep, test);
	}
}

void solve()
{
    cin>>n>>m;
    S = vector<ll>(n+1,0);
    vector<pll>test(m,{0,0});
    for(int i=0;i<m;i++)
    {
    	cin>>test[i].first>>test[i].second;
    }
    cin>>k;
    vector<pll>pep(k,{0,0});
   	for(int i=0;i<k;i++)
    {
    	cin>>pep[i].first>>pep[i].second;
    }
    ans=0;
    rec(0, pep,test);
    cout<<ans<<endl;
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