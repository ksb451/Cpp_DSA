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
        cout << x; \
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
	ll a,b,k;
	cin>>a>>b>>k;
	if(b==1)
	{
		if(k==0)
		{
			cout<<"YES"<<endl;
			cout<<1;
			for(int i=0;i<a;i++)
			{
				cout<<0;
			}
			cout<<endl;
			cout<<1;
			for(int i=0;i<a;i++)
			{
				cout<<0;
			}
			cout<<endl;
			return;
		}
		else{
			cout<<"NO"<<endl;
			return;
		}
	}
	if(a==0)
	{
		if(k==0)
		{
			cout<<"YES"<<endl;
			for(int i=0;i<b;i++)
			{
				cout<<1;
			}
			cout<<endl;
			for(int i=0;i<b;i++)
			{
				cout<<1;
			}
			cout<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
		return;
	}
	if(k<=(a+b-2))
	{
		vector<ll>y(a+b);
		y[0]=1;
		for(int i=1;i<b;i++)
		{
			y[a+b-i]=1;
		}
		vector<ll>x(a+b);
		ll car=0;
		for(int i=1;i<=(a+b);i++)
		{
			ll q;
			if(i<=k)
			{
				q=1;
			}
			else{
				q=0;
			}
			ll ind = a+b-i;
			ll sum = y[ind]+q+car;
			if(sum==1)
			{
				x[ind]=1;
				car=0;
			}
			else if(sum==2)
			{
				x[ind]=0;
				car=1;
			}
			else if(sum==3)
			{
				x[ind]=1;
				car=1;
			}
		}
		cout<<"YES"<<endl;
		write(x);
		write(y);
	}
	else{
		cout<<"NO"<<endl;
	}
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