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
    adj[a].pb(b);
    adj[b].pb(a);
}
*/


void solve1(vll &values)
{
	ll n = values.size();

	ll k,x=-1;
   	k=1;
   	for(int i=3;i<n;i++,i++)
   	{
   		if(values[i]==values[k])
   		{
   			continue;
   		}
   		else{
   			x=i;
   			break;
   		}
   	}
   	vector<vll>moves;
   	if(x==-1)
   	{
   		cout<<0<<endl;
   		return;
   	}
   	for(int i=0;i<n;i++,i++)
	{
		moves.pb({k+1,x+1,i+1});
		values[i] = (values[k]^values[x]);
	}
	for(int i=1;i<n;i++,i++)
	{
		moves.pb({1,3,i+1});
		values[i] = (values[0]^values[2]);
	}
	// write(values);
	cout<<moves.size()<<endl;
	for(auto i:moves)
	{
		cout<<i[0]<<" "<<i[1]<<" "<<i[2]<<endl;
	}
	return;
}

void solve()
{
	ll n;
    cin>>n;
    vector<ll>values(n);
    for(int i=0;i<n;i++)cin>>values[i];

    if(n==1){
    	cout<<0<<endl;
    	return;
    }
    if(n==2){
    	if(values[0]==values[1])
    	{
    		cout<<-1<<endl;
    	}
    	else{
    		cout<<0<<endl;
    	}
    	return;
    }
    if(n==3)
    {
    	if((values[0]==values[2]) && (values[0]!=values[1]))
    	{
    		cout<<0<<endl;
    		return;
    	}
    	if((values[0]==values[2]) && (values[0]==values[1]))
    	{
    		if(values[0]==0)
    		{
    			cout<<-1<<endl;
    			return;
    		}
    		cout<<1<<endl;
    		cout<<"1 3 2"<<endl;
    		return;
    	}
    	if(values[1]==0)
    	{
    		if(values[0]!=0)
    		{
    			cout<<1<<endl;
    			cout<<"1 2 3"<<endl;
    			return;
    		}
    		if(values[2]!=0)
    		{
    			cout<<1<<endl;
    			cout<<"3 2 1"<<endl;
    			return;
    		}
    	}
    	cout<<-1<<endl;
    	return;
    }
   	if(count(all(values),0)==n)
   	{
   		cout<<-1<<endl;
   		return;
   	}
   	ll k,x=-1;
   	k=0;
   	for(int i=2;i<n;i++,i++)
   	{
   		if(values[i]==values[k])
   		{
   			continue;
   		}
   		else{
   			x=i;
   			break;
   		}
   	}
   	vector<vll>moves;
   	if(x==-1)
   	{
   		if(values[0]==0)
   		{
   			solve1(values);
   			return;
   		}
   		for(int i=1;i<n;i++,i++)
   		{
   			moves.pb({1,3,i+1});
   			values[i] = (values[0]^values[2]);
   		}
   		// write(values);
   		cout<<moves.size()<<endl;
   		for(auto i:moves)
		{
			cout<<i[0]<<" "<<i[1]<<" "<<i[2]<<endl;
		}
   		return;	
   	}
   	for(int i=1;i<n;i++,i++)
	{
		moves.pb({k+1,x+1,i+1});
		values[i] = (values[k]^values[x]);
	}
	for(int i=0;i<n;i++,i++)
	{
		moves.pb({2,4,i+1});
		values[i] = (values[1]^values[3]);
	}
	// write(values);
	cout<<moves.size()<<endl;
	for(auto i:moves)
	{
		cout<<i[0]<<" "<<i[1]<<" "<<i[2]<<endl;
	}
	return;
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