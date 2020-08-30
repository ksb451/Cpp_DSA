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
	int n;
	cin>>n;
	std::vector<int> arr(n);
	for (int i = 0; i < n; ++i)
	{
			cin>>arr[i];
	}	
	int max_len=0;
	int curr_len=0;
	int max_len_2=0;
	for(int i=0;i<n;i++)
	{
		if(arr[i]==1)
		{
			if(curr_len>=max_len)
			{
				max_len_2=max_len;
				max_len=curr_len;
			}
			else if(curr_len>=max_len_2)
			{
				max_len_2=curr_len;
			}
			curr_len=0;
		}
		else{
			curr_len++;
		}
	}
	bool flag;
	if(max_len==0)
	{
		flag=false;
	}
	else if(max_len_2==max_len)
	{
		flag=false;
	}
	else
	{
		if(max_len%2==1)
		{
			if(max_len_2>(max_len/2))
			{
				flag=false;
			}
			else
				flag=true;
		}
		else{
			flag=false;
		}
	}
	if(flag)
	{
		cout<<"Yes"<<endl;
	}
	else{
		cout<<"No"<<endl;
	}
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