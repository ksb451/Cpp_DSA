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

void solve()
{
	ll n,m;
    cin>>n>>m;
    string a,b;
    cin>>a>>b;
    vector<vector<ll>>dp(n+1,vector<ll>(m+1,0));
    ll ans=0;
    for(int i=0;i<=n;i++)
    {
    	for(int j=0;j<=m;j++)
    	{
    		if((i==0)||(j==0))
    		{
    			dp[i][j]=0;
    		}
    		else{
    			if(a[i-1] == b[j-1])
    			{
    				dp[i][j] = max(dp[i][j],2 + dp[i-1][j-1]);
    			}
    			else{
    				dp[i][j] = max(dp[i][j], max(dp[i][j-1], dp[i-1][j])-1);
    			}
    		}
    		ans=max(ans,dp[i][j]);
    	}
    }
    // for(int i=0;i<=n;i++)
    // {
    // 	for(int j=0;j<=m;j++)
    // 	{
    // 		cout<<dp[i][j]<<" ";
    // 	}
    // 	cout<<endl;
    // }
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