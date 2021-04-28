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
    ll n,a,b;
    cin>>n>>a>>b;
    vector<ll>given(1000,0);
    vector<ll>current(1000,0);	
    for(int i=1;i<=n;i++)
    {
    	ll x;
    	cin>>x;
    	given[i]=x;
    }
    for(int i=n+a; i<1000;i++)
    {
    	current = vector<ll>(1000,0);
    	current[i]=1;
    	bool flag=true;
    	for(int j =i;j>=0;j--)
    	{
    		if(current[j]>=given[j])
    		{
    			ll extra = current[j]-given[j];
    			current[j]-=extra;
    			current[max(0LL,j-a)]+=extra;
    			current[max(0LL,j-b)]+=extra;
    		}
    		else{
    			flag = false;
    			break;
    		}
    	}
    	if(flag)
    	{
    		cout<<i<<endl;
    		return;
    	}
    }
    cout<<"IMPOSSIBLE"<<endl;
    return;
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