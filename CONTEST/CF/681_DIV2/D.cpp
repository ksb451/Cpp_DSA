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
    vector<ll>a(n);
    for(int i=0;i<n;i++)cin>>a[i];

    vector<int>arr;
	arr.push_back(a[0]);
	for(int i=1;i<n;i++)
	{
		if(a[i]!=a[i-1])
		{
			arr.push_back(a[i]);
		}
	}
	n = arr.size();
    if(n<=2)
    {
    	cout<<"YES"<<endl;
    	return;
    }
    ll peak = 0;
    ll dip = 0;
    for(int i=0;i<n;i++)
    {
    	if(i==0)
    	{
    		if(arr[i+1]>arr[i])
    		{
    			dip+=arr[i];
    		}
    	}
    	else if(i==n-1)
    	{
    		if(arr[i-1]>arr[i])
    		{
    			dip+=arr[i];
    		}
    	}
    	else{
    		if((arr[i+1]<arr[i]) && (arr[i-1]<arr[i]))
    		{
    			peak+=arr[i];
    		}
    		if((arr[i+1]>arr[i]) && (arr[i-1]>arr[i]))
    		{
    			dip+=arr[i];
    		}
    	}
    }
    if(peak<=dip)
    {
    	cout<<"YES"<<endl;
    	return;
    }
    else{
    	cout<<"NO"<<endl;
    	return;
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