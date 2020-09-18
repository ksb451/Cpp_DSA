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

const int MAXN=2e5+5;
const ll MAX_LEN = 1e15;
ll n, m;
vector<ll>adj[MAXN];
//vector<pll>adj[MAXN];
vector<int>vis;
ll bin_lift[MAXN][32];

void solve()
{
	memset(bin_lift, -1,sizeof(bin_lift));
    cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		ll a;
		cin>>a;
		a--;
		bin_lift[i][0]=a;
	}
	for(ll i=1;(1LL<<i)<=1e9+2;i++)
	{
		for(int j=0;j<n;j++)
		{
			bin_lift[j][i]=bin_lift[bin_lift[j][i-1]][i-1];
		}
	}
	while(m--)
	{
		ll a,b;
		cin>>a>>b;
		int ans=a-1;
		for(int i=0;(1<<i)<=b;i++)
		{

			if(((1<<i)&b))
			{
				//cout<<i<<" ";
				ans= bin_lift[ans][i];
			}
		}
		cout<<ans+1<<endl;
	}

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