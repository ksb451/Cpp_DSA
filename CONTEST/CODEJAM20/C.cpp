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
    ll n,c;
    cin>>n>>c;
    ll mx = ((n*(n+1))/2)-1;
    if((c<(n-1))||(c>mx))
    {
    	cout<<"IMPOSSIBLE"<<endl;
    	return;
    }
    else{
    	ll rem = c-n+1;
    	vector<ll>ans(n,0);
    	ll start=0,end=n-1;
    	ll curr=0;
    	c-=(n-1);
    	for(int i=1;i<=n;i++)
    	{
    		ll sc = n-i;
    		if(rem < sc)
    		{
    			if(curr==0)
    			{
    				ans[start]=i;
    				start++;
    			}
    			else{
    				ans[end]=i;
    				end--;
    			}
    		}
    		else{
    			rem-=sc;
    			if(curr==0)
    			{
    				ans[end]=i;
    				end--;
    				curr=1;
    			}
    			else{
    				ans[start]=i;
    				start++;
    				curr=0;
    			}
    		}
    	}
    	write(ans);
    	return;
    }
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