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
ll fun(string s)
{
	ll n = s.length();
	ll res=0;
	    for(int i=0;i<=n-4;i++)
	    {
	    	if(s.substr(i,4) == "haha")
	    	{
	    		res++;
	    	}
	    }
    return res;
}

void print(tuple<string, int ,string>a)
{
	cout<<get<0>(a)<<" "<<get<1>(a)<<" "<<get<2>(a)<<endl;
}

void solve()
{
	ll n;
    cin>>n;
    // unordered_map<string ,string>um;
    unordered_map<string ,tuple<string,ll,string>>um;
    tuple<string,ll,string> ans;
    while(n--)
    {
    	string curr_var;
    	cin>>curr_var;
    	string op;
    	cin>>op;
    	// cout<<curr_var<<" "<<op<<endl;
    	if(op == ":=")
    	{
    		string val;
    		cin>>val;
    		string beg = val.substr(0, min(3LL, (ll)val.size()));
    		string en = val.substr(max(0LL, (ll)val.size()- 3));
    		ll x = fun(val);
    		um[curr_var]={beg, x, en};
    		ans = um[curr_var];
    		// print(ans);
    	}
    	else{
    		string ff,ss;
    		cin>>ff>>op>>ss;
    		auto fir = um[ff];
    		auto sec = um[ss];
    		// print(fir);
    		// print(sec);
    		ll x = fun(get<2>(fir)+get<0>(sec));
    		string beg = get<0>(fir);
    		if(beg.length() <3)
    		{
    			beg+= get<0>(sec);
    			beg = beg.substr(0,min((ll)beg.length(), 3LL));
    		}
    		string en = get<2>(sec);
    		if(en.length()<3)
    		{
    			en+= get<2>(fir);
    			en = en.substr(max(0LL, (ll)en.size()- 3));
    		}
    		x+= (get<1>(fir)+get<1>(sec));
    		um[curr_var]={beg, x, en};
    		ans = um[curr_var];
    		// print(ans);
    	}

    }
    cout<<get<1>(ans)<<endl;
    
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