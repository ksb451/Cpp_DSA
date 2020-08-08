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
    ll n, k;
    cin>>n>>k;
    ll l1, r1, l2, r2;
    cin>>l1>>r1>>l2>>r2;
    ll ans=LLONG_MAX;
    ll insec=min(r1, r2)-max(l1, l2);
    //cout<<insec<<endl;
    if (insec>=0)
    {
        ll rem=max(0LL, k-n*(insec));
        ll max_pos=n*(abs(l1 - l2) + abs(r1 - r2));
        ans = min(rem, max_pos) + max(0LL, rem - max_pos) * 2;
    }
    else {
        ll invest=abs(insec);
        for (int i=1;i<=n;i++)
        {
            ll curr=invest*i;
            ll max_pos=(max(r1, r2)-min(l1, l2))*i;
            curr+=min(k, max_pos)+max(0LL, k-max_pos)*2;
            ans=min(curr, ans);
        }
    }
    cout<<ans<<endl;
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