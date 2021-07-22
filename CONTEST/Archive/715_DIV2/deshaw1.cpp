//**sn0wrus**//
#include <bits/stdc++.h>
using namespace std;

#define all(a) (a).begin(), (a).end()
#define allr(a) (a).rbegin(), (a).rend()

using ll = long long int;
const ll mod = (ll)(1e9) + 7LL;

void solve()
{
	ll n;
    cin>>n;
    vector<ll>arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    ll k;
	cin>>k;
	sort(all(arr));
	ll ans=0;
	for(int i=0;i<n;i+=k)
	{
		ll curr=1;
		for(int j=i;j<i+k;j++)
		{
			curr*=arr[j];
			curr%=mod;
		}
		ans+=curr;
		ans%=mod;
	}
	cout<<ans<<endl;
	return;

}

int main()
{
  
    solve();
    return 0;
}