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
	ll n,m;
    cin>>n>>m;
    string s,t;
    cin>>s>>t;
    if(n==m)
    {
    	cout<<1<<endl;
    	return;
    }
    ll i=n-1;
    ll j=m-1;
    vector<ll>st(m);
    vector<ll>nd(m);
    while((i>=0) && (j>=0))
    {
    	if(s[i]==t[j])
    	{
    		nd[j]=i;
    		j--;
    		i--;
    	}
    	else{
    		i--;
    	}
    }
    i=0;
    j=0;
    while((i<n) && (j<m))
    {
    	if(s[i]==t[j])
    	{
    		st[j]=i;
    		j++;
    		i++;
    	}
    	else{
    		i++;
    	}
    }
    
    ll ans=0;
    for(int i=0;i<m-1;i++)
    {
    	ans=max(ans,nd[i+1]-st[i]);
    }
    cout<<ans<<endl;
}

int main()
{
    fast;
    ll tc = 1;
    //IN tc;
    while (tc--)
    {
        solve();
    }
    return 0;
}