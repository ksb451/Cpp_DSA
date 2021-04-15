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
ll x;
int solve(int op, int cop, int siz, int n){
		cout<<x<<endl;
		x++;
        if(siz == n){
            return op;
        }
        if(siz > n)
            return INT_MAX;
        
        int a = solve(op+1, cop, siz+cop, n);
        int b = solve(op+2, siz+cop, siz+cop, n);
        
        return min(a, b);
        
    }
    int minSteps(int n) {
        int cop = 1, siz = 1, op = 1;
        if(n == 1)
            return 0;
        return solve(op, cop, siz, n);
    }

int main()
{
    fast;
    ll tc = 1;
    IN tc;
    x=0;
    cout<<minSteps(tc)<<endl;;
    return 0;
}