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
    cin>>n;
    vi arr(n);
    vi ans(32, 0);
    for (int i=0;i<n;i++)
    {
        cin>>arr[i];
        for (int j=0;j<31;j++)
        {
            if (arr[i]&(1<<j))
            {
                ans[31-j]++;
            }
        }
    }
    for (int i=0;i<32;i++)
    {
        if (ans[i]&1)
        {
            if (ans[i]%4==3&&((n-ans[i])%2==0))
            {
                cout<<"LOSE"<<endl;
                return;
            }
            else {
                cout<<"WIN"<<endl;
                return;
            }
        }
    }
    cout<<"DRAW"<<endl;
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