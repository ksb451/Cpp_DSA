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
	string s;
	cin>>s;
	ll n=s.length();
	vector<pll>arr;
	ll x=0,y=0;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='L')
		{
			x--;
		}
		else if(s[i]=='U')
		{
			y++;
		}
		else if(s[i]=='R')
		{
			x++;
		}	
		else{
			y--;
		}
		arr.push_back({x,y});
	}
	for(auto i:arr){
		ll xx=0,yy=0;
		for(int j=0;j<n;j++)
		{
			x=xx,y=yy;
			if(s[j]=='L')
			{
				x--;
			}
			else if(s[j]=='U')
			{
				y++;
			}
			else if(s[j]=='R')
			{
				x++;
			}	
			else{
				y--;
			}
			if((i.first==x) && (i.second==y))
			{

			}
			else{
				xx=x;
				yy=y;
			}
		}
		if(xx==0 && yy==0)
		{
			cout<<i.first<<" "<<i.second<<endl;
			return;
		}
	}
	cout<<"0 0"<<endl;
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