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

bool ispos(set<pair<int, int>, greater<pair<int, int>>>&st)
{
    if (st.size()==1)
    {
        int f=st.begin()->first;
        if (f>=8)
        {
            return true;
        }
    }
    else if (st.size()==2)
    {
        int f=st.begin()->first;
        int s=next(st.begin())->first;
        if ((f>=8)||(f>=4&&s>=4)||(f>=6&&s>=2))
        {
            return true;
        }
    }
    else {
        int f=st.begin()->first;
        int s=next(st.begin())->first;
        int t=next(next(st.begin()))->first;
        if ((f>=8)||(f>=4&&s>=4)||(f>=6&&s>=2)||(f>=4&&s>=2&&t>=2))
        {
            return true;
        }
    }
    return false;
}

void solve()
{
    int n;
    cin>>n;
    unordered_map<int, int>um;
    for (int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        um[x]++;
    }
    set<pair<int, int>, greater<pair<int, int>>>st;
    for (auto i: um)
    {
        st.insert({ i.second, i.first });
    }
    // for (auto i:st)
    // {
    //     cout<<i.first<<" "<<i.second<<endl;
    // }
    int q;
    cin>>q;
    while (q--)
    {
        cin.get();
        char c;
        int x;
        cin>>c>>x;
        st.erase({ um[x], x });
        if (c=='+')
        {
            um[x]++;
        }
        else {
            um[x]--;
        }
        st.insert({ um[x], x });
        // for (auto i:st)
        // {
        //     cout<<i.first<<" "<<i.second<<endl;
        // }
        if (ispos(st))
        {
            cout<<"YES"<<endl;
        }
        else {
            cout<<"NO"<<endl;
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