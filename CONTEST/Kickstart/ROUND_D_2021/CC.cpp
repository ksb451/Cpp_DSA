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
// #define endl "\n"
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

multimap<ll, ll>M;

void insert_into(ll a, ll b)
{
	if(a<=b)
	{
		M.insert({a,0});
		M.insert({b,1});
	}
	return;
}

const ll MX = 10000;
void solve()
{
    ll n,m;
    cin>>n>>m;
    vector<vll>arr;
    M.clear();
    for(int i=0;i<n;i++)
    {
    	ll a,b;
    	cin>>a>>b;
    	arr.push_back({a,b});
    	insert_into(a,b);
    }
  	vector<ll>ans;
  	while(m--)
  	{
  		ll q;
  		cin>>q;
  		auto ptr = M.upper_bound(q);
  		// cout<<q<<endl;
  		if(ptr==M.begin())
  		{
  			ll rx,ry;
  			// cout<<1<<endl;
  			auto ptr_next = next(ptr);
  			rx = ptr->first;
  			ry = ptr_next->first;
  			M.erase(rx);
  			M.erase(ry);
  			ans.push_back(rx);
  			insert_into(rx+1,ry);
  		}
  		else if(ptr==M.end()){
  			// cout<<2<<endl;
  			auto ptr_prev = prev(ptr);
  			ll lx,ly;
  			auto ptr_prev_prev = prev(ptr_prev);
  			ly = ptr_prev->first;
  			lx = ptr_prev_prev->first;
  			M.erase(lx);
  			M.erase(ly);
  			ans.push_back(ly);
  			insert_into(lx,ly-1);
  		}
  		else{
  			if(ptr->second == 1)
  			{
  				auto ptr_prev = prev(ptr);
  				ll lx,ly;
  				ly = ptr->first;
  				lx = ptr_prev->first;
  				ans.push_back(q);
  				M.erase(lx);
  				M.erase(ly);
  				insert_into(lx, q-1);
  				insert_into(q+1,ly);
  			}
  			else{
  				ll rx,ry,lx,ly;
  				auto ptr_next = next(ptr);
				rx = ptr->first;
				ry = ptr_next->first;
  				auto ptr_prev = prev(ptr);
				auto ptr_prev_prev = prev(ptr_prev);
				lx = ptr_prev_prev->first;
				ly = ptr_prev->first;
  				M.erase(lx);
  				M.erase(ly);
  				M.erase(rx);
  				M.erase(ry);
  				if((rx - q) < (q-ly))
  				{
  					ans.push_back(rx);
  					insert_into(lx,ly);
  					insert_into(rx+1, ry);
  				}
  				else{
  					ans.push_back(ly);
  					insert_into(rx,ry);
  					insert_into(lx,ly-1);
  				}
  			}
  		}
  		// cout<<endl;
  	}
  	write(ans);
    return;
}

/*
1.check for ll for all variables. 
2.check brackets in all equation and order of conditions.
3.check custom compare funtions if any.
4.check logic carefully.
5.Dont get stuck on one approch.
*/

int main()
{
    ios_base::sync_with_stdio(false); 
    cout.tie(NULL);
    cin.tie(NULL);
    ll tc = 1;
    IN tc;
    for (int i = 1; i <= tc; i++)
    {
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}