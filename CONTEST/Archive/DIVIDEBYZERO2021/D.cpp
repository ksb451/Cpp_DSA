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

void solve()
{
	ll n,x;
    cin>>n>>x;
    vector<ll>arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    vector<int>is_connected(n,0);
	vector<pll>a;
	for(int i=0;i<n;i++)
	{
		a.push_back({arr[i],i});
	}
	sort(all(a));
	ll ans=0;
	for(auto p:a)
	{
		ll curr = p.first;
		if(curr>=x)
		{
			break;
		}
		ll i = p.second;
		while(i>0)
		{
			if(is_connected[i])
			{
				break;
			}
			else{
				if((arr[i-1]%curr)== 0)
				{
					// cout<<i<<" "<<curr<<endl;
					ans+=curr;
					is_connected[i]=1;
				}
				else{
					break;
				}
			}
			i--;
		}
		i = p.second+1;
		while(i<n)
		{
			if(is_connected[i])
			{
				break;
			}
			else{
				if((arr[i]%curr)== 0)
				{
					// cout<<i<<" "<<curr<<endl;
					ans+=curr;
					is_connected[i]=1;
				}
				else{
					break;
				}
			}
			i++;
		}
	}
	// cout<<ans<<endl;
	for(int i=1;i<n;i++)
	{
		if(!is_connected[i])
		{
			ans+=x;
		}
	}
	cout<<ans<<endl;
}

int main()
{
    fast;
    ll tc = 1;
    IN tc;
    while (tc--)
    {
        solve();
    }
    return 0;
}