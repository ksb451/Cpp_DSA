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
    cin.get();
    string s, pat;
    cin>>s;
    cin.get();
    cin>>pat;
    //cout<<s<<" "<<pat<<endl;
    int n=s.length();
    int m=pat.length();
    vector<int>char_cnt(26, 0);
    for (auto i:pat)
    {
        char_cnt[i-'a']++;
    }
    bool flag=false;
    for (int i=1;i<m;i++)
    {
        if (pat[i]<pat[0])
        {
            flag=true;
        }
        if (pat[i]>pat[0])
        {
            break;
        }
    }
    string ans="";
    for (auto i :s)
    {
        if (char_cnt[i-'a'])
        {
            char_cnt[i-'a']--;
        }
        else {
            ans+=i;
        }
    }
    sort(ans.begin(), ans.end());
    char a=pat[0];
    int pt;
    if (flag)
    {
        pt=lower_bound(ans.begin(), ans.end(), a)-ans.begin();
    }
    else
        pt=upper_bound(ans.begin(), ans.end(), a)-ans.begin();
    ans.insert(pt, pat);
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