//**sn0wrus**//
#include <bits/stdc++.h>
using namespace std;

using ll = long long int;


int typee(pair<ll,ll>a)
{
	if(a.first==a.second)
	{
		return 2;
	}
	else if(a.first < a.second)
	{
		return 1;
	}
	else{
		return 3;
	}
}

void solve()
{
	ll n;
    cin>>n;
    vector<pair<ll,ll>>arr(n);
    for(int i=0;i<n;i++)cin>>arr[i].first;
	for(int i=0;i<n;i++)cin>>arr[i].second;
	
	sort(arr.begin(),arr.end(),[](pair<ll,ll>a,pair<ll,ll>b){
		ll type1=typee(a);
		ll type2=typee(b);
		if(type1 < type2)
		{
			return true;
		}
		if(type1==type2)
		{
			if(a.first < b.first)
			{
				return true;
			}
		}
		return false;
	});

	ll ans=0;
	vector<vector<ll>>res;
	for(int i=0;i<n;i++)
	{
		// cout<<arr[i].first<<" "<<arr[i].second<<endl;
		ans+=arr[i].first;
		res.push_back({ans, arr[i].second});
	}
	ans=0;
	for(int i=0;i<n;i++)
	{
		// cout<<res[i][0]<<" "<<res[i][1]<<endl;
		if(res[i][0]<=ans)
		{
			ans+=res[i][1];
		}
		else{
			ans= res[i][0]+res[i][1];
		}
	}   
	cout<<ans<<endl;
}

int main()
{
    solve();
    return 0;
}