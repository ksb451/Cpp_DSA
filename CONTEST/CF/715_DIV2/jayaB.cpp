//**sn0wrus**//
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

using ll = long long int;
using pll = pair<ll, ll>;   


ll len(ll x)
{
	ll ans=0;
	while(x)
	{
		ans++;
		x = (x>>1);
	}
	return ans;
}

void solve()
{
	string s;
	cin>>s;
	ll n;
	n = s.length();
	multiset<pll>pre;
	ll zeros =0;
	ll ans=0;
	for(int i=0;i<n;i++)
	{
		multiset<pll>temp;
		for(auto j:pre)
		{
			ll z = j.first;
			ll x = j.second;
			x = (x<<1);
			x = (x|(s[i]-'0'));
			if(x>n)
			{
			}
			else{
				if(len(x)+z >= x)
				{
					ans++;
				}
				temp.insert({z,x});
			}
		}
		pre = temp;
		if(s[i]=='0')
		{
			zeros++;
		}
		else{
			ans++;
			pre.insert({zeros,1});
			zeros = 0;
		}
	}
	cout<<ans<<endl;
}

int main()
{
    ll n;
    cin>>n;
    while (n--)
    {
        solve();
    }
    return 0;
}