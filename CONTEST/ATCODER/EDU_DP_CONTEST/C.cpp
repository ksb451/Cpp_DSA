//**sn0wrus**//
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

//#pragma GCC optimize("Ofast")
//#pragma GCC optimization("unroll-loops, no-stack-protector")
//#pragma GCC target("avx,avx2,fma")

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
#define for0(i,n) for(int i=0;i<n;i++)
#define forn(i,n) for(int i=n-1;i>=0;i++)
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
template<typename T, typename... Args>
void __print(T t, Args... args) // recursive variadic function
{
    cout << t <<" " ;
    __print(args...) ;
}
void nl()
{
    cout<<endl;
}

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

void solve()
{
	string s;
	ll n;
    cin>>s;
    n = s.length();
   	vector<vector<int>>dp(n,vector<int>(4,0));
    for(int i=0;i<n;i++)
    {
    	if(i==0)
    	{
    		if(s[i]=='X'){
    			dp[i][0]=1;
    			dp[i][1]=1;
    			dp[i][3]=1;
    		}
    		else{
    			if(s[i]=='0')
    			{
    				dp[i][0]=1;
	    			dp[i][1]=0;
	    			dp[i][3]=0;
    			}
    			else if(s[i]=='1')
    			{
    				dp[i][0]=0;
	    			dp[i][1]=1;
	    			dp[i][3]=0;
    			}
    			else if(s[i]=='2')
    			{
    				cout<<0<<endl;
    				return;
    			}
    			else if(s[i]=='S')
    			{
    				dp[i][0]=0;
	    			dp[i][1]=0;
	    			dp[i][3]=1;
    			}
    		}
    	}
    	else{
    		if(s[i]=='X')
    		{
    			dp[i][3] = dp[i-1][1] + dp[i-1][3];
    			dp[i][0] = dp[i-1][3] + dp[i-1][0];
    			dp[i][1] = dp[i-1][3] + dp[i-1][0];
    		}
    		else{
    			if(s[i]=='0')
    			{
    				dp[i][0]=dp[i-1][0];
	    			dp[i][1]=0;
	    			dp[i][3]=0;
    			}
    			else if(s[i]=='1')
    			{
    				dp[i][0]=dp[i-1][3];
	    			dp[i][1]=dp[i-1][0];
	    			dp[i][3]=0;
    			}
    			else if(s[i]=='2')
    			{
    				dp[i][0]=0;
	    			dp[i][1]=dp[i-1][3];
	    			dp[i][3]=0;
    			}
    			else if(s[i]=='S')
    			{
    				dp[i][0]=0;
	    			dp[i][1]=0;
	    			dp[i][3]=dp[i-1][1];
    			}
    		}
    	}
    }
    cout<<dp[n-1][0]+dp[n-1][3]<<endl;
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