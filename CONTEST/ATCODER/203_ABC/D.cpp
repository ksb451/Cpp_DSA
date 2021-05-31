//**sn0wrus**//
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops, no-stack-protector")
#pragma GCC target("avx,avx2,fma")

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

struct MedianFinder {

    multiset<ll>left, right;

    MedianFinder()
    {
    	left.clear();
    	right.clear();
    }
    void addNum(ll curr) {
    	//cout<<curr<<endl;
        if(left.empty())
        {
            left.insert(curr);
        }
        else
        {
            ll x = *left.rbegin();   
            if(curr>x)
            {
                right.insert(curr);
            }
            else{
                left.insert(curr);
            }
        }
        while(right.size()>left.size())
        {
            ll x = *right.begin();
            left.insert(x);
            right.erase(right.find(x));
        }
        while(left.size()-right.size()>1)
        {
            ll x = *left.rbegin();
            right.insert(x);
            left.erase(left.find(x));
        }
        //cout<<"done"<<endl;
    }

    void removeNum(ll curr)
    {
    	//cout<<curr<<"r"<<endl;
    	if(left.find(curr)==left.end())
        {
            right.erase(right.find(curr));
        }
        else{
            left.erase(left.find(curr));
        }
        while(right.size()>left.size())
        {
            ll x = *right.begin();
            left.insert(x);
            right.erase(right.find(x));
        }
        while(left.size()-right.size()>1)
        {
            ll x = *left.rbegin();
            right.insert(x);
            left.erase(left.find(x));
        }
       // cout<<"done"<<endl;
    }
    // Returns the median of current data stream
    ll findMedian() {
        if(left.size() == right.size()) return left.empty()?0:(*left.rbegin());
        else return (left.size() > right.size())? *(left.rbegin()):*(right.begin()); 
    }
};

void solve()
{
	ll n,k;
    cin>>n>>k;
    vector<vll>arr(n,vll(n));
    for(int i=0;i<n;i++)
    {
    	for(int j=0;j<n;j++)
    	{
    		cin>>arr[i][j];
    	}
    }
    // cout<<"done"<<endl;
    ll ans=INT_MAX;
    for(int i=0;i<=n-k;i++)
    {
    	MedianFinder curr;
    	for(int ii=i;ii<i+k;ii++)
    	{
    		for(int jj=0;jj<k;jj++)
    		{
    			curr.addNum(arr[ii][jj]);
    		}
    	}
    	// cout<<"done1"<<endl;
    	// cout<<"median"<<curr.findMedian()<<endl;
    	ans = min(ans, curr.findMedian());
    	for(int j = k;j<n;j++)
    	{
    		for(int ii=i;ii<i+k;ii++)
    		{
    			curr.addNum(arr[ii][j]);
    			curr.removeNum(arr[ii][j-k]);
    		}
    		ans = min(ans, curr.findMedian());
    		// cout<<"median"<<curr.findMedian()<<endl;
    	}
    	// cout<<"done2"<<endl;
    }
    cout<<ans<<endl;
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
    //IN tc;
    while (tc--)
    {
        solve();
        cout.flush();
    }
    return 0;
}

