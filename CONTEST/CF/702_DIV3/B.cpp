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
    ll a1=0,a2=0,a3=0;
	for(int i=0;i<n;i++)
	{
		if((arr[i]%3)==0)
		{
			a1++;
		}
		else if((arr[i]%3)==1)
		{
			a2++;
		}
		else{
			a3++;
		}
	}
	ll ans=0;
	ll x = n/3;
	if((a1>=a2)&&(a1>=a3))
	{
		ans+= (a1-x);
		a2+= (a1-x);
		if(a2<a3)
		{
			ans+= (a3-a2);
		}
		else{
			ans+=(a2-a3)/2;
		}
	}
	else if((a1<=a2)&&(a2>=a3))
	{
		ans+= (a2-x);
		a3+= (a2-x);
		if(a3<a1)
		{
			ans+= (a1-a3);
		}
		else{
			ans+=(a3-a1)/2;
		}
	}
	else if((a3>=a2)&&(a3>=a1))
	{
		ans+= (a3-x);
		a1+= (a3-x);
		if(a1<a2)
		{
			ans+= (a2-a1);
		}
		else{
			ans+=(a1-a2)/2;
		}
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