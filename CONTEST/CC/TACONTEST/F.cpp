/******************************************
* AUTHOR : Keshab Agrawal *
* NICK : sn0wrus *
******************************************/
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

ll sum_r(ll a,ll b)
{
	return ((b*(b+1))-(a*(a-1)))/2;
}

void solve()
{
	ll n,s;
    cin>>n>>s;
    vector<ll>arr(n+1,0);
    for(ll i=1;i<=n;i++)
    {
    	cin>>arr[i];
    	arr[i]+=arr[i-1];
    }
    ll sum=0;
    for(ll i=n;i>0;i--)
    {
    	for(ll j=1;j+i-1<=n;j++)
    	{
    		sum=0;
    		sum=arr[j+i-1]-arr[j-1];
    		sum+=(i*(sum_r(j,j+i-1)));
    		if(sum<=s)
    		{
    			cout<<i<<endl;
    			return;
    		}
    	}
    }
    cout<<0<<endl;
    return;
}

int main()
{
    ll tc = 1;
    //IN tc;
    while (tc--)
    {
        solve();
    }
    return 0;
}