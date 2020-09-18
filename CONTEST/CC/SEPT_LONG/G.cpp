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

void solve(ll k)
{
	ll n;
	cin>>n;
	if(k==1)
	{
		if(n==1)
		{
			cout<<1<<endl<<"1"<<endl;
			return;
		}
		else if(n==2)
		{
			cout<<1<<endl<<"10"<<endl;
		}
		else if(n==3)
		{
			cout<<0<<endl<<"110"<<endl;
		}
		else{
			string ans(n,'0');
			if(n&1)
			{
				for(int i=0;i<n/2;i+=2)
				{
					ans[i+1]='1';
					ans[n-i-1]='1';
				}
				if((n/2) & 1)
				{
					ans[n/2]='0';
					cout<<0<<endl<<ans<<endl;
					return;
				}
				cout<<1<<endl<<ans<<endl;
			}
			else{
				for(int i=0;i<n/2;i+=2)
				{
					ans[i]='1';
					ans[n-i-1]='1';
				}
				if((n/2) & 1)
				{
					ans[n/2]='0';
					cout<<1<<endl<<ans<<endl;
					return;
				}
				cout<<0<<endl<<ans<<endl;
			}
		}
	}
	else if(k==2)
	{
		ll val = pow(2, n); 
	    ll sep = n / 2; 
	    ll grp1 = 0; 
	    ll grp2 = 0; 
	    
	    grp1 = grp1 + val; 
	      
	    for(int i = 1; i < sep; i++) 
	       grp1 = grp1 + pow(2, i); 
	          
	   
	    for(int i = sep; i < n; i++) 
	       grp2 = grp2 + pow(2, i); 
	          
	   
	    cout << (abs(grp1 - grp2)); 
	}
}

int main()
{
    fast;
    ll k;
    ll tc = 1;
    cin>>k>>tc;
    //IN tc;
    while (tc--)
    {
        solve(k);
    }
    return 0;
}