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
	ll n,x;
    cin>>n>>x;
    vector<ll>arr(n);
    ll inf =0;
    vector<int>inc;
    vector<int>dec;
    for(int i=0;i<n;i++)
    {
    	cin>>arr[i];
    	if(arr[i]==x)
    	{
    		inf++;
    	}
    	else{
    		if(arr[i]>x)
    		{
    			dec.push_back(arr[i]-x);
    		}
    		else{
    			inc.push_back(x-arr[i]);
    		}
    	}
    }
    if(inf==n)
    {
    	cout<<0<<endl;
    	return;
    }
    sort(all(inc));
    sort(all(dec));
    ll inc_sum = accumulate(all(inc),0);
    ll dec_sum = accumulate(all(dec),0);
    if(inc_sum==dec_sum)
    {
    	cout<<1<<endl;
    	return;
    }
    int ans =0;
    if(inc_sum> dec_sum)
    {
    	int i=0;
    	dec_sum+=(inf*(x-4000));
    	while(dec_sum>0)
    	{
    		if(i==inc.size())
    		{
    			break;
    		}
    		if(dec_sum>=inc[i])
    		{
    			dec_sum-=inc[i];
    			i++;
    			inf++;
    		}
    		else{
    			inc[i]-=dec_sum;
    			dec_sum=0;
    		}
    	}
    	ans++;
    	while(inf<n)
    	{
    		ll left = inf*()
    	}
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