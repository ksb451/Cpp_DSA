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
    int n;
    string s;
    cin >> n >> s;
    vector<int> ans(n);
    vector<int> pos0, pos1;
    for (int i = 0; i < n; ++i) {
        int newpos = pos0.size() + pos1.size();
        if (s[i] == '0') {
            if (pos1.empty()) {
                pos0.push_back(newpos);
            }
            else {
                newpos = pos1.back();
                pos1.pop_back();
                pos0.push_back(newpos);
            }
        }
        else {
            if (pos0.empty()) {
                pos1.push_back(newpos);
            }
            else {
                newpos = pos0.back();
                pos0.pop_back();
                pos1.push_back(newpos);
            }
        }
        ans[i] = newpos;
    }
    cout << pos0.size() + pos1.size() << endl;
    for (auto it : ans) cout << it + 1 << " ";
    cout << endl;
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