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

bool knap(ll sum, vector<ll>&arr)
{
    vector<bool>dp(sum+1,false);
    ll n = arr.size();
    dp[0]=true;
    for (int i=0; i<=sum; i++)
      for (int j=0; j<n; j++)
         if (arr[j] <= i)
            dp[i] = (dp[i] || dp[i-arr[j]]);
    return dp[sum];
}

void solve()
{
	ll n,d;
    cin>>n>>d;
    vector<ll>arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];

    vector<ll>S;
	for(int j=0;j<d;j++)
	{
		ll x = j*10+d;
		S.push_back(x);
	}
    for(int i=0;i<n;i++)
    {
    	if(d==1)
    	{
    		cout<<"YES"<<endl;
    		continue;
   		}
   		if(arr[i]<(d*10))
   		{
   			if(knap(arr[i], S))
   			{
   				cout<<"YES"<<endl;
   			}
   			else
   			{
   				cout<<"NO"<<endl;
   			}
   		}
   		else{
   			cout<<"YES"<<endl;
   		}
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