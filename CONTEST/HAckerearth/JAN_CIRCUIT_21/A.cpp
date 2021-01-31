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

int check(ll x1,ll x2,ll y1,ll y2)
{
	if(x1 <1 || x1 > 8 ||x2 <1 || x2 > 8 || y1 <1 || y1 > 8 ||y2 <1 || y2 > 8 )
	{
		return 0;
	}
	if(abs(x2-x1)<2 && abs(y2-y1)< 2)
	{
		return 1;
	}
	else{
		return 2;
	}
}

void solve()
{
	ll x1, x2,y1,y2;
	cin>>x1>>y1;
	cin>>x2>>y2;
	if(check(x1,x2,y1,y2)==1)
	{
		cout<<"FIRST"<<endl;
		return;
	}
	else{
		for(int i=0;i<8;i++)
		{
			ll nx= x1+dir8[i][0];
			ll ny = y1+dir8[i][1];
			if(check(nx,x2,ny,y2)==2)
			{
				cout<<"DRAW"<<endl;
				return;
			}
		}
		cout<<"SECOND"<<endl;
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