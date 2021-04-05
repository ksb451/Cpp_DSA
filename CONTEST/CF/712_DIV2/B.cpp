//**sn0wrus**//
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cout.tie(NULL);                   \
    cin.tie(NULL);
#define write(a)          \
    for (auto x : a)      \
    {                     \
        cout << x << " "; \
    }                     \
    cout << endl;
#define read(a)       \
    for (auto &x : a) \
    {                 \
        cin >> x;     \
    }
#define IN cin >>
#define OUT cout <<
#define endl "\n"
#define all(a) (a).begin(), (a).end()
#define allr(a) (a).rbegin(), (a).rend()
#define pb push_back
#define fi first;
#define se second;

using ll = long long int;
using ld = long double;
using pll = pair<ll, ll>;   
using pii = pair<int, int>;
using plll  = pair<ll,pll>;
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
    cin>>n;
    string a,b;
    cin>>a>>b;
	vector<vector<int>>cnt(n,{0,0});
	for(int i=0;i<n;i++)
	{
		if(a[i]=='0')
		{
			cnt[i][0]++;
		}
		else{
			cnt[i][1]++;
		}
		if(i>0)
		{
			cnt[i][0]+=cnt[i-1][0];
			cnt[i][1]+=cnt[i-1][1];
		}
	}
	if(n&1)
	{
		if(a[n-1]!=b[n-1])
		{
			cout<<"NO"<<endl;
			return;
		}
		n--;
	}
	int chk=1;
	for(int i=n-1;i>=0;i-=2)
	{
		if((a[i] != b[i]) && (a[i-1]!=b[i-1]))
		{
			if(chk==1)
			{
    			//cout<<i<<"  1"<<endl;
    			if(cnt[i][0]!=cnt[i][1])
    			{
    				cout<<"NO"<<endl;
    				return;
    			}
    			chk=0;
			}
			else{
				continue;
			}
		}
		else if((a[i]==b[i]) && (a[i-1]==b[i-1]))
		{
			if(chk==0)
			{
    			//cout<<i<<"  1"<<endl;
    			if(cnt[i][0]!=cnt[i][1])
    			{
    				cout<<"NO"<<endl;
    				return;
    			}
    			chk=1;
			}
			else{
				continue;
			}
		}
		else if((a[i]!=b[i]) ^ (a[i-1]!=b[i-1]))
		{
			//cout<<i<<" 2"<<endl;
			cout<<"NO"<<endl;
			return;
		}
	}
	cout<<"YES"<<endl;
    return;
}

int main()
{
    fast;
    ll tc = 1;
    IN tc;
    while (tc--)
    {
        solve();
    }
    return 0;
}