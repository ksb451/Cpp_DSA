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
#define endl "\n"
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

void solve()
{
	ll n;
    cin>>n;
    vector<ll>arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];

    unordered_map<ll, ll>um;
	for(auto i:arr)
	{
		um[i]++;
	}
	map<ll, ll>mm;
	for(auto i:um)
	{
		mm[i.second]++;
	}
	vector<pii>vv;
	for(auto i:mm)
	{
		vv.push_back({i.first,i.second});
	}
	sort(allr(vv));
	ll ans=INT_MAX;
	ll pr1,pr2;
	ll c1 = vv[0].first*vv[0].second;
	ans = (n-c1);
	pr1 = vv[0].first;
	pr2 = vv[0].second;
	for(int i=1;i<vv.size();i++)
	{
		c1+=vv[i].first*vv[i].second;
		ll curr = pr2*( pr1 - vv[i].first);
		curr+= (n-c1);
		ans = min(ans,curr);
		pr2 += vv[i].second;
		pr1 = vv[i].first;
	}
	cout<<ans<<endl;
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