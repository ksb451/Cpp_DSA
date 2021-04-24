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
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}


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
const int dir4[4][2]={{1,0},{0,1},{-1,0},{0,-1}};

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

ll vert[500][500];
ll hor[500][500];


ll exhibit(ll x, ll xx, ll y, ll yy)
{
	if(x==xx)
	{
		// cout<< hor[x][min(y,yy)]<<endl;
		return hor[x][min(y,yy)];
	}
	else{
		// cout<<vert[min(x,xx)][y]<<endl;
		return vert[min(x,xx)][y];
	}
}

void solve()
{
	ll n,m,kk;
    cin>>n>>m>>kk;    
    for(int i=0;i<n;i++)
    {
    	for(int j=0;j<m-1;j++)
    	{
    		cin>>hor[i][j];
    	}
    }
    for(int i=0;i<n-1;i++)
    {
    	for(int j=0;j<m;j++)
    	{
    		cin>>vert[i][j];
    	}
    }
    if(kk&1)
    {
    	for(int i=0;i<n;i++)
    	{
    		for(int j=0;j<m;j++)
    		{
    			cout<<-1<<" ";
    		}
    		cout<<endl;
    	}
    }
    ll arr[n][m][kk/2];
    for(int k=0;k<kk/2;k++)
    {
    	for(int i=0;i<n;i++)
    	{
    		for(int j=0;j<m;j++)
    		{
    			arr[i][j][k] = INT_MAX;
    			ll x = i;
    			ll y = j;
    			for(int q=0;q<4;q++)
    			{
    				ll xx = x+dir4[q][0];
    				ll yy = y+dir4[q][1];
    				if((xx>=0)&&(yy>=0)&&(xx<n)&&(yy<m))
    				{
    					if(k==0)
    					{
    						arr[x][y][k] = min(arr[x][y][k], exhibit(x,xx,y,yy));
    						// cout<<arr[x][y][k]<<exhibit(x,xx,y,yy)<<endl;
    					}
    					else{
    						arr[x][y][k] = min(arr[x][y][k], exhibit(x,xx,y,yy)+arr[xx][yy][k-1]);
    					}
    				}
    			}
    		}
    	}
    }
    for(int i=0;i<n;i++)
    {
    	for(int j=0;j<m;j++)
    	{
    		cout<<arr[i][j][(kk/2)-1]*2<<" ";
    	}
    	cout<<endl;
    }
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