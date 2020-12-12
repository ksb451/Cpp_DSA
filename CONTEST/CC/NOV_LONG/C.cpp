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
	ll n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    vector<int>sheet(n,0);
    ll sh_cnt=0;
    vector<int>block(n,0);
    deque<int>mag;
    deque<int>iron;
    ll ans=0;
    for(int i=0;i<n;i++)
    {
    	sheet[i]=sh_cnt;
    	if(s[i]=='I')
    	{
    		bool flag=false;
    		while(mag.empty()==false)
    		{
    			ll x = mag.front();
    			mag.pop_front();
    			ll p = k+1-abs(i-x)-(sheet[i]-sheet[x]);
    			if(p>0)
    			{
    				ans++;
    				flag=true;
    				break;
    			}
    		}
    		if(!flag)
    		{
    			iron.push_back(i);
    		}
    	}
    	else if(s[i]=='M')
    	{
    		bool flag=false;
    		while(iron.empty()==false)
    		{
    			ll x = iron.front();
    			iron.pop_front();
    			ll p = k+1-abs(i-x)-(sheet[i]-sheet[x]);
    			if(p>0)
    			{
    				ans++;
    				flag=true;
    				break;
    			}
    		}
    		if(!flag)
    		{
    			mag.push_back(i);
    		}
    	}
    	else if(s[i]==':'){
    		sh_cnt ++;
    		sheet[i]=sh_cnt;
    	}
    	else if(s[i]=='X')
    	{
    		mag.clear();
    		iron.clear();
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