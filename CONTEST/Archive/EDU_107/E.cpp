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

ll white;
ll ans;
ll n,m;
void dfs(ll x, ll y, vector<vector<ll>>&visited, vector<string>&arr)
{
	visited[x][y]=1;
	for(int i=0;i<4;i++)
	{
		ll xx = x+ dir4[i][0];
		ll yy = y+ dir4[i][1];
		if((xx<0) || (xx>=n) || (yy<0) || (yy>=m))
		{
			continue;
		}
		else{
			if(arr[xx][yy]=='o')
			{
				ans++;
				if((visited[xx][yy]==0))
				{
					dfs(xx,yy,visited,arr);
				}
			}
		}
	}
}

long long binpow(long long a, long long b, long long m=M) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

void solve()
{
    cin>>n>>m;
    vector<string>arr(n);
    for(int i=0;i<n;i++)
    {
    	cin>>arr[i];
    }
    ans=0;
    white=0;
    vector<vector<ll>>visited(n,vector<ll>(m,0));
    for(int i=0;i<n;i++)
    {
    	for(int j=0;j<m;j++)
    	{
    		if(arr[i][j]=='o')
    		{
    			white++;
	    		if(!visited[i][j])
	    		{
	    			dfs(i,j, visited, arr);
	    		}
    		}
    	}
    }
    ans/=2;
    white -= 2;
    //cout<<white<<endl;
    ans  = (ans* (binpow(2,white)))%M;
    cout<<ans<<endl;
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