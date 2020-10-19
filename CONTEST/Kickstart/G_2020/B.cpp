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
    ll arr[n][n];
    for(int i=0;i<n;i++)
    {
    	for(int j=0;j<n;j++)
    	{
    		cin>>arr[i][j];
    	}
    }
    ll ans=0;
    for(int i=n-1;i>=0;i--)
    {
    	ll si=i;
    	ll sj=0;
    	ll curr=0;
    	while(si<n && sj<n)
    	{
    		curr+=arr[si][sj];
    		si++;
    		sj++;
    	}
    	ans=max(ans,curr);
    }
    for(int i=0;i<n;i++)
    {
    	ll si=0;
    	ll sj=i;
    	ll curr=0;
    	while(si<n && sj<n)
    	{
    		curr+=arr[si][sj];
    		si++;
    		sj++;
    	}
    	ans=max(ans,curr);
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