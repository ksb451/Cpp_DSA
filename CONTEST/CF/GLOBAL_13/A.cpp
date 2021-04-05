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
	ll n,qq;
    cin>>n>>qq;
    vector<ll>arr(n);
    ll cnt0=0,cnt1=0;
    for(int i=0;i<n;i++){
    	cin>>arr[i];
    	if(arr[i]==0)
    	{
    		cnt0++;
    	}
    	else{
    		cnt1++;
    	}
    }
    while(qq--)
    {
    	ll x;
    	cin>>x;
    	if(x==1)
    	{
    		ll q;
    		cin>>q;
    		q--;
    		if(arr[q]==0)
    		{
    			cnt0--;
    			cnt1++;
    			arr[q]=1;
    		}
    		else{
    			cnt0++;
    			cnt1--;
    			arr[q]=0;
    		}
    	}
    	else
    	{
    		ll q;
    		cin>>q;
    		if(q>cnt1)
    		{
    			cout<<0<<endl;
    		}
    		else{
    			cout<<1<<endl;
    		}
    	}
    }
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