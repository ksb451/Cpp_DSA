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
const ll INF = (ll)3e18+5LL;
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
struct Matrix{
    vector<vector<ll>>val;
    Matrix(ll n)
    {
        val= vector<vector<ll>>(n,vector<ll>(n,INF));
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
					product.val[i][k] =min(product.val[i][k], val[i][j]+B.val[j][k]);
				}
			}
		}
		return product;
	}
};

Matrix mat_exp(Matrix mat, ll k)
{
    ll n=mat.val.size();
    Matrix iden(n);
    for(int i=0;i<n;i++){
        iden.val[i][i]=0;
    }
	while(k>0)
	{
		if(k&1)
		{
			iden = iden*mat;
		}
		k=(k>>1);
		mat = mat * mat;
	}
    return iden;
}

void solve()
{
	ll n,m,k;
    cin>>n>>m>>k;
    Matrix mat(n);
    
    for(int i=0;i<m;i++)
    {
        ll a,b,c;
        cin>>a>>b>>c;
        a--;b--;
        mat.val[b][a]=c;
    }
    Matrix iden = mat_exp(mat, k);
    ll ans=INF;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            ans=min(ans,iden.val[i][j]);
        }
    }
    if(ans >= (2e18))
        cout<<"IMPOSSIBLE"<<endl;
    else
        cout<<ans<<endl;
    return;
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