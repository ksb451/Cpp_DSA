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
const ll N = 102;
const ll MAX_C = 10005;
ll dp[N][MAX_C];
void solve()
{
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<MAX_C;j++)
		{
			dp[i][j]=-1e2;
		}
	}
	dp[0][0]=0;
	ll n;
    cin>>n;
    ll sum=0;
    for(int i=0;i<n;i++)
    {
    	ll a,b;
    	cin>>a>>b;
    	sum+=b;
    	for(int ii = i;ii>=0;ii--)
    	{
    		for(int s=0;s<MAX_C;s++)
    		{
    			if(s+a<MAX_C && dp[ii][s]>=0)
    			{
    				dp[ii+1][s+a] = max(dp[ii+1][s+a], dp[ii][s]+b);
    			}
    		}
    	}
    	cout<<endl<<endl;
    	for(int i=0;i<11;i++)
    {
    	for(int j=0;j<25;j++)
    	{
    		cout<<dp[i][j]<<"   ";
    	}
    	cout<<endl;
    }
    }
    
    for(int i=1;i<=n;i++)
    {
    	ld ans = 0;
    	for(int s=0;s<MAX_C;s++)
    	{
    		if(dp[i][s]<0)
    		{
    			continue;
    		}
    		else{
    			ans=max(ans,min((ld)s,(ld)(dp[i][s]+sum)*0.5));
    		}
    	}
    	cout<<ans<<" ";
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