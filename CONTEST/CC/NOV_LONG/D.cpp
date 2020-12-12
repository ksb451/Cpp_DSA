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
    vector<ll>arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];

    bool chef= true;
	ll chef_can=0;
	vector<pair<bool,ll>>chef_cnt;
    for(int i=0;i<n;i++)
    {
    	if(arr[i]==1)
    	{
    		if(i==0)
    		{
    			chef_can+=1;
    			chef_cnt.push_back({chef,chef_can});
    			chef^=true;
    			continue;
    		}
    		else if(i==n-1)
    		{
    			chef_can+=1;
    			chef_cnt.push_back({chef,chef_can});
    			continue;
    		}
    		else{
    			if(arr[i-1]%2)
    			{
    				chef_can++;
    				chef_cnt[i-1].second++;
    			}
    			else{
    				chef_can--;
    				chef_cnt[i-1].second--;
    			}
    			chef_cnt.push_back({false, chef_can});
    			continue;
    		}
    	}
    	else if(chef==true){
    		if(i==n-1)
    		{
    			if(arr[i]%2)
    			{
    				chef_can+=arr[i];
    			}
    			else{
    				chef_can+=(arr[i]-1);
    			}
    		}
    		else{
    			if(arr[i]%2)
    			{
    				chef_can+=(arr[i]-1);
    			}
    			else{
    				chef_can+=arr[i];
    			}
    		}
    	}
    	chef_cnt.push_back({chef,chef_can});
    }
    // for(auto i:chef_cnt)
    // {
    // 	cout<<i.first<<" "<<i.second<<endl;
    // }
    ll x = chef_cnt.size();
    ll q;
    cin>>q;
    while(q--)
    {
    	ll r;
    	cin>>r;
    	if(n==1)
    	{
    		if(arr[0]==1)
    		{
    			cout<<r<<endl;
    		}
    		else{
    			if(arr[0]%2==0)
    			{
    				ll ans = (r*arr[0])-(r-1);
    				ans%=mod;
    				cout<<ans<<endl;
    			}
    			else{
    				ll ans = r*arr[0];
    				ans%=mod;
    				cout<<ans<<endl;
    			}
    		}
    		continue;
    	}
    	if(r==1)
    	{
    		cout<<arr[0]<<endl;
    		continue;
    	}
    	ll ans=0;
    	ll quo = (r-1)/x;
    	//cout<<quo<<endl;
    	ans+=(quo*(chef_cnt[x-1].second));
    	ans%=mod;
    	ll j =(r-1)%x;
    	//cout<<j<<endl;
    	if(j>0)
    	{
    		ans+=chef_cnt[j-1].second;
    		ans%=mod;
    	}
    	if(arr[j]==1)
    	{
    		if(j==0)
    		{
    		}
    		else if(j==n-1)
    		{
    			ans++;
    		}
    		else{
    			if(arr[j-1]%2==0)
    			{
    				ans+=2;
    			}
    		}
    	}
    	else if(arr[0]!=1)
    	{
    		ans+=arr[j];
    	}
	    ans%=mod;
	    cout<<ans<<endl;
    }
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