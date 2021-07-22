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
//#define endl "\n"
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
const ll mod = (ll)(1LL<<32);
const ll M = 998244353LL;

const int dir8[8][2]={{2,1},{2,-1},{-2,1},{-2,-1},{1,2},{1,-2},{-1,2},{-1,-2}};
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
    vector<vector<unsigned int>>val;
    Matrix(unsigned int n)
    {
        val= vector<vector<unsigned int>>(n,vector<unsigned int>(n,0));
    }
	Matrix operator*(Matrix B)
	{
        unsigned int n = B.val.size();
		Matrix product(n);
		for(unsigned int i=0;i<n;i++)
		{
			for(unsigned int j=0;j<n;j++)
			{
				for(unsigned int k=0;k<n;k++)
				{
					product.val[i][k] += val[i][j]*B.val[j][k];
				}
			}
		}
		return product;
	}
};

void mat_exp(Matrix &iden, Matrix mat, unsigned int n)
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

bool valid(unsigned int i, unsigned int j)
{
	return((i<8)&&(j<8)&&(i>=0)&&(j>=0));
}

void solve()
{
	unsigned int n;
    cin>>n;
    //cout<<"a"<<endl;
    Matrix mat(65);
    for(int i=0;i<8;i++)
    {
		for(int j=0;j<8;j++)
		{
			mat.val[i*8+j][64]=1;
			for(int k=0;k<8;k++)
			{
				unsigned int new_i = i+dir8[k][0];
				unsigned int new_j = j+dir8[k][1];
				if(valid(new_i, new_j))
				{
					mat.val[(new_i*8)+new_j][(i*8)+j]=1;
				}
			}
		}   
    }
    mat.val[64][64]=1;
    Matrix iden(65);
    iden.val[0][0]=1;
    mat_exp(iden, mat, n);
    unsigned int ans=0;
    for(int i=0;i<65;i++)
    {
        for(int j=0;j<65;j++)
        {
            ans+=iden.val[i][j];
        }
    }
    cout<<ans<<endl;
    return;
}

int main()
{
    fast;
    unsigned int tc = 1;
    //IN tc;
    while (tc--)
    {
        solve();
    }
    return 0;
}
