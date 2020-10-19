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

bool cal(int n, int a,int b,int c)
{
	if(n<0)
	{
		return false;
	}
	if(n%3==0)
	{
		cout<<a+n/3<<" "<<b<<" "<<c<<endl;
		return true;
	}
	else if(n%5==0)
	{

		cout<<a<<" "<<b+n/5<<" "<<c<<endl;
		return true;
	}
	else if(n%7==0)
	{

		cout<<a<<" "<<b<<" "<<c+n/7<<endl;
		return true;
	}
	else{
		return false;
	}
}

void solve()
{
	ll n;
    cin>>n;
    for(int i=0;i<3;i++)
    {
    	if(cal(n-i*3, i,0,0))
    	{
    		return;
    	}
    }

    for(int i=0;i<5;i++)
    {
    	if(cal(n-i*5, 0,i,0))
    	{
    		return;
    	}
    }

    for(int i=0;i<7;i++)
    {
    	if(cal(n-i*7, 0,0,i))
    	{
    		return;
    	}
    }
    cout<<-1<<endl;
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