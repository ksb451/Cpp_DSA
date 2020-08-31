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

vector<ll>S(26);
vector<ll>score;
vector<ll>curr(26);

const int N = 100001; 
ll factorialNumInverse[N + 1];
ll naturalNumInverse[N + 1]; 
ll fact[N + 1]; 
void InverseofNumber() 
{ 
	naturalNumInverse[0] = naturalNumInverse[1] = 1LL; 
	for (ll i = 2LL; i <= N; i++) 
		naturalNumInverse[i] = (naturalNumInverse[M % i] * (M - M / i)) % M; 
} 
void InverseofFactorial() 
{ 
	factorialNumInverse[0] = factorialNumInverse[1] = 1LL; 
	for (ll i = 2LL; i <= N; i++) 
		factorialNumInverse[i] = (naturalNumInverse[i] * factorialNumInverse[i - 1]) % M; 
} 
void factorial() 
{ 
	fact[0] = 1LL; 
	for (ll i = 1; i <= N; i++) { 
		fact[i] = (fact[i - 1] * i) % M; 
	} 
} 
ll Binomial(ll N, ll R) 
{
	ll ans = (((fact[N] * factorialNumInverse[R]) % M )* factorialNumInverse[N - R]) % M; 
	return ans; 
}


ll nCrModp(ll n, ll r) 
{
	if(r>n)
	{
		return 0LL;
	} 
    // Optimization for the cases when r is large 
    if (r > n - r) 
        r = n - r; 
  
    // The array C is going to store last row of 
    // pascal triangle at the end. And last entry 
    // of last row is nCr 
    ll C[r + 1]; 
    memset(C, 0, sizeof(C)); 
  
    C[0] = 1; // Top row of Pascal Triangle 
  
    // One by constructs remaining rows of Pascal 
    // Triangle from top to bottom 
    for (ll i = 1; i <= n; i++) { 
  
        // Fill entries of current row using previous 
        // row values 
        for (ll j = min(i, r); j > 0; j--) 
  
            // nCj = (n-1)Cj + (n-1)C(j-1); 
            C[j] = (C[j] + C[j - 1]) % M; 
    } 
    return C[r]; 
}


ll rec(string &s)
{
	curr=std::vector<ll>(26,0);
	ll ans=1;
	for(auto i:s)
	{
		curr[i-'a']++;
	}
	// for(ll q:curr)
	// {
	// 	cout<<q<<" ";
	// }
	// cout<<endl;
	// for(ll q:S)
	// {
	// 	cout<<q<<" ";
	// }
	// cout<<endl<<endl;
	
	for(int i=0;i<26;i++)
	{
		ans*=Binomial(S[i],curr[i]);
		//cout<<ans<<" ";
		ans%=M;
	}
	//cout<<endl;
	return ans;
}


void solve()
{
	string s;
    cin>>s;
    int n;
   	cin>>n;
   	S=vector<ll>(26,0);
   	for(auto i:s)
   	{
   		S[i-'a']++;
   	}
    vector<string>arr(n);
    score=vector<ll>(n,0);
    for(int i=0;i<n;i++)
    {
    	cin>>arr[i];
    	score[i]=rec(arr[i]);
    }
    string ans;
    ll mx=INT_MIN;
    for(int i=0;i<n;i++)
    {
    	cout<<score[i]<<endl;
    	if(score[i]>mx)
    	{
    		mx=score[i];
    		ans=arr[i];
    	}
    }
    if(mx==0)
    {
    	cout<<"No Research This Month"<<endl;
    	return;
    }
    cout<<ans<<endl;
}


int main()
{
	InverseofNumber(); 
	InverseofFactorial(); 
	factorial();
    ll tc = 1;
    IN tc;
    while (tc--)
    {
        solve();
    }
    return 0;
}