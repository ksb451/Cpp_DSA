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
	ll n,a,b;
    cin>>n>>a>>b;
    string s;
    cin>>s;
    vector<ll>aa;
    vector<ll>bb;
    ll i=0;
    while(a)
    {
    	if(i<n-1)
    	{
    		if((s[i]=='0')&&(s[i+1]=='0'))
    		{
    			aa.push_back(i);
    			s[i]='1';
    			s[i+1]='1';
    			i+=2;
    			a--;
    		}
    		else{
    			i++;
    		}
    	}
    	else{
    		break;
    	}
    }
    i=0;
    while(b)
    {
    	if(i<n)
    	{
    		if(s[i]=='0')
    		{
    			bb.push_back(i);
    			s[i]='1';
    			i++;
    			b--;
    		}
    		else{
    			i++;
    		}
    	}
    	else{
    		break;
    	}
    }
    if((a==0) && (b==0))
    {
    	cout<<"YES"<<endl;
    	for(auto i:aa)
    	{
    		cout<<i+1<<" "<<i+2<<endl;
    	}
    	for(auto i:bb)
    	{
    		cout<<i+1<<endl;
    	}
    }
    else{
    	cout<<"NO"<<endl;
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