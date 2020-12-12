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

char neg(char a)
{
    if (a == '1')
    {
        return '0';
    }
    else
    {
        return '1';
    }
}

void rev(string &a, int n)
{
    int i = 0;
    int j = n - 1;
    while (i <= j)
    {
        if (i == j)
        {
            a[i] = neg(a[j]);
        }
        else
        {
            char aa = a[i];
            char bb = a[j];
            a[i] = neg(bb);
            a[j] = neg(aa);
        }
        i++;
        j--;
    }
}

void solve()
{
    ll n;
    cin >> n;
    string a, b;
    cin.get();
    getline(cin, a);
    getline(cin, b);
    vector<ll> ans;
    char first = a[0];
    for (int i = 0; i < n; i++)
    {
        int first;
        if (i % 2 == 0)
        {
            first = (a[i / 2] - '0') ^ 0;
        }
        else
        {
            first = (a[n - 1 - (i / 2)] - '0') ^ 1;
        }
        //cout << first << " ";
        if (('0' + first) == b[n - 1 - i])
        {
            ans.push_back(1);
            //rev(a, 1);
            ans.push_back(n - i);
            //rev(a, n - i);
        }
        else
        {
            ans.push_back(n - i);
            //rev(a, n - i);
        }
        //cout << a << " ";
    }
    cout << ans.size() << endl;
    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
}

int main()
{
    fast;
    ll tc = 1;
    IN tc;
    while (tc--)
    {
        solve();
    }
    return 0;
}