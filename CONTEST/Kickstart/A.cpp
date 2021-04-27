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


void completesec(ll &a,ll &b, ll &c)
{
	ll sec_nan = 1000000000;
    ll sec = 720 *sec_nan;
    ll min = 12*sec_nan;
    ll hr = sec_nan;
	ll com = 360*12*sec_nan*10;

	ll aa = a;
	ll bb = b;
	ll cc = c;
	while((((bb-cc+com)%com)%(com/60)) !=0)
	{
		cc= (cc-sec+com)%com;
		bb= (bb-min+com)%com;
		aa= (aa-hr+com)%com;
	}
	while((((aa-bb+com)%com)%(com/60)) !=0)
	{
		cc=(cc-sec*60+com)%com;
		bb= (bb-min*60+com)%com;
		aa= (aa-hr*60+com)%com;
	}
	ll hr_ans = ((aa-bb+com)%com)/(com/12);
	if(aa!=a)
	{
		hr_ans--;
	}
	cout<<hr_ans<<endl;
}

void solve()
{
    ll a,b,c;
    cin>>a>>b>>c;
    completesec(a,b,c);
    return;
    
}

int main()
{
    ios_base::sync_with_stdio(false); 
    cout.tie(NULL);
    cin.tie(NULL);
    ll tc = 1;
    IN tc;
    for (int i = 1; i <= tc; i++)
    {
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}