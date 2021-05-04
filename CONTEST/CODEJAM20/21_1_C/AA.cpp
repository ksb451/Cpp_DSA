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

ld solve(ll n,ll k,set<ll>arr)
{
    multiset<ll>s1;
    multiset<ll>s2;
    vector<ll>tick;
    for(auto i:arr)
    {
    	tick.push_back(i);
    }
    
    for(int i=0;i<tick.size()-1;i++)
    {
    	if(i==0)
    	{
    		s1.insert(tick[i]-1);
    		s2.insert(tick[i]-1);
    	}
    	ll a = tick[i];
    	ll b = tick[i+1];
    	s1.insert((b-a)/2);
    	s2.insert(b-a-1);
    }
    if(tick.size()==1)
    {
    	s1.insert(tick[0]-1);
    	s2.insert(tick[0]-1);
    }
    ll x = tick.back();
    s1.insert(k-x);
    s2.insert(k-x);
    ll a1  = *s1.rbegin();
    ll a2  = *(next(s1.rbegin()));
    ll a3 = *s2.rbegin();
    ll ans = max(a1+a2, a3);
    // cout<<ans<<endl;
	return (ld(ans)/ld(k));
}

ld solve1(ll n, ll k, vector<ll>arr)
{
    
    sort(all(arr));
	ld ans=0;
	for(ll i=1;i<=k;i++)
	{
		for(ll j=1;j<=i;j++)
		{
			ll a=0,b=0;
			for(ll c=1;c<=k;c++)
			{
				b++;
				ll y_s =min(abs(i-c),abs(j-c));
				ll mn=10000;
				for(ll q=0;q<n;q++)
				{
					mn= min(abs(c-arr[q]),mn);
				}
				if(y_s < mn)
				{
					a++;
				}
			}
			ans = max(ans, ld(a)/ld(b));
		}
	}
	return ans;
}

ld solve3(ll n, ll k,vector<long long> tic)
{
	
	
        set <int> arr;
        arr.insert(all(tic));
        map <pair <int, int> , int> m;
        
        int s=0;
        for(auto i:arr)
        {
            pair <int, int> pp= {s,i};
            int a=i-s-1;
            
             if(s!=0 && a!=1)
             a--;
             
            m.insert({pp,a});
            s=i;
        }
        
            pair <int, int> pp= {s,k+1};
            int a= k-s;
            m.insert({pp,a});
            
         
         int m1 =0;
         int m2=0;
         
         pair <int, int> p;
         
        for(auto i: m)
        {
            
            pair <int, int>  pp= i.first;
            int a= i.second;
            
            if(a>m1)
            {m1=a;
                p=pp;
            }
            //cout<<pp.first <<" "<<pp.second<<" -> "<<a<<endl;
        }
        
        m.erase(p);
        
        for(auto i: m)
        {
            
            pair <int, int>  pp= i.first;
            int a= i.second;
            
            if(a>m2)
            m2=a;
            //cout<<pp.first <<" "<<pp.second<<" -> "<<a<<endl;
        }
        ld ans= (ld)(m1+m2)/(ld)k;
        
        return ans;
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
    	// cout<<i<<endl;
        // cout << "Case #" << i << ": ";
        //srand((unsigned)time(0));
        ll n = (rand() %30) + 1;
        ll k  = (rand() % 30) +1;
        
		vector<ll>arr(n);
		for(int i=0;i<n;i++)
		{
			arr[i]= (rand()%k) +1;
		}
		// cout<<n<<" "<<k<<endl;
		// __print(arr);
		set<ll>S;
		S.insert(all(arr));
		ld c = solve(n,k,S);
		ld b = solve1(n,k,arr);
		ld a = solve3(n,k,arr);
		if((a != b))
		{
			// cout<<"f"<<endl;
			cout<<a<<"  "<<b<<"  "<<c<<endl;
			cout<<n<<" "<<k<<endl;
			__print(arr);
		}
    }
    return 0;
}