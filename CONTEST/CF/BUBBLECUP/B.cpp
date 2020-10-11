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
const ll maxn = 1000001;

ll dp[maxn];

void sieve()
{
	for(ll i=0;i<maxn;i++)
	{
		dp[i]=1;
	}
	dp[0]=0;
	dp[1]=0;
	for(ll i = 2;i<maxn;i++)
	{
		//cout<<dp[i]<<" ";
		if(dp[i]==1)
		{
			for(ll j=i*i;j<maxn;j+=i)
			{
				dp[j]=0;
			}
		}
	}
	for(ll i=1;i<maxn;i++)
	{
		dp[i]+=dp[i-1];
		//cout<<dp[i]<<" ";
	}
	//cout<<endl;
}
void solve()
{
	ll n;
    cin>>n;
    ll sq = sqrt(n);
    cout<<dp[n]-dp[sq]+1<<endl;
}

int main()
{
	sieve();
    fast;
    ll tc = 1;
    IN tc;
    while (tc--)
    {
        solve();
    }
    return 0;