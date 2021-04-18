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

void sol(string &a, string &b, char freq, char oth)
{
	ll cnt = 0;
	cnt = count(all(a),freq);
	cnt = min(cnt,(ll)count(all(b),freq));
	ll n = a.length();
	string ans="";
	ll i=0,j=0;
	while((i<n)&&(j<n))
	{	
		if(a[i]==b[j])
		{
			ans+=a[i];
			i++;
			j++;
		}
		else{
			if(a[i]==freq)
			{
				ans+=b[j];
				j++;
			}
			else{
				ans+=a[i];
				i++;
			}
		}
	}
	if(i==n)
	{
		while(j<n)
		{
			ans+=b[j];
			j++;
		}
	}
	if(j==n)
	{
		while(i<n)
		{
			ans+=a[i];
			i++;
		}
	}
	while(ans.length() < ((n/2)*3))
		ans+='0';
	cout<<ans<<endl;
	return;
}	

void solve()
{
	ll n;
    cin>>n;
    vector<string>s(3);
    cin>>s[0]>>s[1]>>s[2];
    ll cnt[3][2]={};
    for(int i=0;i<3;i++)
    {
    	for(int j=0;j<2*n;j++)
    	{
    		cnt[i][s[i][j]-'0']++;
    	}
    }
    if((cnt[0][0]>=n) && (cnt[1][0]>=n))
    {
    	//cout<<1<<endl;
    	sol(s[0],s[1],'0','1');
    }
    else if((cnt[1][0]>=n) && (cnt[2][0]>=n))
    {

    	// cout<<2<<endl;
    	sol(s[2],s[1],'0','1');
    }
    else if((cnt[0][0]>=n) && (cnt[2][0]>=n)){

    	// cout<<3<<endl;
    	sol(s[0],s[2],'0','1');
    }
    else if((cnt[0][1]>=n) && (cnt[1][1]>=n)){

    	// cout<<4<<endl;
    	sol(s[0],s[1],'1','0');
    }
    else if((cnt[2][1]>=n) && (cnt[1][1]>=n)){

    	// cout<<5<<endl;
    	sol(s[2],s[1],'1','0');
    }
    else if((cnt[0][1]>=n) && (cnt[2][1]>=n)){

    	// cout<<6<<endl;
    	sol(s[0],s[2],'1','0');
    }

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