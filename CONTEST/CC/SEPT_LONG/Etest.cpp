//**sn0wrus**//
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cout.tie(NULL);                   \
    cin.tie(NULL);

#define IN cin >>
#define OUT cout <<
#define endl "\n"
#define all(a) (a).begin(), (a).end()
#define pb push_back
using ll = long long int;
using ld = long double;
using pll = pair<ll, ll>;
using pii = pair<int, int>;
using vll = vector<ll>;
using vi = vector<int>;
const ll mod = (ll)(1e9) + 7LL;
const ll M = 998244353LL;

const int dir8[8][2]={{1,0},{0,1},{-1,0},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
const int dir4[4][2]={{1,0},{0,1},{-1,0},{0,-1}};

/*
for(int i=0;i<n-1;i++)
{
    int a,b;
    cin>>a>>b;
    a--,b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
}
*/

void solve(ll n)
{
	//ll n;
	//cin>>n;
	ll total_sum=(n*(n+1))/2;
	ll ans=0;
	bool flag=true;
	cout<<"start  "<<ll(ceil(double(n)*.70710678))-3<<endl;
	ll start=ll(ceil(double(n)*.70710678))-3;
	start=max(1LL,start);
	ll sum_1=(start*(start-1)/2);
	for(ll i=start;i<=n;i++)
	{
		sum_1 +=i;
		ll sum_2=total_sum-sum_1;
		if(sum_1>sum_2)
		{
			cout<<1<<" "<<i<<endl;
			break;
		}
		else{
			if(sum_1==sum_2)
			{
				ans+=(i*(i-1))/2;
				//cout<<"1 "<<ans<<i<<endl;
				ans+=((n-i)*(n-i-1))/2;
				//cout<<"1 "<<ans<<endl;
			}
			else{
				ll diff=sum_2-sum_1;
				if(!(diff&1))
				{
					diff/=2;
					ll l=max(i+1,1+diff);
					ll r=min(n,i+diff);
					if(r>=l)
					{
						if(flag)
						{
							//cout<<i<<"    ";
							flag=false;
						}
						cout<<i<<" "<<(r-l+1)<<" ";
						ans+=(r-l+1);
					}
					//cout<<"2"<<ans<<endl;
				}
			}
		}
	}
	cout<<endl;
	cout<<n<<" "<<ans<<endl;
}

int main()
{
	fast;
    ll tc = 1;
    IN tc;
    for(ll i=tc-10;i<=tc;i++)
    {
    	solve(i);
    }
    return 0;
}