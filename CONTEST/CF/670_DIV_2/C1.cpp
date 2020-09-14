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
vector<int> cent(const vector<int> g[], int n) {
        
        vector<int> c;
        vector<int> size(n+1);
        function<void (int, int)> dfsit = [&](int u, int p) {
                size[u] = 1;
                int flag = 1;
                for (auto v : g[u])
					if (v != p) {
                        dfsit(v, u);
                        size[u] += size[v];
                        if (size[v] > n / 2) 
							flag = 0;
                	}
                if (n - size[u] > n / 2)
					flag = 0;
                if (flag == 1) 
					c.push_back(u);
        };
        dfsit(1, -1);
        return c;
}

void solve()
{
    ll n, x, y;
        cin>>n;
        vector<int> g[n+1];
        for(int i=0;i<n-1;i++){
            cin>>x>>y;
            g[x].pb(y);
            g[y].pb(x);
        }
        vector<int> c = cent(g, n);
        cout<<c.size()<<endl;
        // if (c.size() == 1) {
        //     int c1 = c[0];
        //     // cout<<c1<<endl;
        //     cout<<c1<<" "<<g[c1][0]<<endl;
        //     cout<<c1<<" "<<g[c1][0]<<endl;
        // } 
        // else if (c.size() == 2) {
        //     int c1 = c[0];
        //     int c2 = c[1];
        //     // cout<<c1<<" "<<c2<<endl;
        //     for(int i=0; i<g[c1].size(); i++){
        //         if(g[c1][i] != c2){
        //             cout<<c1<<" "<<g[c1][i]<<endl;
        //             x = g[c1][i];
        //             break;
        //         }
        //     }
        //     cout<<c2<<" "<<x<<endl;
        // }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int tc = 1;
    cin>>tc;
    while(tc--){
        solve();
	}

    return 0;
}