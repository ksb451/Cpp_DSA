#include <bits/stdc++.h>
#include <algorithm>
#include <stdio.h>
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
    scanf("%d", &n);
    string s;
    cin >> s;
    int a = 0;
    for (auto i : s)
    {
        if (i == 'A')
            a++;
        else
            a--;
    }
    printf(abs(a) == 1 ? "Y" : "N");
    puts("");
}

int main()
{
    ll tc = 1;
    IN tc;
    for (int i = 1; i <= tc; i++)
    {
        printf("Case #%d:", i);
        //puts("");
        solve();
    }
    return 0;
}