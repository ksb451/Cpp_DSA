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
using ll = unsigned long long int;
using ld = long double;
using pll = pair<ll, ll>;
using pii = pair<int, int>;
using vll = vector<ll>;
using vi = vector<int>;
const ll mod = (ll)(1e9) + 7LL;
const ll M = 988244353LL;

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

ll power(ll x, ll y) 
{ 
    if (y == 0) 
        return 1; 
    else if (y % 2 == 0) 
        return power(x, y / 2) * power(x, y / 2); 
    else
        return x * power(x, y / 2) * power(x, y / 2); 
}

void solve()
{
	ll n;
    cin>>n;
    vector<ll>arr(n);
    read(arr);
    sort(all(arr));
    double x=pow((double)(arr[n-1]),(1.0/(double)(n-1)));
    ll st=floor(x+0.5);
    ll ans=LLONG_MAX;
    ll c=floor(pow(10.0,17.0/(double)(n-1)));
    for(ll i=1;i<=min(st+2,c);i++)
    {	
    	ll sum=0;
    	for(ll j=0;j<n;j++)
    	{
    		sum+=abs(arr[j]-pow(i,j));
    	}
    	ans=min(ans,sum);
    }
    cout<<ans<<endl;
}

int main()
{
    ll tc = 1;
    //IN tc;
    while (tc--)
    {
        solve();
    }
    return 0;
}