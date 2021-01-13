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
#define endl "\n"
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

int find(int i)
{
	if(i==1)
	{
		return 1;
	}
	int ans=1;
	while(i!=1)
	{
		if(i&1)
		{
			i=(3*i+1);
			ans++;
		}
		else{
			i/=2;
			ans++;
		}
	}
	return ans;
}
void solve()
{
	int a,b;
    while(cin>>a>>b)
    {
    	int x=min(a,b);
    	int y=max(a,b);
    	int mx=0;
    	for(int i =x;i<=y;i++)
    	{
    		mx=max(mx,find(i));
    	}
    	cout<<a<<" "<<b<<" "<<mx<<endl;
    }
    return;
}

int main()
{
    solve();
    return 0;
}