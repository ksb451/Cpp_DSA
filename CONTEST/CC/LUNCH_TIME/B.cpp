/******************************************
* AUTHOR : Keshab Agrawal *
* NICK : sn0wrus *
******************************************/
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cout.tie(NULL);                   \
    cin.tie(NULL);

#define IN cin >>
#define OUT cout <<
#define nl "\n"
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define write(a)          \
    for (auto x : a)      \
    {                     \
        cout << x << " "; \
    }                     \
    cout << nl;
#define read(a)       \
    for (auto &x : a) \
    {                 \
        cin >> x;     \
    }
using ll = long long int;
using ld = long double;
using pll = pair<ll, ll>;
using pii = pair<int, int>;
using vll = vector<ll>;
using vi = vector<int>;
const ll mod = (ll)(1e9) + 7LL;
const ll M = 988244353LL;

void solve()
{
	int n,d;
	cin>>n>>d;
	cout<<setprecision(6)<<fixed;
	std::vector<long double> arr(n);
	for (int i =0; i < n; ++i)
	{
		cin>>arr[i];
	}
	sort(all(arr));
	ld l=0,r=1e10,mid,ans=0,time;
	while(r-l>=1e-7)
	{
		mid=(r+l)/2;
		time=arr[0];
		int i;
		for(i=0;i<n-1;i++)
		{
			if(time+mid > (arr[i+1]+d))
			{
				break;
			}
			time=max(arr[i+1],time+mid);
		}
		if(i==n-1)
		{
			ans=mid;
			l=mid+1e-7;
		}
		else
			r=mid-1e-7;
	}
	cout<<ans<<endl;
}

int main()
{
    ll tc = 1;
    IN tc;
    while (tc--)
    {
        solve();
    }
    return 0;
}