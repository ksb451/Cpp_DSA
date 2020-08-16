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

int find(string &s)
{
    int n = s.length();
    int max = 0;
    int start = 0;
    int curr = 0;
    int curr_start = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
        {
            curr++;
            if (curr > max)
            {
                max = curr;
                start = curr_start;
            }
        }
        else
        {
            curr_start = i + 1;
            curr = 0;
        }
    }
    s.erase(start, max);
    return max;
}

void solve()
{
    string s;
    cin >> s;
    //cout << s << endl;
    int ans = 0;
    while (1)
    {
        int temp = find(s);
        ans += temp;
        temp = find(s);
        if (temp == 0)
        {
            break;
        }
    }
    cout << ans << endl;
}

int main()
{
    ll tc = 1;
    IN tc;
    while (tc--)
    {
        solve();
    }
    return 0;
}