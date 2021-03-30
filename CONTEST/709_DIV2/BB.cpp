#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cout.tie(NULL);                   \
    cin.tie(NULL);

#define IN cin >>
#define OUT cout <<
#define nl "\n"
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

ll cal(int a,int b)
{
	if(a==1)
	{
		return 0;
	}
	return max(0,min(a-1,((b/2)-1)));
}

void print(vector<vector<ll>>a)
{
	for(auto i :a)
	{
		for(auto j:i)
		{
			cout<<j<<" ";
		}
		cout<<endl;
	}
	return;
}

void solve()
{
    ll n,m;
    cin>>n>>m;
    vector<vector<ll>>mat(n,vector<ll>(m));
    for(int i=0;i<n;i++)
    	for(int j=0;j<m;j++)
    		cin>>mat[i][j];
    vector<vector<ll>>U(n,vector<ll>(m));
    vector<vector<ll>>D(n,vector<ll>(m));
    vector<vector<ll>>R(n,vector<ll>(m));
    vector<vector<ll>>L(n,vector<ll>(m));
    for(int i=0;i<n;i++)
    {
    	ll curr=0;
    	for(int j=0;j<m;j++)
    	{
    		if(mat[i][j]==1)
    		{
    			curr++;
    		}
    		else{
    			curr=0;
    		}
    		L[i][j]=curr;
    	}
    }
    for(int i=0;i<n;i++)
    {
    	ll curr=0;
    	for(int j=m-1;j>=0;j--)
    	{
    		if(mat[i][j]==1)
    		{
    			curr++;
    		}
    		else{
    			curr=0;
    		}
    		R[i][j]=curr;
    	}
    }
    for(int j=0;j<m;j++)
    {
    	ll curr=0;
    	for(int i=0;i<n;i++)
    	{
    		if(mat[i][j]==1)
    		{
    			curr++;
    		}
    		else{
    			curr=0;
    		}
    		U[i][j]=curr;
    	}
    }
    for(int j=0;j<m;j++)
    {
    	ll curr=0;
    	for(int i=n-1;i>=0;i--)
    	{
    		if(mat[i][j]==1)
    		{
    			curr++;
    		}
    		else{
    			curr=0;
    		}
    		D[i][j]=curr;
    	}
    }
    // print(U);
    // print(D);
    // print(L);
    // print(R);
    
    ll ans=0;
    //cout<<endl;
    for(int i=0;i<n;i++)
    {
    	for(int j=0;j<m;j++)
    	{
    		//cout<<U[i][j]<<" "<<D[i][j]<<" "<<R[i][j]<<" "<<L[i][j]<<endl;
    		ans+=cal(U[i][j],L[i][j]);
    		ans+=cal(U[i][j],R[i][j]);
    		ans+=cal(D[i][j],L[i][j]);
    		ans+=cal(D[i][j],R[i][j]);
    		ans+=cal(L[i][j],U[i][j]);
    		ans+=cal(L[i][j],D[i][j]);
    		ans+=cal(R[i][j],U[i][j]);
    		ans+=cal(R[i][j],D[i][j]);
    	}
    }
    cout<<ans<<endl;
}


int main()
{
    ios_base::sync_with_stdio(false); 
    cout.tie(NULL);
    cin.tie(NULL);
    ll tc = 1;
    IN tc;
    for (int i = 1; i <= tc; i++)
    {
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}