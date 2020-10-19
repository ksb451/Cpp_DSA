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
    ll w,n;
    cin>>w>>n;
    vector<int>arr(w);
    for(int i=0;i<w;i++)
    {
    	cin>>arr[i];
    }
    sort(all(arr));
    ll ans=LLONG_MAX;
    ll curr_ans=0;
    for(int i =0;i<w;i++)
    {
    	ll org = arr[i];
    	curr_ans=0;
    	for(int j=0;j<w;j++)
    	{
    		ll curr = arr[j];
    		ll one  = abs(curr-org);
    		ll two = n-one;
    		curr_ans+=min(one,two);
    	}
    	ans = min(ans,curr_ans);
    	if(i==w-1)
    	{
    		ll temp = n-arr[i]+arr[0];
    		temp/=2;
    		org=arr[i]+temp;
    		if(org>n)
    		{
    			org%=n;
    		}
    	}
    	else{
    		org = arr[i]+(arr[i+1]-arr[i])/2;
    		if(org>n)
    		{
    			org%=n;
    		}
    	}
    	curr_ans=0;
    	for(int j=0;j<w;j++)
    	{
    		ll curr = arr[j];
    		ll one  = abs(curr-org);
    		ll two = n-one;
    		curr_ans+=min(one,two);
    	}
    	ans = min(ans,curr_ans);
    	org++;
    	if(org>n)
    		{
    			org%=n;
    		}
    	curr_ans=0;
    	for(int j=0;j<w;j++)
    	{
    		ll curr = arr[j];
    		ll one  = abs(curr-org);
    		ll two = n-one;
    		curr_ans+=min(one,two);
    	}
    	ans = min(ans,curr_ans);
    	//cout<<i<<curr_ans<<endl;
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