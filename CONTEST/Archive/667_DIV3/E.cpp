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
	ll n,k;
    cin>>n>>k;
    map<int,int>um;
    for(int i=0;i<n;i++)
    {
    	int a;
    	cin>>a;
    	um[a]++;
    }
    auto i=
    vector<int>xpoints(mx+1,0);
    for(int i=0;i<=mx;i++)
    {
    	xpoints[i]=um[i];
    	if(i>0)
    	{
    		xpoints[i]+=xpoints[i-1];
    	}
    }
    int curr_max=0;
    vector<int>dp(mx+1,0);
    int ans=0;
    for(int i=mx-k;i>=0;i--)
    {
    	int curr;
    	if(i==0)
    	{
    		 curr=xpoints[i+k];
    	}
    	else
    		 curr=xpoints[i+k]-xpoints[i-1];
    	curr_max=max(curr,curr_max);
    	dp[i]=curr_max;

    	int max_next=0;
    	if(i+k+1<=mx)
    	{
    		max_next=dp[i+k+1];
    	}
    	ans=max(curr+max_next,ans);
    }
    cout<<ans<<endl;
}

int main()
{
    ll tc = 1;
    IN tc;
    while (tc--)
    {
        solve();
    }
    return 0;
}