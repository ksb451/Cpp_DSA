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
#define for0(i,n) for(ll i =0;i<n;i++)
#define forn(i,n) for(ll i =n-1;i>=0;i--)
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
	ll n;
    cin>>n;
    vector<string>arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    ll r1=0,r2=0,c1=0,c2=0,k=0;
    for0(i,n)
	{

		for0(j,n)
		{
			if(arr[i][j]=='*')
			{
				if(k==0)
				{
					r1=i;
					c1=j;
					k++;
				}
				else{
					r2=i;
					c2=j;
					k++;
					break;
				}
			}
		}
		if(k==2)
		{
			break;
		}
	}
	if(r1==r2)
	{
		ll newr=0;
		if(r1==0)
		{
			newr = 1;
		}
		else{
			newr = r1-1;
		}
		arr[newr][c1]='*';
		arr[newr][c2]='*';
	}
	else if(c1==c2)
	{
		ll newr=0;
		if(c1==0)
		{
			newr = 1;
		}
		else{
			newr = c1-1;
		}
		arr[r1][newr]='*';
		arr[r2][newr]='*';
	}
	else{
		arr[r1][c2]='*';
		arr[r2][c1]='*';
	}
	for0(i,n)
	{
		for0(j,n)
		{
			cout<<arr[i][j];
		}
		cout<<endl;
	}
	return;

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