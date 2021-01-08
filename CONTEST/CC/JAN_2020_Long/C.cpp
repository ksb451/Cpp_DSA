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
	ll n1,n2,n3;
    cin>>n1>>n2>>n3;
    vector<ll>a1(n1);
    vector<ll>a2(n2);
    vector<ll>a3(n3);
    ll sum1=0,sum2=0,sum3=0;
    ll min1=INT_MAX,min2=INT_MAX,min3=INT_MAX;
    for(int i=0;i<n1;i++)
    {
    	cin>>a1[i];
    	min1 = min(a1[i],min1);
    	sum1+=a1[i];
    }
    for(int i=0;i<n2;i++)
    {
    	cin>>a2[i];
    	min2 = min(a2[i],min2);
    	sum2+=a2[i];
    }
    for(int i=0;i<n3;i++)
    {
    	cin>>a3[i];
    	min3 = min(a3[i],min3);
    	sum3+=a3[i];
    }
    ll summin=min(min1+min2, min(min2+min3,min3+min1));
    summin =min(min(min(summin,sum1),sum2),sum3);
    cout<<sum1+sum2+sum3-summin*2<<endl;
}

int main()
{
    fast;
    ll tc = 1;
    //IN tc;
    while (tc--)
    {
        solve();
    }
    return 0;
}