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

bool cmp(pll a,pll b)
{
	if(a.first > b.first)
	{
		return true;
	}
	else if(a.first==b.first){
		return a.second < b.second;
	}
	else{
		return false;
	}
}

void solve()
{
	ll n;
    cin>>n;
    set<pll>cust;
    set<pll, decltype(cmp)*>cust2(cmp);
    ll num=1;
    for(int i=0;i<n;i++)
    {
    	ll a;
    	cin>>a;
    	if(a==1)
    	{
    		ll m;
    		cin>>m;
    		cust.insert({num,m});
    		cust2.insert({m,num});
    		num++;
    	}
    	else if(a==2)
    	{
    		pll xx = *cust.begin();
    		cout<<xx.first<<" ";
    		cust.erase(xx);
    		cust2.erase({xx.second, xx.first});
    	}
    	else if(a==3)
    	{
    		pll xx = *cust2.begin();
    		cout<<xx.second<<" ";
    		cust2.erase(xx);
    		cust.erase({xx.second, xx.first});
    	}
    }
    cout<<endl;
    return;
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