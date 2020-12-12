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
int gcd(int a, int b) 
{ 
    if (b == 0) 
        return a; 
    return gcd(b, a % b);  
      
} 
void solve()
{
	ll n;
    cin>>n;
    vector<int>arr(n);
    vector<bool>done(n,0);
    for(int i=0;i<n;i++)
    {
    	cin>>arr[i];
    }
    vector<int>ans;
    int mx=INT_MIN;
    int mxi;
    for(int i=0;i<n;i++)
    {
    	if(arr[i]>mx)
    	{
    		mxi=i;
    		mx=arr[i];
    	}
    }
    ans.push_back(mx);
    done[mxi]=1;
    int mx_gcd;
    int curr_gcd=mx;
    for(int i=0;i<n-1;i++)
    {
    	mx_gcd=INT_MIN;
    	for(int i=0;i<n;i++){
			if(done[i]==0)
			{
				int curr=gcd(curr_gcd,arr[i]);
				if(curr > mx_gcd)
				{
					mx_gcd=curr;
					mxi=i;
				}
			}
		}
		ans.push_back(arr[mxi]);
		done[mxi]=1;
		curr_gcd=mx_gcd;
    }
    for(auto i:ans)
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