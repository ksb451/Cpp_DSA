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
    vector<pll>ans;
    if(n>30)
    {
    	for(int i=31;i<n;i++){
    		ans.push_back({i,n});
    	}
    	for(int i=0;i<4;i++)
    	{
    		ans.push_back({n,30});
    	}

    	for(int i=11;i<30;i++)
    	{
    		ans.push_back({i,30});
    	}
    	ans.push_back({30,10});
    	for(int i=6;i<10;i++)
    	{
    		ans.push_back({i,10});
    	}
    	ans.push_back({10,5});
    	ans.push_back({4,5});
    	ans.push_back({5,3});
    	ans.push_back({5,3});
    	ans.push_back({10,3});
    	ans.push_back({30,3});
    	ans.push_back({3,2});
    	ans.push_back({3,2});
    }
    else{
    	for(int i=3;i<n;i++)
    	{
    		ans.push_back({i,n});
    	}
    	for(int i=0;i<5;i++)
    	{
    		ans.push_back({n,2});
    	}
    }
    cout<<ans.size()<<endl;
    for(auto i: ans)
    {
    	cout<<i.first<<" "<<i.second<<endl;
    }
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