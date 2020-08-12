//https://codeforces.com/problemset/problem/1215/D





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
    string s;
    cin>>s;
    bool flag;
    int s1=0, s2=0, g1=0, g2=0;
    for (int i=0;i<n/2;i++)
    {
        if (s[i]=='?')
        {
            g1++;
        }
        else {
            s1+=(s[i]-'0');
        }
    }
    for (int i=n/2;i<n;i++)
    {
        if (s[i]=='?')
        {
            g2++;
        }
        else {
            s2+=(s[i]-'0');
        }
    }
    //cout<<s1<<endl<<s2<<endl<<g1<<endl<<g2<<endl;
    if (s1==s2&&g1==g2)
    {
        flag=true;
    }
    else if (s1==s2||g1==g2)
    {
        flag=false;
    }
    else
    {
        if (((s1<s2)&&(g1>g2))||((s1>s2)&&(g1<g2)))
        {
            if (abs(g1-g2)*9==2*(abs(s1-s2)))
            {
                flag=true;
            }
            else {
                flag=false;
            }
        }
        else {
            flag=false;
        }
    }
    if (flag)
    {
        cout<<"Bicarp"<<endl;
    }
    else {
        cout<<"Monocarp"<<endl;
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