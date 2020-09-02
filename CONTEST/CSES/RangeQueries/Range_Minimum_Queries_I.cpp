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

const ll MAXN = 200005;
const ll K=25;
ll spt[MAXN][25];
ll lg[MAXN];
void solve()
{
	lg[1]=0;
	for(int i=2;i<MAXN;i++)
	{
		lg[i]=lg[i/2]+1;
	}
	ll n;
	ll q;
	cin>>n>>q;
	std::vector<int> arr(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
		spt[i][0]=arr[i];
	}
	for(int j=1;j<K;j++)
	{
		for(int i=0;i+(1<<j)<=n;i++)
		{
			spt[i][j]=min(spt[i][j-1],spt[i+(1<<(j-1))][j-1]);
		}
	}
	while(q--)
	{
		ll a, b;
		cin>>a>>b;
		a--,b--;
		int j = lg[b-a+1];
		ll minimum = min(spt[a][j],spt[b-(1<<j)+1][j]);
		cout<<minimum<<endl;
	}
}

int main()
{
	lg[1]=0;
	for(int i=2;i<MAXN;i++)
	{
		lg[i]=lg[i/2]+1;
	}
    ll tc = 1;
    //IN tc;
    while (tc--)
    {
        solve();
    }
    return 0;
}

