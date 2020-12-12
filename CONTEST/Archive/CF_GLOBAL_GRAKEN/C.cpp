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

void solve()
{
	ll n;
	double l;
    cin>>n>>l;
    vector<double>arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    double s1=0,s2=0, dist=0, rel =0;
	s1=1;
	s2=1;
	rel =2;
	ll i = 0;
	ll j =n-1;
	double a = 1;
	double b = l;
	double ans = 0;
	while(true)
	{
		double next_a = (arr[i]-a)/s1;
		double next_b = (b-arr[j])/s2;
		if(next_a<next_b)
		{
			i++;
			if(((l-dist)/rel) < next_a)
			{
				ans+=((l-dist)/rel);
				break;
			}
			else{
				dist+=(rel*next_a);
				ans+=next_a;
			}
			a=arr[i];
			b-=(s2*next_a);
			s2+=1;
			rel+=1;
		}
		else if(next_a>next_b){
			j--;
			if(((l-dist)/rel) < next_b)
			{
				ans+=((l-dist)/rel);
				break;
			}
			else{
				dist+=(rel*next_b);
				ans+=next_b;
			}
			b=arr[j];
			a+=(s1*next_b);
			s2+=1;
			rel+=1;
		}
		else{
			j--;
			i++;
			if(((l-dist)/rel) < next_b)
			{
				ans+=((l-dist)/rel);
				break;
			}
			else{
				dist+=(rel*next_b);
				ans+=next_b;
			}
			b=arr[j];
			a=arr[i];
			s1+=1;
			s2+=1;
			rel+=2;
		}
	}
	cout<<ans<<endl;
}

int main()
{
    //fast;
    ll tc = 1;
    IN tc;
    while (tc--)
    {
        solve();
    }
    return 0;
}