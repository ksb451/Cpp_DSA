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
long long binpow(long long a, long long b, long long m=mod) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

struct Matrix{
    vector<vector<ll>>val;
    Matrix(ll n)
    {
        val= vector<vector<ll>>(n,vector<ll>(n,0));
    }
	Matrix operator*(Matrix B)
	{
        ll n = B.val.size();
		Matrix product(n);
		for(ll i=0;i<n;i++)
		{
			for(ll j=0;j<n;j++)
			{
				for(ll k=0;k<n;k++)
				{
					product.val[i][k] += val[i][j]*B.val[j][k];
					product.val[i][k]%=mod;
				}
			}
		}
		return product;
	}
};

void mat_exp(Matrix &iden, Matrix mat, ll n)
{
	while(n>0)
	{
		if(n&1)
		{
			iden = iden*mat;
		}
		n=(n>>1);
		mat = mat*mat;
	}
}


void solve()
{
// 	ll n,m;
//     cin>>n>>m;
    
//     ll ans=0;
//     while(n)
//     {
//     	ll x=m;
//     	ll curr = n%10;
//     	n/=10;
//     	x-=(10-curr);
//     }
	ll n,m;
	cin>>n>>m;
	Matrix mat(10);
	Matrix iden(10);
	for(int i=0;i<10;i++)
	{
		iden.val[i][i]=1;
	}
	for(int i=0;i<10;i++)
	{	
		mat.val[(i-1+10)%10][i]=1;
		if(i==1)
		{
			mat.val[9][1]=1;
		}
	}
	// for(int i=0;i<10;i++)
	// {
	// 	for(int j=0;j<10;j++)
	// 	{
	// 		cout<<mat.val[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }
	mat_exp(iden, mat, m);
	ll ans=0;
	// for(int i=0;i<10;i++)
	// {
	// 	for(int j=0;j<10;j++)
	// 	{
	// 		cout<<iden.val[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }
	// cout<<endl<<endl;
	while(n)
	{
		ll x = n%10;
		n/=10;
		for(int i=0;i<10;i++)
		{
			ans+=iden.val[x][i];
			ans%=mod;
		}
	}
	cout<<ans<<endl;
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