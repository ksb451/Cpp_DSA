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

string addone(string s)
{
	// cout<<s<<endl;
	string ans="";
	ll carry=1;
	for(int i = s.length()-1;i>=0;i--)
	{
		ll curr = s[i]-'0';
		ll nxt = curr+carry;
		// cout<<curr<<" "<<nxt<<endl;
		if(nxt==10)
		{
			carry=1;
		}
		else{
			carry=0;
		}
		nxt%=10;
		ans = char('0'+nxt) + ans;
	}
	// cout<<ans<<endl;
	return ans;
}

void solve()
{
    ll n;
    cin>>n;
    vector<string>arr(n);
    for(int i=0;i<n;i++)
    {
    	cin>>arr[i];
    }
    ll ans=0;
    for(int i=1;i<n;i++)
    {
    	string prev = arr[i-1];
    	string curr = arr[i];
    	// cout<<curr<<" "<<prev<<endl;
    	if(curr.length() > prev.length())
    	{
    		continue;
    	}
    	else{
    		if(curr.length() == prev.length())
    		{
    			if(curr > prev)
    			{
    				continue;
    			}
    			else{
    				curr+='0';
    				arr[i]=curr;
    				ans++;
    				continue;
    			}
    		}
    		else{
    			string sub = prev.substr(0,curr.length());
    			if(sub < curr)
    			{
    				ans+=(prev.length() - curr.length());
    				curr += string(prev.length() - curr.length(),'0');
    				arr[i]=curr;
    			}
    			else if(sub > curr)
    			{
    				ans+=(prev.length() - curr.length() + 1);
    				curr += string(prev.length() - curr.length() + 1,'0');
    				arr[i]=curr;
    			}
    			else{
    				ll sm = 0;
    				for(int j = curr.length();j<prev.length();j++)
					{
						if(prev[j] < '9')
						{
							sm=3;
						}
					}
					if(sm==3)
					{
						string nxt = addone(prev.substr(curr.length()));
						ans+=nxt.length();
						curr+=nxt;
						arr[i]=curr;
					}
					else{
						for(int j=curr.length();j<prev.length();j++)
						{
							curr+='0';
							ans++;
						}
						curr+='0';
						ans++;
						arr[i]=curr;
					}
    			}
    		}
    	}
    }
    // write(arr);
    cout<<ans<<endl;
    return;
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