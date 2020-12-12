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

const int N=5e5+1;
int a[4][N];
int dp3[N][8];
int dp2[N][4];
int ok3[8][8];
int ok2[4][4];
int n, m;
void fill3() {
    for (int i = 0;i < 8;i++) {
        for (int j = 0;j < 8;j++) {
            bool bad = 0;
            for (int st = 0;st < 2;st++) {
                int bits = (bool)(i&(1<<st))+(bool)(i&(1<<(st+1)));
                bits += (bool)(j&(1<<st))+(bool)(j&(1<<(st+1)));
                if (bits%2 == 0) {
                    bad = 1;
                }
            }
            if (!bad) {
                ok3[i][j] = 1;
            }
        }
    }
}
void fill2() {
    for (int i = 0;i < 4;i++) {
        for (int j = 0;j < 4;j++) {
            bool bad = 0;
            for (int st = 0;st < 1;st++) {
                int bits = (bool)(i&(1<<st))+(bool)(i&(1<<(st+1)));
                bits += (bool)(j&(1<<st))+(bool)(j&(1<<(st+1)));
                if (bits%2 == 0) {
                    bad = 1;
                }
            }
            if (!bad) {
                ok2[i][j] = 1;
            }
        }
    }
}

void solve2() {
    for (int i = 1;i <= m;i++) {
        int mask = a[1][i]+2*a[2][i];
        for (int cur = 0;cur < 4;cur++) {
            dp2[i][cur] = 1e9;
            for (int prev = 0;prev < 4;prev++) {
                if (!ok2[prev][cur])continue;
                dp2[i][cur] = min(dp2[i][cur], dp2[i-1][prev]+__builtin_popcount(cur^mask));
            }
        }
    }
    int ans = 1e9;
    for (int i = 0;i < 4;i++)ans = min(ans, dp2[m][i]);
    cout << ans;
}
void solve3() {
    for (int i=1;i<=m;i++)
    {
        int mask=a[1][i]+2*a[2][i]+4*a[3][i];
        for (int cur=0;cur<8;cur++)
        {
            dp3[i][cur]=1e9;
            for (int prev=0;prev<8;prev++) {
                if (!ok3[prev][cur])continue;
                dp3[i][cur]=min(dp3[i][cur], dp3[i-1][prev]+ __builtin_popcount(cur^mask));
            }
        }
    }
    int ans=1e9;
    for (int i=0;i<8;i++)ans=min(ans, dp3[m][i]);
    cout<<ans;

}
void solve()
{
    cin>>n>>m;
    if (min(m, n)==1)
    {
        cout<<0<<endl;
        return;
    }
    else if (min(m, n)>3)
    {
        cout<<-1<<endl;
        return;
    }
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++) {
            char o;
            cin>>o;
            a[i][j]=o-'0';
        }
    }
    if (n==3)solve3();
    else solve2();
}

int main()
{
    //fast;
    ll tc = 1;
    //IN tc;
    while (tc--)
    {
        fill2();
        fill3();
        solve();
    }
    return 0;
}