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
    vector<vector<ll>>rem(n,vector<ll>(4,0));
    unordered_map<ll,vector<ll>>um;
    set<ll>S;
    for(int i=0;i<n;i++)
    {
    	ll m;
    	cin>>m;
    	for(int j=0;j<m;j++)
    	{
    		ll x;
    		cin>>x;
    		if(x>0)
    		{
    			rem[i][0]++;
    			rem[i][1]++;
    			
    		}
    		else{
    			rem[i][2]++;
    		}
    		S.insert(abs(x));
    		um[x].push_back(i);
    	}
    }
    ll ans=0;
    for(auto i:S)
    {
    	ll sz=0;
    	if(um.find(i)!=um.end())
    	{
    		sz+=um[i].size();
    	}
    	ll neg = (0-i);
    	if(um.find(neg)!=um.end())
    	{
    		sz+=um[neg].size();
    	}

    	if(sz > 1)
    	{
    		ans++;
    		if(um.find(i)!=um.end())
	    	{
	    		for(auto j: um[i])
	    		{
	    			rem[j][1]--;
	    			rem[j][0]--;
	    			ans+=rem[j][1];
    			}
	    	}
	    	if(um.find(neg)!=um.end())
	    	{
	    		for(auto j:um[neg])
	    		{
	    			rem[j][2]--;
	    			ans+=rem[j][2];
	    			ans+=rem[j][3];
	    		}
	    	}
    	}
    	else{
    		if((um.find(i)!=um.end())&& (um[i].size()==1))
    		{
    			rem[um[i][0]][1]--;
    			rem[um[i][0]][3]++;
    		}
    		else if((um.find(neg)!=um.end())&&(um[neg].size()==1))
    		{
    			ans+=rem[um[i][0]][0];
    			rem[um[i][0]][2]--;
    		}
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