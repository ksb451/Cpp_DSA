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

void solve()
{
	ll n;
    cin>>n;
    vector<ll>arr(n*2);
    for(int i=0;i<n*2;i++){
    	cin>>arr[i];
    }
    ll x;
    vector<pll>ans;
	for(int i=0;i<2*n;i++)
	{
		multiset<ll>S;
		ll ind=0;
		ll mx = -1;
		for(int j=0;j<2*n;j++)
		{
			S.insert(arr[j]);
			if(arr[j]>=mx)
			{
				mx=arr[j];
				ind=j;
			}
		}
		ll a = *S.rbegin();
		auto temp = S.find(a);
		S.erase(temp);
		if(i!=ind)
		{
			ll b=arr[i];
			temp = S.find(b);
			S.erase(temp);
			x=a+b;
			ans.push_back({a,b});
			while(!S.empty())
	    	{
	    		ll curr = max(a,b);
				a = *S.rbegin();
				temp = S.find(a);
				S.erase(temp);
				if(S.find(curr-a)!=S.end())
				{
					temp = S.find(curr-a);
					b  = *temp;
					ans.push_back({a,b});
					S.erase(temp);
				}
				else{
					break;
				}
	    	}
	    	if(S.empty())
	    	{
	    		cout<<"YES"<<endl;
	    		cout<<x<<endl;
	    		for(auto i: ans)
	    		{
	    			cout<<i.first<<" "<<i.second<<endl;
	    		}
	    		return;
	    	}
	    	else{
	    		ans.clear();
	    	}
		}
	}
    cout<<"NO"<<endl;
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