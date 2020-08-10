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
unordered_map<char, int>um;
void fill() {
    int i=0;
    for (char j='0';j<='9';j++)
    {
        um[j]=i;
        i++;
    }
    for (char j='A';j<='Z';j++)
    {
        um[j]=i;
        i++;
    }
    for (char j='a';j<='z';j++)
    {
        um[j]=i;
        i++;
    }
    um['-']=i;
    i++;
    um['_']=i;
    //cout<<i;
}

int power3[7]={ 1, 3, 9, 27, 81, 243, 729 };

int count0(int x)
{
    int ans=0;
    for (int i=0;i<6;i++)
    {
        if (!(x&1))
        {
            ans++;
        }
        x>>=1;
    }
    return ans;
}

void solve()
{
    string s;
    cin>>s;
    ll ans=1;
    for (int i=0;i<s.length();i++)
    {
        int x=um[s[i]];
        //cout<<x<<endl;
        int a=count0(x);
        //cout<<a<<endl;
        ans*=power3[a];
        ans%=mod;
    }
    cout<<ans;
}

int main()
{
    ll tc = 1;
    //IN tc;
    while (tc--)
    {
        fill();
        solve();
    }
    return 0;
}