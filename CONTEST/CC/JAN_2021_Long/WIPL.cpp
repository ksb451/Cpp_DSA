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

ll subsetsum(vector<ll>arr, ll sum)
{
	ll n = arr.size();
	bool dp[n+1][sum+1];
 
    for (int i = 0; i <= n; i++)
        dp[i][0] = true;
    for (int i = 1; i <= sum; i++)
        dp[0][i] = false;
 
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (j < arr[i - 1])
                dp[i][j] = dp[i - 1][j];
            if (j >= arr[i - 1])
                dp[i][j] = dp[i - 1][j]
                               || dp[i - 1][j - arr[i - 1]];
        }
    }
    for(int i=sum;i>=0;i--)
	{
		if(dp[n][i]==true)
		{
			return i;
		}
	}
	return 0;
}

void solve()
{
	ll n,k;
    cin>>n>>k;
    vector<ll>arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    sort(allr(arr));
    vector<ll>arr2;
    ll sm=0;
    for(int i=0;i<n;i++)
    {
    	sm+=arr[i];
    	arr2.push_back(arr[i]);
    	if(sm>=(2*k))
    	{
    		break;
    	}
    }
    if(sm < 2*k)
    {
    	cout<<-1<<endl;
    	return;
    }
    ll max = subsetsum(arr2, sm/2);
    ll ans=arr2.size();
    if(max >= k)
    {
    	cout<<ans<<endl;
    }
    else{
    	for(int i=arr2.size();i<n;i++)
    	{
    		max+=arr[i];
    		ans++;
    		if(max>=k)
    		{
    			cout<<ans<<endl;
    			return;
    		}
    	}
    	cout<<-1<<endl;
    }
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
    }
    return 0;
}