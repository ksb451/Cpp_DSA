#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

#define ll long long 
#define llf long long double

int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		vector<int>arr;
		ll ans=0;
		for(int i=0;i<n;i++)
		{
			ll x;
			cin>>x;
			arr.push_back(x);
			if(i>0)
			{
				ans+=(abs(arr[i]-arr[i-1])-1);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}