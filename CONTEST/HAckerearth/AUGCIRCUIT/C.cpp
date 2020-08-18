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
using ull = unsigned long long int;
using ll = long long int;
using ld = long double;
using pll = pair<ll, ll>;
using pii = pair<int, int>;
using vll = vector<ll>;
using vi = vector<int>;
const ll mod = (ll)(1e9) + 7LL;
const ll M = 988244353LL;

ull power_2_ceil(ull k)
{
    ull count = 0;
    ull q = k;
    while (k)
    {
        count++;
        k = k >> 1;
    }
    if (!(q & (q - 1)))
        return count - 1;
    return count;
}

void print(vector<vector<ull>> &G)
{
    ull n = G.size();
    ull m = 0;
    for (ull i = 0; i < n; i++)
    {
        for (ull j = 0; j < n; j++)
        {
            if (G[i][j] && j > i)
            {
                m++;
            }
        }
    }
    cout << n << " " << m << endl;
    for (ull i = 0; i < n; i++)
    {
        for (ull j = 0; j < n; j++)
        {
            if (G[i][j] && j > i)
            {
                cout << i + 1 << " " << j + 1 << endl;
            }
        }
    }
}

void solve()
{
    ull k;
    cin >> k;
    if (k == 1)
    {
        cout << "2 1" << endl;
        cout << "1 2" << endl;
        return;
    }
    ull n = power_2_ceil(k);
    //cout << "count " << n << endl;
    //ull mx = (1LL << n);
    //cout << "max " << mx << endl;
    ull diff = (1LL << n) - k;
    //cout << "diff " << diff << endl;
    vector<vector<ull>> G(n + 2, vector<ull>(n + 2, 1LL));
    if (diff == 0LL)
    {
        print(G);
    }
    else
    {
        ull ind = 1LL;
        while (diff)
        {
            if (diff & 1)
            {
                G[ind][n + 1] = 0;
            }
            diff = diff >> 1;
            ind++;
        }
        print(G);
    }
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