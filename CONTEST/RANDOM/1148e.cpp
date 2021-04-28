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

void solve()
{
	ll n;
    cin>>n;
    vector<vll>arr(n,vll(2));
    vector<vll>target(n,vll(2));
    for(int i=0;i<n;i++){
    	cin>>arr[i][0];
    	arr[i][1]=i+1;
    }
    for(int i=0;i<n;i++){
    	cin>>target[i][0];
    	target[i][1]=i+1;
    }
    // if((n==100) && (arr[0][0]==493104271))
    // {
    // 	for(int i=47;i<100;i++)
    // 	{
    // 		cout<<arr[i][0]<<endl;
    // 	}
    // 	return;
    // }
    sort(all(arr));
	sort(all(target));
	// __print(arr);
	// __print(target);
	vector<vll>ans;
	ll i=0;
	ll j=1;
	while((i<n) && (j<n))
	{
		// __print(i,j);nl();
		if(i==j)
		{
			j++;
		}
		else{
			if(arr[i][0]==target[i][0])
			{
				i++;
			}
			else if(arr[i][0]>target[i][0])
			{
				cout<<"NO"<<endl;
				return;
			}
			else{
				if(arr[j][0]<=target[j][0])
				{
					j++;
				}
				else{
					ll d = min(target[i][0]-arr[i][0], arr[j][0]-target[j][0]);
					arr[i][0]+=d;
					arr[j][0]-=d;
					ans.push_back({arr[i][1],arr[j][1],d});
				}
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		if(arr[i][0]==target[i][0])
		{

		}
		else{
			cout<<"NO"<<endl;
			return;
		}
	}
	cout<<"YES"<<endl;
	cout<<ans.size()<<endl;
	for(auto it:ans)
	{
		cout<<it[0]<<" "<<it[1]<<" "<<it[2]<<endl;
	}
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
    // IN tc;
    while (tc--)
    {
        solve();
    }
    return 0;
}