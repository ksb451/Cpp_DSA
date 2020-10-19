#include <bits/stdc++.h> 
using namespace std; 
  
// Function that returns true if s1 
// and s2 are anagrams of each other 
// Function to return the minimum swaps required 

  
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
 
ll CountSteps(string s1, string s2, ll size) 
{ 
    ll i = 0, j = 0; 
    ll result = 0; 
    while (i < size) { 
        j = i; 
        while (s1[j] != s2[i]) { 
            j += 1; 
        } 
        while (i < j) { 
            char temp = s1[j]; 
            s1[j] = s1[j - 1]; 
            s1[j - 1] = temp; 
            j -= 1; 
            result += 1; 
        } 
        i += 1; 
    } 
    return result; 
} 

 void solve()
 {
 	ll n;
    cin>>n;
    string s1;
    cin>>s1;
    string s2=s1;
    reverse(s2.begin(),s2.end());  
    // If both the strings are anagrams 
    // of each other then only they 
    // can be made equal 
    cout << CountSteps(s1, s2, n); 
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