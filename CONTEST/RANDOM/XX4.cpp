#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

ll dp[400][400];

ll rec(ll l, ll r, string &s)
{
	if(l > r)
		return 0;
	if(l == r)
		return 1;
	if(dp[l][r] == -1)
	{	
		ll res = 1 + rec(l + 1,r,s);

		for (int i = l + 1; i <= r; ++i) {

			if (s[l] == s[i])
				res = min(res, rec(l + 1, i - 1, s)
								+ rec(i, r,s));
		}
		return dp[l][r] = res;
	}
	else
		return dp[l][r];
}

void solve()
{
	ll n;
	cin>>n;
	string s;
	for(int i=0;i<n;i++)
	{
		string ss;
		cin>>ss;
		s+=ss;
	}
	memset(dp,-1,sizeof(dp));
	cout<<rec(0,s.length()-1, s)<<endl;

}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}
