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
int n;
    int dp[301][301][301];
    int dist(char a, char b)
    {
        return abs(((a-'a')/6 )-((b-'a')/6 )) + abs(((a-'a')%6)-((b-'a') %6));
    }
    
    int rec(int i, int l ,int r, string & word)
    {
    	cout<<i<<" "<<l<< " "<<r<<endl;
        if(i > n)
        {
            return 0;
        }
        if((dp[i][l][r] !=-1))
        {
            return dp[i][l][r];
        }
        else{
            int ans = INT_MAX;
            if(l==0)
            {
                ans = min(ans, rec(i+1, i, r,word));
            }
            else{
                ans = min(ans, rec(i+1, i, r,word)+dist(word[i-1], word[l-1]));
            }
            if(r==0)
            {
                ans = min(ans, rec(i+1, l, i,word));
            }
            else{
                ans = min(ans, rec(i+1, l, i,word)+dist(word[i-1], word[r-1]));
            }
            cout<<i<<" "<<l<<" "<<r<<" "<<ans<<endl; 
            return dp[i][l][r]=ans;
        }
    }
    
    int minimumDistance(string word) {
        n = word.length();
        if(n<=2)
        {
            return 0;
        }
        cout<<"done"<<endl;
        memset(dp,-1 ,sizeof(dp));
        return rec(1,0,0,word);
    }

int main()
{
    fast;
    ll tc = 1;
    IN tc;
    while (tc--)
    {
    	string s;
    	cin>>s;
        cout<<minimumDistance(s)<<endl;
    }
    return 0;
}
