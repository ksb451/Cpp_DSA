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
	string s;
	cin>>s;
	ll n = s.length();
	ll ans=0;
	if(n==1)
	{
		cout<<0<<endl;
		return;
	}
	else if(n==2)
	{
		if(s[0]==s[1])
		{
			cout<<1<<endl;
		}
		else{
			cout<<0<<endl;
		}
		return;
	}
	vector<int>arr(n,0);
	if(s[0]==s[1] && s[0]==s[2])
	{
		ans=2;
		arr[1]=1;
		arr[2]=1;
	}
	else{
		if(s[0]==s[1])
		{
			ans=1;
			arr[1]=1;
		}
		else if(s[1]==s[2])
		{
			ans=1;
			arr[2]=1;
		}
		else if(s[0]==s[2])
		{
			ans=1;
			arr[2]=1;
		}
	}
	for(int i=3;i<n;i++)
	{
		if((s[i]==s[i-1]) && (s[i]==s[i-2]))
		{
			if(arr[i-1] && arr[i-2])
			{
				continue;
			}
			ans++;
			arr[i]=1;
		}
		else if(s[i]==s[i-1])
		{
			if(arr[i-1]==0)
			{
				arr[i]=1;
				ans++;
			}
			
		}
		else if(s[i]==s[i-2])
		{	
			if(arr[i-2]==0)
			{
				arr[i]=1;
				ans++;
			}
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