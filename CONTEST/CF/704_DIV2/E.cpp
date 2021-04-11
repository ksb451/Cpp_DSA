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

vector<vll>v;
ll n,m;

int rec(ll depth)
{
	if(depth>2)
	{
		return 0;
	}
	else{
		for(int i=0;i<n;i++)
		{
			ll c=0;
			for(int j=0;j<m;j++)
			{
				c+= ((v[0][j]==v[i][j])?0:1);
			}
			if(c>4)
			{
				return 0;
			}
			if(c>2)
			{
				for(int j=0;j<m;j++)
				{
					if(v[0][j] != v[i][j])
					{
						ll temp = v[0][j];
						v[0][j] = v[i][j];
						if(rec(depth+1))
						{
							return 1;
						}
						v[0][j]=temp;
					}
				}
				return 0;
			}
		}
	}
	return 1;
}

void solve()
{
    cin>>n>>m;
    v.clear();
    for(int i=0;i<n;i++)
    {
    	vector<ll>arr(m);
    	for(int j=0;j<m;j++)cin>>arr[j];
    	v.push_back(arr);
    }
    if(rec(0))
    {
    	cout<<"Yes"<<endl;
    	write(v[0]);
    	return;
    }
    else{
    	cout<<"No"<<endl;
    	return;
    }
    
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