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

ld fac;
ld total;

void rec(vector<ll>arr,ld score)
{
	if(arr.size()==1)
	{
		//	cout<<score<<endl;
		total+=score;
	}
	else{
		ll n = arr.size();
		//write(arr);
		for(int i=0;i<n-1;i++)
		{
			//cout<<i<<" "<<arr[i]+arr[i+1]<<endl;
			ld curr=score;
			curr+=(arr[i]+arr[i+1]);
			vector<ll>x;
			for(int j=0;j<n;j++)
			{
				//cout<<j<<" ";
				if(j==i)
				{
					x.push_back(arr[i]+arr[i+1]);
					j++;	
				}
				else{
					x.push_back(arr[j]);
				}
			}
			//write(x);
			rec(x,curr);
		}
	}
}

void solve()
{
    ll n;
    cin>>n;
    vector<ll>arr(n);
    for(int i=0;i<n;i++)
    {
    	cin>>arr[i];
    }
    total =0;
    fac=1;
    for(ll i=1;i<n;i++)
    {
    	fac*=i;
    }

    rec(arr,0);
    std::cout.precision(6);
    std::cout.setf( std::ios::fixed, std:: ios::floatfield );
    cout<<total<<endl;
}

int main()
{
	ios_base::sync_with_stdio(false); 
    cout.tie(NULL);
    cin.tie(NULL);
    ll tc = 1;
    IN tc;
    for (int i = 1; i <= tc; i++)
    {
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}