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

ll solve(ll n,ll q)
{
	vector<ll>ans;
	cout<<"1 2 3"<<nl;
	cout.flush();
	ll x;
	cin>>x;
	if(x==1)
	{
		ans.push_back(2);
		ans.push_back(1);
		ans.push_back(3);
	}
	else if(x==2)
	{
		ans.push_back(1);
		ans.push_back(2);
		ans.push_back(3);
	}
	else{
		ans.push_back(2);
		ans.push_back(3);
		ans.push_back(1);
	}
	for(ll i=4;i<=n;i++)
	{
		ll nn=ans.size();
		ll l=0,r=nn;
		while(1)
		{
			ll mid = (l+r)/2;
			if(mid==(nn-1))
			{
				ans.insert(ans.begin()+mid+1, i);
				break;
			}
			//cout<<l<<" "<<r<<" "<<mid<<nl;
			cout.flush();
			cout<<ans[mid]<<" "<<ans[mid+1]<<" "<<i<<endl;
			cout.flush();
			cin>>x;
			if(x==-1)
			{
				return -1;
			}
			if(mid==0)
			{
				if(x==ans[mid])
				{
					ans.insert(ans.begin()+mid, i);
					break;
				}
				else if(x==(ans[mid+1]))
				{
					l=mid+1;
					continue;
				}
				else if(x==(i))
				{
					ans.insert(ans.begin()+mid+1,i);
					break;
				}
			}
			else{
				
				if(x==ans[mid])
				{
					r=mid;
					continue;
				}
				else if(x==(ans[mid+1]))
				{
					l=mid+1;
					continue;
				}
				else if(x==(i))
				{
					ans.insert(ans.begin()+mid+1,i);
					break;
				}
			}
		}
		//cout<<"array";
		//write(ans);
		cout.flush();
	}
	write(ans);
	cout.flush();
	cin>>x;
	return x;
    
}

int main()
{
    ios_base::sync_with_stdio(false); 
    cout.tie(NULL);
    cin.tie(NULL);
    ll tc = 1;
    IN tc;
	ll n,q;
	cin>>n>>q;    
    for (int i = 1; i <= tc; i++)
    {
        //cout << "Case #" << i << ": ";
        ll x=solve(n,q);
        if(x==-1){
        	break;
        }
    }
    return 0;
}