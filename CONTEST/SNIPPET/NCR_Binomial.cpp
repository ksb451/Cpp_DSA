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
using ll = long long int;
using ld = long double;
using pll = pair<ll, ll>;
using pii = pair<int, int>;
using vll = vector<ll>;
using vi = vector<int>;
const ll mod = (ll)(1e9) + 7LL;
const ll M = 998244353LL;


//NCR using Bnomial in O(1) with preprossessing
const ll N = 100005LL;

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


//ncr using DP
ll nCrModp(ll n, ll r) 
{  
    if (r > n - r) 
        r = n - r; 
    ll C[r + 1]; 
    memset(C, 0, sizeof(C)); 
    C[0] = 1;
    for (ll i = 1; i <= n; i++) { 
        for (ll j = min(i, r); j > 0; j--) 
            C[j] = (C[j] + C[j - 1]) % M; 
    } 
    return C[r]; 
} 


//NCR using fermet theorem
unsigned long long power(unsigned long long x, int y, int p) 
{ 
    unsigned long long res = 1;
    x = x % p;
    while (y > 0) { 
        if (y & 1) 
            res = (res * x) % p; 
        y = y >> 1;
        x = (x * x) % p; 
    } 
    return res; 
} 
  
unsigned long long modInverse(unsigned long long n, int p) 
{ 
    return power(n, p - 2, p); 
} 

unsigned long long nCrModPFermat(unsigned long long n, int r, int p) 
{ 
    if (r == 0) 
        return 1; 
    unsigned long long fac[n + 1]; 
    fac[0] = 1; 
    for (int i = 1; i <= n; i++) 
        fac[i] = (fac[i - 1] * i) % p; 
    return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) % p; 
} 


void solve()
{
	ll n,r;
    cin>>n>>r;
    cout<<Binomial(n,r)<<endl;
    cout<<nCrModp(n,r)<<endl;
    cout<<nCrModPFermat(n,r,M)%M;
    cout<<endl;
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