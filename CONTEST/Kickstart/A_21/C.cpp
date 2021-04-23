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

bool is_prime(ll n)
{
	ll x = sqrt(n);
	for(ll i =2;i<=x ;i++)
	{
		if((n%i)==0)
		{
			return false;
		}
	}
	return true;
}

void solve()
{
    ll n;
    cin>>n;
    ll x = sqrt(n);
    ll prev;
	ll i = x+1;
	while(true)
	{
		if(is_prime(i))
		{
			if(is_prime(x))
			{
				if((i*x )<= n)
				{
					cout<< i*x <<endl;
					return;
				}
			}
			prev = i;
			break;
		}
		i++;
	}
	i =x;
	while(true)
	{
		if(is_prime(i))
		{
			if((i*prev )<= n)
			{
				cout<< i*prev <<endl;
				return;
			}
			else{
				prev = i;
			}
		}
		i--;
	}
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