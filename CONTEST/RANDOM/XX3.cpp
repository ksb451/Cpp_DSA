
#include <bits/stdc++.h>
using namespace std;


using ll = long long int;
const ll maxn=100005; 
const ll MAX = (ll)1e15;
const ll MIN = (ll)-1e15;
ll dp[maxn][5][2];

pair<ll,ll> rec(ll curr, ll k, vector<ll>&arr)
{

	ll n= arr.size();
	if(curr >=n)
	{
		return{MIN,MAX};
	}
	if(k==1)
	{
		
		ll sum = accumulate(arr.begin()+curr, arr.end(),0LL);
		// cout<<"case"<<curr<<" "<<k<<endl;
		// cout<<sum<<" "<<sum<<endl;
		return {sum,sum};
	}
	if(dp[curr][k][0]==-1)
	{
		ll curr_diff=MAX;
		ll mx,mn;
		ll sum = 0;
		for(ll i=curr;i<n;i++)
		{
			sum+=arr[i];
			ll t_mn, t_mx;
			t_mx =sum;
			t_mn =sum;
			auto x = rec(i+1, k-1,arr);
			t_mx = max(t_mx, x.second);
			t_mn = min(t_mn, x.first);
			if((t_mx-t_mn) < curr_diff)
			{
				curr_diff = t_mx-t_mn;
				mx=t_mx;
				mn=t_mn;
			}
		}
		dp[curr][k][0] = mn;
		dp[curr][k][1] = mx;
	}
	// cout<<"case"<<curr<<" "<<k<<endl;
	// cout<<dp[curr][k][0]<<" "<<dp[curr][k][1]<<endl;
	return {dp[curr][k][0],dp[curr][k][1]};
}

void solve()
{
	ll n;
    cin>>n;
    vector<ll>arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    memset(dp,-1,sizeof(dp));
	auto x = rec(0,4,arr);
	cout<<x.second-x.first<<endl;
	return;
}

int main()
{
    
        solve();
    return 0;
}