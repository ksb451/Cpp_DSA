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
	ll n,k;
    cin>>n>>k;
	string s;
	cin>>s;
	bool flag=true;
	for(int i=0;i<k;i++)
	{
		char curr='?';
		for(int j=i;j<n;j+=k)
		{
			if(s[j]!='?')
			{
				curr=s[j];
			}
		}
		if(curr!='?')
		{
			for(int j=i;j<n;j+=k)
			{
				if(s[j]=='?')
				{
					s[j]=curr;
				}
				else{
					if(s[j]!=curr)
					{
						cout<<"NO"<<endl;
						return;
					}
				}
			}
		}
	}
	int cnt0=0,cnt1=0,cntq=0;
	for(int i=0;i<k;i++)
	{
		if(s[i]=='0')
		{
			cnt0++;
		}
		else if(s[i]=='1')
		{
			cnt1++;
		}
		else{
			cntq++;
		}
	}
	if(abs(cnt1-cnt0)>cntq)
	{
		cout<<"NO"<<endl;
		return;
	}
	cout<<"YES"<<endl;

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