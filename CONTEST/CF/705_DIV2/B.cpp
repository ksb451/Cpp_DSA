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
vector<char>refl = {'0', '1', '5', 'q','q','2','q','q','8','q'};
ll h,m;
string add(string s)
{
	ll car=1;
	ll hr = (s[0]-'0')*10 + s[1]-'0';
	ll min = (s[3]-'0')*10 + s[4]-'0';
	min+=1;
	car = min/m;
	min%=m;
	hr+=car;
	hr%=h;
	string hh = to_string(hr);
	string mm = to_string(min);
	if(hh.length()<2)
	{
		hh = '0'+hh;
	}
	if(mm.length()<2)
	{
		mm = '0'+mm;
	}
	return hh+':'+mm;
}

bool refl_check(string s)
{
	string rev;
	for(int i=4;i>=0;i--)
	{
		if(s[i]==':')
		{
			rev+=':';
		}
		else{
			if(refl[s[i]-'0'] == 'q')
			{
				return false;
			}
			else{
				rev+= refl[s[i]-'0'];
			}
		}
	}
	ll hr = (rev[0]-'0')*10 + rev[1]-'0';
	ll min = (rev[3]-'0')*10 + rev[4]-'0';
	if((min < m) && (hr< h))
	{
		return true;
	}
	return false;
}

void solve()
{
    cin>>h>>m;
   	string s;
   	cin>>s;
   	for(int i=0;i<=(h*m);i++)
   	{
   		// cout<<s<<endl;
   		if(refl_check(s))
   		{
   			cout<<s<<endl;
   			return;
   		}
   		s = add(s);
   	}
   	cout<<endl;
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
    fast;
    ll tc = 1;
    IN tc;
    while (tc--)
    {
        solve();
    }
    return 0;
}