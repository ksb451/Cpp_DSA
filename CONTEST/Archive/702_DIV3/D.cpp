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
#define IN cin >>
#define OUT cout <<
//#define endl "\n"
#define all(a) (a).begin(), (a).end()
#define allr(a) (a).rbegin(), (a).rend()
#define pb push_back
#define fi first;
#define se second;

using ll = long long int;
using ld = long double;
using pll = pair<ll, ll>;   
using pii = pair<int, int>;
using plll  = pair<ll,pll>;
using vll = vector<ll>;
using vi = vector<int>;
const ll mod = (ll)(1e9) + 7LL;
const ll M = 998244353LL;

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
vector<ll>ans;

void rec(vector<ll>&arr, ll dep, ll st, ll nd)
{
	if(st>nd)
	{
		return;
	}
	ll ind;
	ll mx= 0;
	for(int i = st;i<=nd;i++)
	{
		if(arr[i]>mx)
		{
			mx = arr[i];
			ind = i;
		}
	}
	// cout<<dep<<" "<<mx<<endl;
	// cout<<st<<" "<<nd<<endl;
	ans[mx-1]=dep;
	rec(arr, dep+1, ind+1, nd);
	rec(arr, dep+1, st, ind-1);
}

void solve()
{
	ll n;
    cin>>n;
    vector<ll>arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    
    ans = vector<ll>(n,0);
	// cout<<"1"<<endl;
	rec(arr,0 ,0 ,n-1);
	for(auto i:arr)
	{
		cout<<ans[i-1]<<" ";
	}
	cout<<endl;
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