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

#define fi first
#define se second

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x ;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}'<<endl;}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}"<<endl;}

using ll = long long int;

using ld = long double;
using pll = pair<ll, ll>;   
using pii = pair<int, int>;
using plll  = pair<ll,pll>;
using vll = vector<ll>;
using vi = vector<int>;

const ll MOD = (ll)(1e9) + 7LL;
const ll MM = 998244353LL;
const ll INF  = INT_MAX;

const int dir8[8][2]={{1,0},{0,1},{-1,0},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};

const ll MAXN = 200005;

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
ll n, m;
const int dir4[4][2]={{1,0},{0,1},{-1,0},{0,-1}};

ll dfs(ll x, ll y, vector<vector<ll>>&vis, vector<vector<ll>>&arr)
{
	vis[x][y]=1;
	ll ans=1;
	for(int i=0;i<4;i++)
	{
		ll xx =x+ dir4[i][0];
		ll yy =y+ dir4[i][1];
		if((xx>=0)&&(xx<n)&&(yy>=0)&&(y<m))
		{
			if((vis[xx][yy]==0) && arr[xx][yy]==1)
			{
				ans+=dfs(xx,yy,vis,arr);
			}
		}
	}
	return ans;
}

void solve()
{
    cin>>n>>m;
    vector<vector<ll>>arr(n,vector<ll>(m));
    for(int i=0;i<n;i++)
    {
    	for(int j=0;j<m;j++)
    	{
			cin>>arr[i][j];
    	}
    }
	unordered_map<ll,ll>um;
	vector<vector<ll>>visited(n,vector<ll>(m,0));
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(visited[i][j]==0 && arr[i][j]==1)
			{
				um[dfs(i,j,visited,arr)]++;
			}
		}
	}
	ll q;
	cin>>q;
	while(q--)
	{
		ll x;
		cin>>x;
		cout<<um[x]<<endl;
	}
	
}

int main()
{
    solve();
    return 0;
}