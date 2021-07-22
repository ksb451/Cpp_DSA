//**sn0wrus**//
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cout.tie(NULL);                   \
    cin.tie(NULL);

#define IN cin >>
#define OUT cout <<
#define endl "\n"
#define all(a) (a).begin(), (a).end()
#define pb push_back
using ll = long long int;
using ld = long double;
using pll = pair<ll, ll>;
using pii = pair<int, int>;
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
    vector<int>vis(n,0);
    set<pll,greater<>>ss;
    for(int i=0;i<n;i++)
    {
    	char curr=s[i];
    	int c=i;
    	int cnt=0;
    	while(i<n && s[i]==curr)
    	{
    		i++;
    		cnt++;
    	}
    	vis[c]=cnt;
    	ss.insert({cnt,c});
    	i--;
    }
    // for(int i=0;i<n;i++)
    // {
    // 	cout<<vis[i]<<" ";
    // }
    ll ans=0;
    for(int i=0;i<n;)
    {
    	if(vis[i]>1)
    	{
    		//cout<<i<<" "<<vis[i]<<endl;
    		ans++;
    		ss.erase({vis[i],i});
    		i+=vis[i];
    	}
    	else if(vis[i]==0){
    		i++;
    	}
    	else if(vis[i]==1)
    	{
    		auto xx = *ss.begin();
    		//cout<<i<<" "<<xx.second<<endl;
    		if(xx.first > 1)
    		{
    			ans++;
    			vis[xx.second]=0;
    			vis[xx.second+1]=xx.first-1;
    			ss.erase(ss.begin());
    			ss.insert({xx.first-1, xx.second+1});
    		}
    		else if(xx.first==1)
    		{
    			ans++;
    			if(xx.second==i)
    			{
    				ss.erase(ss.begin());
    				if(!ss.empty())
    				{
    					vis[ss.begin()->second]=0;
    					ss.erase(ss.begin());
    				}
    			}
    			else{
    				vis[ss.begin()->second]=0;
    				ss.erase(ss.begin());
    				ss.erase({1,i});
    			}
    		}
    		i++;
    	}
    }
    cout<<ans;
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
        cout<<endl;
    }
    return 0;
}