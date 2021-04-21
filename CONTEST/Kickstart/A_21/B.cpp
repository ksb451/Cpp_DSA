#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cout.tie(NULL);                   \
    cin.tie(NULL);

#define IN cin >>
#define OUT cout <<
#define nl "\n"
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define write(a)          \
    for (auto x : a)      \
    {                     \
        cout << x << " "; \
    }                     \
    cout << nl;
#define read(a)       \
    for (auto &x : a) \
    {                 \
        cin >> x;     \
    }
using ll = long long int;
using ld = long double;
using pll = pair<ll, ll>;
using pii = pair<int, int>;
using vll = vector<ll>;
using vi = vector<int>;
const ll mod = (ll)(1e9) + 7LL;
const ll M = 988244353LL;

void solve()
{
    ll n;
    cin>>n;
    vector<ll>arr(n);
    for(int i=0;i<n;i++)
    {
    	cin>>arr[i];
    }
    if(n<=3)
    {
    	cout<<n<<endl;
    	return;
    }
    ll ans=2;
    vector<pll>left(n,{0,0});
    vector<pll>right(n,{0,0});
    for(int i=1;i<n;i++)
    {
    	ll curr = arr[i]-arr[i-1];
    	if(i==1)
    	{
    		left[i] = {2,curr};
    	}
    	else{
    		if(curr == left[i-1].second)
    		{
    			left[i] = {left[i-1].first+1, curr};
    		}
    		else{
    			left[i] = {2,curr};
    		}
    	}
    }
    // for(auto i:left)
    // {
    // 	cout<<i.first<<" "<<i.second<<endl;
    // }
    for(int i=n-2;i>=0;i--)
    {
    	ll curr = arr[i+1]-arr[i];
    	// cout<<i<<" "<<curr<<endl;
    	if(i==n-2)
    	{
    		right[i] = {2,curr};
    	}
    	else{
    		if(curr == right[i+1].second)
    		{
    			right[i] = {right[i+1].first+1, curr};
    		}
    		else{
    			right[i] = {2,curr};
    		}
    	}
    }

    // for(auto i:right)
    // {
    // 	cout<<i.first<<" "<<i.second<<endl;
    // }

    for(int i=0;i<n;i++)
    {
    	if(i>0)
    		ans = max(ans,left[i-1].first+1);
    	if(i<n-1)
    		ans = max(ans,right[i+1].first+1);

    	if(i==0)
    	{
    		ans = max(ans, 1+right[1].first);
    	}
    	else if(i==1)
    	{
    		ll x = right[i+1].second;
    		if(arr[i+1]-arr[i-1] == 2*x)
    		{
    			ans = max(ans, right[i+1].first+2);
    		}
    	}
    	else if(i==n-1)
    	{
    		ans = max(ans, 1+left[n-2].first);
    	}
    	else if(i==n-2)
    	{
    		ll x = left[i-1].second;
    		if(arr[i+1]-arr[i-1] == 2*x)
    		{
    			ans = max(ans, left[i-1].first+2);
    		}
    	}
    	else{
    		// cout<<"end"<<i<<endl;
    		// cout<<arr[i+1]<<" "<<arr[i-1]<<endl;
    		if(((arr[i+1]-arr[i-1]) % 2 )==0)
    		{
    			ll diff = (arr[i+1]-arr[i-1]) / 2;
    			if(diff == left[i-1].second)
    			{
    				ans = max(ans,left[i-1].first+2);
    			}
    			if(diff == right[i+1].second)
    			{
    				ans = max(ans,right[i+1].first+2);
    			}
    			// cout<<left[i-1].second<<" "<<right[i+1].second<<endl;
    			if(left[i-1].second == right[i+1].second)
    			{
    				if(arr[i+1]-arr[i-1] == (2* left[i-1].second))
    				{
    					ans = max(ans, left[i-1].first + right[i+1].first +1);
    				}
    			}
    		}
    	}
    }
    cout<<ans<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false); 
    cout.tie(NULL);
    cin.tie(NULL);
    ll tc = 1;
    IN tc;
    for (int i = 1; i <= tc; i++)
    {
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}