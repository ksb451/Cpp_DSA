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
	ll a,b;
	cin>>a>>b;
    string s;
    cin>>s;
    vector<pair<char,int>>arr;
    ll n = s.length();
    for(int i=0;i<n;i++)
    {
    	char curr = s[i];
    	int cnt = 1;
    	while(i<n-1 && s[i+1]==curr)
    	{
    		cnt++;
    		i++;
    	}
    	//cout<<curr<<" "<<cnt<<endl;
    	arr.push_back({curr,cnt});
    }
    ll ans=0;
    ll x = arr.size();
    if(arr[x-1].first=='0')
    {
    	arr.pop_back();
    }
    x = arr.size();
    ll i=0;
    while(i<x)
    {
    	if(arr[i].first =='0')
    	{
    		i++;
    	}
    	else{
    		break;
    	}
    }
    for(;i<x;i++)
    {
    	if(arr[i].first=='0')
    	{
    		ll cnt = arr[i].second;
    		if(cnt*b <= a)
    		{
    			ans+=(cnt*b);
    			i++;
    		}
    	}
    	else{
    		ans+=a;
    	}
    }
    cout<<ans<<endl;

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