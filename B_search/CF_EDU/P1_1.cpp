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
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    read(arr);
    //write(arr);
    while (k--)
    {
        int x;
        cin >> x;
        //cout << x << endl;
        int l = 0;
        int r = n - 1;
        bool ok = false;
        while (r >= l)
        {
            int mid = l + (r - l) / 2;
            //cout << mid << " ";
            if (arr[mid] == x)
            {
                ok = true;
                //cout<<"YES"<<endl;
                break;
            }
            else if (arr[mid] > x)
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        if (ok)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}

int main()
{
    ll tc = 1;
    //IN tc;
    while (tc--)
    {
        solve();
    }
    return 0;
}