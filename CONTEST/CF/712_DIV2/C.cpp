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
    string s;
    cin>>s;
    if((s[0]=='0') || (s[n-1]=='0'))
    {
    	cout<<"NO"<<endl;
    	return;
    }
    ll cnt0 = count(all(s),'0');
    if(cnt0 & 1)
    {
    	cout<<"NO"<<endl;
    	return;
    }
    string a(n,'-');
    string b=a;
    ll x=1;
    for(int i=0;i<n;i++)
    {
    	if(s[i]=='0')
    	{
    		if(x&1)
    		{
    			a[i]='(';
    			b[i]=')';
    		}
    		else{
    			a[i]=')';
    			b[i]='(';
    		}
    		x++;
    	}
    }
    ll cnt1 = n-cnt0;
    x=0;
    for(int i=0;i<n;i++)
    {
    	if(s[i]=='1')
    	{
    		if(x<(cnt1/2))
    		{
    			a[i]='(';
    			b[i]='(';
    		}
    		else{
    			a[i]=')';
    			b[i]=')';
    		}
    		x++;
    	}
    }
    cout<<"YES"<<endl;
    cout<<a<<endl<<b<<endl;
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