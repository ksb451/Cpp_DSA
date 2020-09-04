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
const int MAX = 501; 
int dp[MAX][MAX];
int minimumSquare(int m, int n) 
{ 
    // Initializing max values to vertical_min  
    // and horizontal_min 
    int vertical_min = INT_MAX; 
    int horizontal_min = INT_MAX; 
      
    // If the given rectangle is already a square 
    if (m == n) 
        return 1; 
      
    // If the answer for the given rectangle is  
    // previously calculated return that answer 
    if (dp[m][n]) 
            return dp[m][n]; 
      
    /* The rectangle is cut horizontally and  
       vertically into two parts and the cut  
       with minimum value is found for every  
       recursive call.  
    */
      
    for (int i = 1;i<= m/2;i++) 
    { 
        // Calculating the minimum answer for the  
        // rectangles with width equal to n and length  
        // less than m for finding the cut point for  
        // the minimum answer 
        horizontal_min = min(minimumSquare(i, n) +  
                minimumSquare(m-i, n), horizontal_min);  
    } 
      
    for (int j = 1;j<= n/2;j++) 
    { 
        // Calculating the minimum answer for the  
        // rectangles with width less than n and  
        // length equal to m for finding the cut  
        // point for the minimum answer 
        vertical_min = min(minimumSquare(m, j) +  
                minimumSquare(m, n-j), vertical_min); 
    } 
          
    // Minimum of the vertical cut or horizontal  
    // cut to form a square is the answer 
    dp[m][n] = min(vertical_min, horizontal_min);  
          
    return dp[m][n]; 
}
void solve()
{
	ll n,m;
    cin>>n>>m;
    cout<<minimumSquare(m,n)-1<<endl;
}

int main()
{
    ll tc = 1;
    //IN tc;
    while (tc--)
    {
        solve();
    }
    return 0;
}