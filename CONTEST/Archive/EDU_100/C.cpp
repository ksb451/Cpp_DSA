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
    vector<pll>arr;
    for(int i=0;i<n;i++)
	{
		ll a,b;
		cin>>a>>b;
		arr.push_back({a,b});
	}
	arr.push_back({10000000000LL,0});
	ll curr = 0;
	ll dest = 0;
	ll start,end=0;
	ll count= 0;
	for(int i=0;i<n;i++)
	{
		start=curr;
		//cout<<arr[i].first<<" "<<arr[i].second<<endl;
		//cout<<curr<<" "<<dest<<endl;
		if(curr==dest)
		{
			dest = arr[i].second;
		}
		//cout<<dest<<endl;
		ll next  = arr[i+1].first;
		ll dist = abs(dest-curr);

		ll dir;
		if((dest-curr)<0)
		{
			dir=-1;
		}
		else{
			dir=1;
		}
		//cout<<dist<<" "<<dir<<endl;
		end = curr + (dir * (min(dist, next-arr[i].first)));

		//cout<<ll(next-arr[i].first)<<endl;
		//cout<<start<<" "<<end<<endl;
		
		if(dir<0)
		{
		if(((arr[i].second)<=start) && ((arr[i].second)>=end))
			count++;
		}
		else{
			if(((arr[i].second)<=end) && ((arr[i].second)>=start))
			count++;
		}	
		curr = end;
		//cout<<endl;
	}
	cout<<count<<endl;
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