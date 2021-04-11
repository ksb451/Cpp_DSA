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
const ll INF = 1e9;
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
	ll n1,n2,n3,n4;
    cin>>n1>>n2>>n3>>n4;
    vector<ll>arr1(n1);
    vector<ll>arr2(n2);
    vector<ll>arr3(n3);
    vector<ll>arr4(n4);
    for(int i=0;i<n1;i++)cin>>arr1[i];
    for(int i=0;i<n2;i++)cin>>arr2[i];
    for(int i=0;i<n3;i++)cin>>arr3[i];
    for(int i=0;i<n4;i++)cin>>arr4[i];

    vector<ll>adj1[n2];
	vector<ll>adj2[n3];
	vector<ll>adj3[n4];

	ll x;
	cin>>x;
	for(int i=0;i<x;i++)
	{
		ll a,b;
		cin>>a>>b;
		adj1[b-1].push_back(a-1);
	}
	
	cin>>x;
	for(int i=0;i<x;i++)
	{
		ll a,b;
		cin>>a>>b;
		adj2[b-1].push_back(a-1);
	}
	cin>>x;
	for(int i=0;i<x;i++)
	{
		ll a,b;
		cin>>a>>b;
		adj3[b-1].push_back(a-1);
	}

	multiset<ll>S(all(arr1));
	//cout<<"input done"<<endl;
	
	
	for(int i=0;i<n2;i++)
	{
		for(auto j:adj1[i])
		{
			ll q = arr1[j];
			auto tmp = S.find(q);
			S.erase(tmp);
		}
		//cout<<"ch1"<<endl;
		ll mn =  (S.empty())?INF:(*S.begin());
		arr2[i]+=mn;
		for(auto j:adj1[i])
		{
			S.insert(arr1[j]);
		}
	}
	//cout<<"first dp done"<<endl;

	S = multiset<ll>(all(arr2));

	for(int i=0;i<n3;i++)
	{
		for(auto j:adj2[i])
		{
			ll q = arr2[j];
			auto tmp = S.find(q);
			S.erase(tmp);
		}
		ll mn =  (S.empty())?INF:(*S.begin());
		arr3[i]+=mn;
		for(auto j:adj2[i])
		{
			S.insert(arr2[j]);
		}
	}


	//cout<<"second dp done"<<endl;

	S = multiset<ll>(all(arr3));


	for(int i=0;i<n4;i++)
	{
		for(auto j:adj3[i])
		{
			ll q = arr3[j];
			auto tmp = S.find(q);
			S.erase(tmp);
		}
		ll mn =  (S.empty())?INF:(*S.begin());
		arr4[i]+=mn;
		for(auto j:adj3[i])
		{
			S.insert(arr3[j]);
		}
	}


	//cout<<"third dp done"<<endl;

	ll ans = *min_element(all(arr4));
	cout<<((ans>=INF)?-1:ans)<<endl;
	return;

}

int main()
{
    fast;
    ll tc = 1;
    //IN tc;
    while (tc--)
    {
        solve();
    }
    return 0;
}