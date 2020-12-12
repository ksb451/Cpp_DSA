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

int min(int a, int b, int c, int d)
{
    return min(a, min(b, min(c, d)));
}

void solve()
{
    int n, m;
    cin>>n>>m;
    vector<string>arr(n);
    read(arr);
    vector<vector<int>>upperleft, upperright, downleft, downright;
    upperleft=upperright=downleft=downright=vector<vi>(n, vi(m, 1));
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
            if (i>0&&j>0)
            {
                if (arr[i][j]==arr[i-1][j]&&arr[i][j]==arr[i][j-1])
                {
                    upperleft[i][j]+=min(upperleft[i-1][j], upperleft[i][j-1]);
                }
            }
        }
    }
    for (int i=0;i<n;i++)
    {
        for (int j=m-1;j>=0;j--)
        {
            if (i>0&&j<m-1)
            {
                if (arr[i][j]==arr[i-1][j]&&arr[i][j]==arr[i][j+1])
                {
                    upperright[i][j]+=min(upperright[i-1][j], upperright[i][j+1]);
                }
            }
        }
    }
    for (int i=n-1;i>=0;i--)
    {
        for (int j=0;j<m;j++)
        {
            if (i<n-1&&j>0)
            {
                if (arr[i][j]==arr[i+1][j]&&arr[i][j]==arr[i][j-1])
                {
                    downleft[i][j]+=min(downleft[i+1][j], downleft[i][j-1]);
                }
            }
        }
    }
    long ans=0L;
    for (int i=n-1;i>=0;i--)
    {
        for (int j=m-1;j>=0;j--)
        {
            if (i<n-1&&j<m-1)
            {
                if (arr[i][j]==arr[i+1][j]&&arr[i][j]==arr[i][j+1])
                {
                    downright[i][j]+=min(downright[i+1][j], downright[i][j+1]);
                }
            }
            ans+=min(upperleft[i][j], upperright[i][j], downright[i][j], downleft[i][j]);
        }
    }
    cout<<ans<<endl;
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