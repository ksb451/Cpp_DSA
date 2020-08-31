#include <algorithm>
#include <iostream>
#include <climits>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <set>
#include <map>

using namespace std;

#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define ll long long
#define mod 1000000007
#define vi vector<int>
#define vll vector<ll>
#define pb push_back

ll power(int x, unsigned int y){
    ll res = 1;
    while(y > 0){
        if(y & 1) res = res * x;
        y >>= 1;
        x *= x;
    }
    return res;
}

/* Iterative Function to calculate (x^y)%p  
in O(log y) */
unsigned long long power(unsigned long long x, 
                         int y, int p) 
{ 
    unsigned long long res = 1; // Initialize result 
  
    x = x % p; // Update x if it is more than or 
    // equal to p 
  
    while (y > 0) { 
        // If y is odd, multiply x with result 
        if (y & 1) 
            res = (res * x) % p; 
  
        // y must be even now 
        y = y >> 1; // y = y/2 
        x = (x * x) % p; 
    } 
    return res; 
} 
  
// Returns n^(-1) mod p 
unsigned long long modInverse(unsigned long long n, int p) 
{ 
    return power(n, p - 2, p); 
} 
  
// Returns nCr % p using Fermat's little 
// theorem. 
unsigned long long nCrModPFermat(unsigned long long n, 
                                 int r, int p) 
{ 
    // Base case 
    if (r == 0) 
        return 1; 
  
    // Fill factorial array so that we 
    // can find all factorial of r, n 
    // and n-r 
    unsigned long long fac[n + 1]; 
    fac[0] = 1; 
    for (int i = 1; i <= n; i++) 
        fac[i] = (fac[i - 1] * i) % p; 
  
    return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) % p; 
} 
 

// Check for number of Cases!!
void solve() {
    string str; cin >> str;
    map<char, ll> mp;

    for(char ch : str) {
        mp[ch]++;
    }
    ll q; cin >> q;

    string maxAns = ""; 
    ll maxCount = 0;

    while(q--) {
        string name;
        cin >> name;
        
        ll arr[26] = {0};
        fill_n(arr, 26, 0);

        for(char ch : name) {
            arr[ch - 'a']++;
        }

        ll ans = 1;
        bool started = false;
        for(int i = 0; i < 26; i++) {
            char ch = char(i + 'a');
            if(!arr[i]) continue;
            if(mp[ch] >= arr[i]) {
                
                ans = (ans * nCrModPFermat(mp[ch], arr[i], 998244353) )  % 998244353; 

                // if(mp[ch] != arr[i])
                    // ans = (ans * mp[ch]) % 998244353;
            }else ans *= 0;
        }
        cout << ans << '\n';

        if(maxCount < ans) {
            maxCount = ans;
            maxAns = name;
        }
    }

    if(maxCount > 0) {
        cout << maxAns;
    }else cout << "No Research This Month";
    cout << '\n';
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("/ATOMCODES/input.txt", "r", stdin);
    freopen("/ATOMCODES/output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    cin >> t;
    while(t--) {
    solve();
    }
}