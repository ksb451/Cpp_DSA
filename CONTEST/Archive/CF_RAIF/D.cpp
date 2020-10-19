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
    vector<ll>arr(n+1);
    for(int i=1;i<=n;i++)cin>>arr[i];

    vector<pll>ans_arr;
	ll ans=0;
	ll curr=1;
	unordered_map<ll,ll>umap_c;
	set<int>set_r;
	set<int>set_c;
	unordered_map<ll,ll>umap_r;
    for(int i=n;i>0;i--)
    {
    	if(arr[i]==1)
    	{
    		if(curr>n)
    		{
    			cout<<-1<<endl;
    			return;
    		}
    		ans++;
    		ans_arr.push_back({curr,i});
    		set_r.insert(curr);
    		set_c.insert(i);
    		umap_r[curr]=i;
    		umap_c[i]=curr;
    		curr++;
    	}
    	else if(arr[i]==2)
    	{
    		if(set_r.empty())
    		{
    			cout<<-1<<endl;
    			return;
    		}
    		else{
    			ll xx = *set_r.begin();
    			set_r.erase(xx);
    			set_c.erase(umap_r[xx]);
    			ans++;
    			ans_arr.push_back({xx, i});
    			set_c.insert(i);
    			umap_c[i]=xx;
    		}
    	}
    	else if(arr[i]==3)
    	{
    		if(set_c.empty())
    		{
    			cout<<-1<<endl;
    			return;
    		}
    		else{
    			if(curr>n)
    			{
    				cout<<-1<<endl;
    				return;
    			}
    			ll xx = *set_c.rbegin();
    			//cout<<umap_c[xx]<<endl;
    			set_c.erase(xx);
    			ans+=2;
    			ans_arr.push_back({curr, i});
    			ans_arr.push_back({curr,xx});
    			set_c.insert(i);
    			umap_c[i]=curr;
    			set_r.erase(umap_c[xx]);
    			set_r.erase(curr);
    			set_c.erase(xx);
    			curr++;
    		}
    	}
    }
    cout<<ans<<endl;
    for(auto i:ans_arr)
    {
    	cout<<n-i.first+1<<" "<<i.second<<endl;
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