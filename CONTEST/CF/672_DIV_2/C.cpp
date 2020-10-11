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

ll solve1 (vector<pll>&arr, ll a)
{
	ll ans;
	ll n  = arr.size();
	if(a!=0)
	{
		if(arr[a-1].first>arr[a].first)
		{
			ans = 
		}
	}
	
}

void solve()
{
	ll n,q;
    cin>>n>>q;
    vector<pll>arr(n);
    for(int i=0;i<n;i++)cin>>arr[i].first;
    int inc = 1;
	ll ans = 0;
	for(int i=0;i<n;i++)
	{
		if(inc)
		{
			if(i==n-1 || arr[i+1].first<arr[i].first)
			{
				arr[i].second=3;
				ans+=arr[i].first;
				inc = 0;
			}
			else{
				arr[i].second = 2;
			}
		}
		else{
			if(i!=n-1 && arr[i+1].first>arr[i].first)
			{
				arr[i].second = 0;
				ans-=arr[i].first;
				inc = 1;
			}
			else{
				arr[i].second = 1;
			}
		}
	}
	cout<<ans<<endl;
	// for(auto i:arr)
	// {
	// 	cout<<i.second<<" ";
	// }
	// cout<<endl;
	while(q--)
	{
		ll a,b;
		cin>>a>>b;
		a--,b--;
		if(a==b)
		{
			cout<<ans<<endl;
			continue;
		}
		auto x =arr[a];
		auto y = arr[b];
		if(arr[a].second==3)
		{
			ans-=arr[a].first;
		}
		if(arr[a].second==0)
		{
			ans+=arr[a].first;
		}
		if(arr[b].second==3)
		{
			ans-=arr[b].first;
		}
		if(arr[b].second==0)
		{
			ans+=arr[b].first;
		}
		ll temp  = arr[a].first;
		arr[a].first = arr[b].first;
		arr[b].first=temp;
		
		ll q = solve1(arr, a);


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