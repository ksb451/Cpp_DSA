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

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<string> mat;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        mat.push_back(s);
    }
    vector<vector<int>> arr(n + 1, vector<int>(m + 1, 0));
    int q;
    cin >> q;
    while (q--)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a--, b--, c--, d--;
        arr[a][b]++;
        arr[a][d + 1]--;
        arr[c + 1][b]--;
        arr[c + 1][d + 1]++;
    }
    //cout << endl;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 && j == 0)
            {
            }
            else if (i == 0)
            {
                arr[i][j] += arr[i][j - 1];
            }
            else if (j == 0)
            {
                arr[i][j] += arr[i - 1][j];
            }
            else
            {
                arr[i][j] += (arr[i][j - 1] + arr[i - 1][j] - arr[i - 1][j - 1]);
            }
            //cout << arr[i][j] << " ";
        }
        //cout << endl;
    }
    //cout << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] & 1)
            {
                if (mat[i][j] == '0')
                    mat[i][j] = '1';
                else
                {
                    mat[i][j] = '0';
                }
            }
        }
        cout << mat[i] << endl;
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