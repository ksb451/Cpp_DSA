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

void solve()
{
	ll n;
    cin>>n;
    vector<ll>arr(n);
    for(ll i=0;i<n;i++)cin>>arr[i];
    vector<vector<ll>>dp(32, vector<ll>(n,0));
	for(ll i=0;i<32;i++)
	{
		for(ll j=0;j<n;j++)
		{
			if(arr[j]&(1LL<<i))
			{
				dp[i][j]=0;
			}
			else{
				dp[i][j]=(arr[j]|(1LL<<i))-(arr[j]);
			}
			//cout<<dp[i][j]<<" ";
			if(j>0)
			{
				dp[i][j]+=dp[i][j-1];
			}
		}
		//cout<<endl;
	}
	ll q;
	cin>>q;
	while(q--)
	{
		ll l, r;
		cin>>l>>r;
		l--;
		r--;
		ll ans = 1e15;
		for(ll i=0;i<32;i++)
		{
			if(l==0)
			{
				ans = min(ans,dp[i][r]);
			}
			else{
				ans = min(ans,dp[i][r]-dp[i][l-1]);
			}
		}
		cout<<ans<<endl;
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