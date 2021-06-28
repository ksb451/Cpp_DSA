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

void fun_on(ll x,ll L, vll &len, vll &onentry)
{
	ll q=1;
	for(int i=x+1;i<len.size();i++)
	{
		if(q<L)
		{
			q+=len[i];
			onentry[i]=1;
		}
		else{
			break;
		}
	}
	return;
}

void solve()
{
	ll n,x;
    cin>>n>>x;
    vector<ll>len(n);
    vector<ll>lights_on(n);
    for(int i=0;i<n;i++)cin>>len[i];

    for(int i=0;i<n;i++)cin>>lights_on[i];

    vector<ll>onentry(n,0);
	ll curr_len=0;
	ll curr_num=0;
	ll ans=0;
	ll last_out=-1;
	ll next_in=0;
	while(last_out<n-1)
	{
		if(curr_len<x)
		{
			if(next_in<n)
			{
				curr_len+=len[next_in];
				curr_num+=lights_on[next_in];
				if(lights_on[next_in]==1){
					fun_on(next_in,x, len, onentry);
				}
				if((curr_num==0) && (onentry[next_in]==0)) 
				{
					ans++;
					lights_on[next_in]=1;
					fun_on(next_in,x, len, onentry);
					curr_num=1;
				}
				next_in++;
			}
			else{
				if(curr_num==0)
				{
					lights_on[next_in-1]=1;
					ans++;
					break;
				}
				else{
					last_out++;
					curr_len-=len[last_out];
					curr_num-=lights_on[last_out];
				}
			}
		}
		else{
			if(curr_num==0)
			{
				lights_on[next_in-1]=1;
				fun_on(next_in-1,x, len, onentry);
				curr_num=1;
				ans++;
			}
			last_out++;
			curr_len-=len[last_out];
			curr_num-=lights_on[last_out];
		}
	}
	cout<<ans<<endl;
	
}

/*
1.check for ll for all variables. 
2.chec for return satement in correct places.
3.check brackets in all equation and order of conditions.
4.check custom compare funtions if any.
5.check logic carefully.
6.Dont get stuck on one approch.
*/

int main()
{
    fast;
    ll tc = 1;
    IN tc;
    while (tc--)
    {
        solve();
        cout.flush();
    }
    return 0;
}