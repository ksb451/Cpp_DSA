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

void solve(vector<ll>&arr)
{
	cout<<arr.size()<<endl;
	ll n =arr.size();
	for(int i=0;i<arr.size();i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	multiset<pair<ll,pair<ll,ll>>>dp;
	ll start = 0;
	ll curr  =0;
	for(int i =0;i<n;i++)
	{
		if(arr[i]<0)
		{
			dp.insert({curr, {start, i-1}});
			start = i+1;
			curr = 0;
		}
		else{
			curr+=arr[i];
			if(i==n-1)
			{
				dp.insert({curr, {start, i}});
			}
		}

	}
	auto max1 = *(dp.rbegin());
	if(max1.first == 0 || dp.size()==1 || next(dp.rbegin())->first==0)
	{
		cout<<max1.first<<endl;
		if(max1.first==0)
			cout<<0<<endl;
		else{
			cout<<max1.second.second-max1.second.first+1<<" ";
			for(int i=max1.second.first; i<=max1.second.second;i++)
			{
				cout<<arr[i]<<" ";
			}
			cout<<endl;
		}
		return;
	}
	auto max2 = *(next(dp.rbegin()));
	cout<<max1.first+max2.first<<endl;
	vector<ll>ans;
	for(int i=max1.second.first;i<=max1.second.second;i++)
	{
		ans.push_back(arr[i]);
	}
	for(int i=max2.second.second; i>=max2.second.first; i--)
	{
		
		ans.push_back(arr[i]);
	}
	cout<<ans.size()<<" ";
	if(max2.second.second < max1.second.first)
		reverse(all(ans));
	for(auto i:ans)
	{
		cout<<i<<" ";
	}
	cout<<endl;
}

int main()
{
	srand(time(0));
    fast;
    ll tc = 1;
    IN tc;
    while (tc--)
    {
		int n = rand()%20;
		vector<ll>arr(n);
		for(int i=0;i<n;i++)
		{
			ll par = rand()%2;
			ll curr	= rand()%30;
			if(par)
			{
				curr*=-1;
			}
			arr.push_back(curr);
		}
        solve(arr);
    }
    return 0;
}