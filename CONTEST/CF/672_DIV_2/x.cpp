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
	int mod = 10007;
	int n,k;
    cin>>n>>k;
    vector<int>white1 = {k,0,0,0};
    vector<int>black1 = {k,0,0};
    vector<int>white2(4),black2(3);
    for(int i=0;i<n;i++)
    {
    	white2[0] = (white1[0]*2 + white1[1]*3)%mod;
    	white2[1] = (white1[0])%mod;
    	white2[2] = (white1[1])%mod;
    	white2[3]+= white1[2];
    	white2[3]%=mod;
    	black2[0] = (black1[0]*3)%mod;
    	black2[1] = (black1[0])%mod;
    	black2[2]+= black1[1];
    	black2[2]%=mod;
    	black1 = black2;
    	white1 = white2;
    	cout<< white1[0]<<" "<<white1[1]<<" "<<white1[2]<<" "<<white1[3]<<" "<<black1[0]<<" "<<black1[1]<<" "<<black1[2]<<endl;
    }
    cout<< abs((white1[0]+white1[1]+white1[2])-(black1[0]+black1[1]-black1[2]))%mod<<endl;
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