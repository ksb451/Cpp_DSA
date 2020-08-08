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


int findzzl(int mxi, int mxj, string &s)
{
    int tot=mxi+mxj;
    int i=0;
    int n=s.length();
    int ans=0;
    int curr=mxi;
    while (i<n)
    {
        if (s[i]-'0'==curr)
        {
            ans++;
            curr=abs(curr-tot);
        }
        i++;
    }
    if (mxi!=mxj)
        if (ans%2==1)
            ans--;
    return ans;
}

void solve()
{
    string s;
    cin.get();
    cin>>s;
    int n =s.length();
    vector<int>arr(10, 0);
    for (int i=0;i<n;i++)
    {
        arr[s[i]-'0']++;
    }
    int ans=INT_MAX;
    for (int i=0;i<10;i++)
    {
        for (int j=0;j<10;j++)
        {
            ans=min(ans, n-findzzl(i, j, s));
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