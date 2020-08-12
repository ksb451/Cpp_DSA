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
    cin>>n>>k;
    vector<int>arr(n);
    for (int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    unordered_map<int, int>mp;
    mp.clear();
    int unique=0;
    int cost=0;
    int curr_q_cost=0;
    if (k==1)
    {
        int cost=1;
        for (int i=0;i<n;i++)
        {
            if (mp[arr[i]])
            {
                cost++;
                mp.clear();
            }
            mp[arr[i]]=1;
        }
        cout<<cost<<endl;
        return;
    }
    for (int i=0;i<n;i++)
    {
        if (unique==k)
        {
            if (mp.find(arr[i])==mp.end())
            {
                mp[arr[i]]=1;
                unique++;
            }
            else {
                if (mp[arr[i]]==1)
                {
                    cost+=k;
                    cost+=curr_q_cost;
                    mp.clear();
                    unique=0;
                    curr_q_cost=0;
                    mp[arr[i]]=1;
                    unique=1;
                }
                else {
                    mp[arr[i]]++;
                    curr_q_cost++;
                }
            }
        }
        else {
            if (mp.find(arr[i])==mp.end())
            {
                mp[arr[i]]=1;
                unique++;
            }
            else {
                if (mp[arr[i]]==1)
                {
                    mp[arr[i]]++;
                    unique--;
                    curr_q_cost+=2;
                }
                else {
                    mp[arr[i]]++;
                    curr_q_cost++;
                }
            }
        }
    }
    cost+=k;
    cost+=curr_q_cost;
    cout<<cost<<endl;
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