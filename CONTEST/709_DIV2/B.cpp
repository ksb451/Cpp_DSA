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
    vector<ll>arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    ll m=0,c=0;
	bool flag=true;
	for(auto i:arr)
	{
		if(i == arr[0])
		{
			continue;
		}
		else{
			flag=false;
			break;
		}
	}
	if(flag)
	{
		cout<<0<<endl;
		return;
	}
    for(int i=1;i<n;i++)
    {
    	if(arr[i]>arr[i-1])
    	{
    		//cout<<i<<1<<endl;
    		if(c==0)
    			c=arr[i]-arr[i-1];
    		else{
    			if(c!=(arr[i]-arr[i-1]))
    			{
    				cout<<-1<<endl;
    				return;
    			}
    		}
    	}
    	else if(arr[i]<arr[i-1])
    	{
    		//cout<<i<<2<<endl;
    		if(c!=0)
    		{
    			if(m==0)
    				m= arr[i-1]+(c-arr[i]);
    			else{
    				if(m!=(arr[i-1]+(c-arr[i])))
    				{
    					cout<<-1<<endl;
    					return;
    				}
    			}
    		}
    	}
    	else if(arr[i]==arr[i-1]){
    		//cout<<i<<3<<endl;
    		cout<<-1<<endl;
    		return;
    	}
    }

    if(m==0)
    {
    	cout<<0<<endl;
    }
    else{
    	cout<<m<<" "<<c<<endl;
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