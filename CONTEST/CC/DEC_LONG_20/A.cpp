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
	ll d1,d2,v1,v2,p;
    cin>>d1>>v1>>d2>>v2>>p;
    ll ans=0;
    if(p==0)
    {
    	cout<<ans<<endl;
    	return;
    }
    if(d1>d2)
    {
    	ll temp = d1;
    	d1 = d2;
    	d2 = temp;
    	temp = v1;
    	v1 = v2;
    	v2 = temp;
    }
    ans=d1;
    ll d = d2-d1;
    if((v1*d) >= p)
    {
    	ll q = p/v1;
    	if(p%v1!=0)
    	{
    		q++;
    	}
    	ans+=q;
    	cout<<ans-1<<endl;
    	return;
    }
    p-=(v1*d);
    ans =d2;
    ans+=(p/(v1+v2));
    if(p%(v1+v2)!=0)
    {
    	ans++;
    }
    cout<<ans-1<<endl;

}

int main()
{
    fast;
    ll tc = 1;
    while (tc--)
    {
        solve();
    }
    return 0;
}