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
	ll n,a,b;
    cin>>n>>a>>b;
    vector<ll>arr;
    arr.push_back(a);
    arr.push_back(b);
    ll middle=0;
    ll gap;
    for(int i=n-1;i>0;i--)
    {
    	if((b-a)%i==0)
    	{
    		middle=i-1;
    		gap=(b-a)/i;
    		break;
    	}
    }
    for(int i=1;i<=middle;i++)
    {
    	arr.push_back(a+(gap*i));
    }
    ll rem=n-arr.size();
    while(rem>0)
    {
    	a-=gap;
    	if(a>0)
    	{
    		arr.push_back(a);
    		rem--;
    	}
    	else{
    		break;
    	}
    }
    while(rem>0)
    {
    	b+=gap;
    	arr.push_back(b);
    	rem--;
    }
    for(auto i:arr)
    {
    	cout<<i<<" ";
    }
    cout<<endl;
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