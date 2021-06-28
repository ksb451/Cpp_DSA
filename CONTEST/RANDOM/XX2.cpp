
#include <bits/stdc++.h>
using namespace std;


using ll = long long int;

void solve()
{
	ll n;
    cin>>n;
    vector<ll>arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];

    sort(arr.begin(),arr.end());
	
	ll ans=0;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			ll diff =arr[j]-arr[i];
			ll low = arr[j]+diff;
			ll high=arr[j]+(diff*2);
			ll l= lower_bound(arr.begin(),arr.end(),low)-arr.begin();
			ll r= upper_bound(arr.begin(),arr.end(),high)-arr.begin();
			ans+=(r-l);
		}
	}
	cout<<ans<<endl;
}

int main()
{
    
        solve();
    return 0;
}