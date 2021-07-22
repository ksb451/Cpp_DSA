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
//#define endl "\n"
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

bool comp(pll a,pll b)
{
	if(a.first < b.first)
	{
		return true;
	}
	else if(a.first==b.first)
	{
		if(a.second < b.second)
		{
			return true;
		}
	}
	return false;
}

ll fun (vector<pll>&pre, ll x)
{
	ll n =pre.size();
	ll l=0,r=n;
	while(l<r)
	{
		ll mid = l+(r-l)/2;
		if(pre[mid].first < x)
		{
			l=mid+1;
		}
		else{
			r=mid;
		}
	}
	return pre[l].second;
}

void solve()
{
	ll n,m;
    cin>>n>>m;
    vector<ll>arr(n);
    vector<ll>arr1(m);
    for(int i=0;i<n;i++)cin>>arr[i];
    for(int i=0;i<m;i++)cin>>arr1[i];

    vector<pll>pre(n);
	vector<pll>tmp;
	ll mx=arr[0];
	for(int i=0;i<n;i++)
	{
		if(i==0)
		{
			pre[i].first=arr[i];
		}
		else{
			pre[i].first=pre[i-1].first+arr[i];
		}
		pre[i].second=i;
		mx = max(mx,pre[i].first);
		if(pre[i].first < mx)
		{

		}
		else{
			tmp.push_back(pre[i]);
		}
	}
	ll sum = pre[n-1].first;
	sort(all(pre),comp);
	// for(auto i:pre)
	// {
	// 	cout<<i.first<<" ";
	// }
	// cout<<endl;
	for(int i=0;i<m;i++)
	{
		ll ans;
		// cout<<i<<endl;
		ll x = arr1[i];
		// cout<<"x"<<x<<endl;
		ll last = x - mx;
		// cout<<"last"<<last<<endl;
		if(last <= 0)
		{
			ans=0;
		}
		else{
			if(sum <= 0)
			{
				cout<<-1<<" ";
				continue;
			}
			ans = (last+sum-1)/sum;
		}
		// cout<<"ans"<<ans<<endl;
		ll curr = sum*ans;
		// cout<<"curr"<<curr<<endl;
		ans *=n;
		ll t = x-curr;
		// cout<<"t"<<t<<endl;
		ll qq = fun(tmp,t);
		// cout<<"qq"<<qq<<endl;
		ans+=qq;
		cout<<ans<<" ";
	}
	cout<<endl;
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