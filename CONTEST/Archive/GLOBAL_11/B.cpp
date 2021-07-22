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

void makeL(string &s, int q, int i)
{
	//cout<<q<<" ";
	while(q--)
	{
		s[i]='W';
		i++;
	}
}

ll solve(ll n,ll k,string s)
{
	ll start=0;
	ll i=0;
		if(s[i]=='L')
		{
			ll count=0;
			while(i<n && s[i]=='L')
			{
				i++;
				count++;
			}
			start=count;
		}
		//cout<<start<<" "<<i<<endl;
	if(i==n)
	{
		return(2*k - 1);
	}
	ll j=n-1;
	ll last=0;
	if(s[j]=='L')
	{
		ll count=0;
		while(j>=0 && s[j]=='L')
		{
			j--;
			count++;
		}
		last=count;
	}
	//cout<<last<<" "<<j<<endl;
	set<pll>ss;
	for(ll x=i;x<=j;x++)
	{
		if(s[x]=='L')
		{
			ll q=x;
			ll count=0;
			while(x<=j && s[x]=='L')
			{
				count++;
				x++;
			}
			ss.insert({count,q});
		}
	}
	while(k>0)
	{
		if(!ss.empty())
		{
			auto xx = *ss.begin();
			if(xx.first<=k)
			{
				ss.erase(ss.begin());
				makeL(s,xx.first,xx.second);
				k-=xx.first;
			}
			else{
				break;
			}
		}
		else{
			break;
		}
	
	}
	if(!ss.empty())
	{
		auto xx = *ss.begin();
		ll cnt = min(k,xx.first);
		ss.erase(ss.begin());
		makeL(s,cnt,xx.second);
		k-=cnt;
	}
	if(k>0)
	{
		ll cnt = min(last,k);
		k-=cnt;
		makeL(s,cnt,n-last);
	}
	if(k>0)
	{
		ll cnt = min(k,start);
		makeL(s, cnt, start-cnt);
	}
	ll ans=0;
	bool flag=false;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='W')
		{
			if(flag)
			{
				ans+=2;
			}
			else{
				ans+=1;
				flag=true;
			}
		}
		else{
			flag=false;
		}
	}
	return ans;
}

int main()
{
    fast;
    ll tc = 1;
    IN tc;
    while (tc--)
    {
    	ll n,k;
    	cin>>n>>k;
    	string s;
    	cin>>s;
    	ll ans=0;
        ans=max(solve(n,k,s),ans);
        cout<<ans<<endl;
    }
    return 0;
}