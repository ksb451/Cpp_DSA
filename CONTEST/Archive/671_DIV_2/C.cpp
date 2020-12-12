//**sn0wrus**//
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cout.tie(NULL);                   \
    cin.tie(NULL);

#define IN cin >>
#define OUT cout <<
#define endl "\n"
#define all(a) (a).begin(), (a).end()
#define pb push_back
using ll = long long int;
using ld = long double;
using pll = pair<ll, ll>;
using pii = pair<int, int>;
using vll = vector<ll>;
using vi = vector<int>;
const ll mod = (ll)(1e9) + 7LL;
const ll M = 998244353LL;

const int dir8[8][2]={{1,0},{0,1},{-1,0},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
const int dir4[4][2]={{1,0},{0,1},{-1,0},{0,-1}};

/*
for(int i=0;i<n-1;i++)
{
    int a,b;
    cin>>a>>b;
    a--,b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
}
*/

void solve()
{
	ll n,x;
    cin>>n>>x;
    vector<ll>arr(n);
    ll inf =0;
    vector<int>inc;
    vector<int>dec;
    for(int i=0;i<n;i++)
    {
    	cin>>arr[i];
    	if(arr[i]==x)
    	{
    		inf++;
    	}
    	else{
    		if(arr[i]>x)
    		{
    			dec.push_back(arr[i]-x);
    		}
    		else{
    			inc.push_back(x-arr[i]);
    		}
    	}
    }
    if(inf==n)
    {
    	cout<<0<<endl;
    	return;
    }
    sort(all(inc));
    sort(all(dec));
    ll inc_sum = accumulate(all(inc),0);
    ll dec_sum = accumulate(all(dec),0);
    cout<<inc_sum<<" "<<dec_sum<<endl;
    if(inc_sum==dec_sum)
    {
    	cout<<1<<endl;
    	return;
    }
    int ans =0;
    if(inc_sum> dec_sum)
    {

    	int i=0;
    	dec_sum+=(inf*(x-4000));
        int new_inf=0;
    	while(true)
    	{
    		if(i==inc.size())
    		{
    			break;
    		}
    		if(dec_sum>=inc[i])
    		{
    			dec_sum-=inc[i];
    			i++;
    			new_inf++;
    		}
    		else{
    			break;
    		}
    	}
    	ans++;
        inf+=new_inf;
        inf+=dec.size();
        new_inf+=dec.size();
        cout<<inf<<endl;
    	while(inf < n)
    	{
    		dec_sum+=new_inf*(x-4000);
            new_inf=0;
            while(true)
            {
                if(i==inc.size())
                {
                    break;
                }
                if(dec_sum>=inc[i])
                {
                    dec_sum-=inc[i];
                    i++;
                    new_inf++;
                }
                else{
                    break;
                }
            }
            ans++;
            inf+=new_inf;
    	}
        cout<<ans<<endl;
        return;
    }
    else
    {
        int i=0;
        inc_sum+=(inf*(4000-x));
        int new_inf=0;
        while(true)
        {
            if(i==dec.size())
            {
                break;
            }
            if(inc_sum>=dec[i])
            {
                inc_sum-=dec[i];
                i++;
                new_inf++;
            }
            else{
                break;
            }
        }
        ans++;
        inf+=new_inf;
        inf+=inc.size();
        new_inf+=inc.size();
        while(inf < n)
        {
            inc_sum+=new_inf*(4000-x);
            new_inf=0;
            while(dec_sum>0)
            {
                if(i==dec.size())
                {
                    break;
                }
                if(inc_sum>=dec[i])
                {
                    inc_sum-=dec[i];
                    i++;
                    new_inf++;
                }
                else{
                    dec[i]-=inc_sum;
                    inc_sum=0;
                }
            }
            ans++;
            inf+=new_inf;
        }
        cout<<ans<<endl;
        return;
    }
}

int main()
{
    fast;
    ll tc = 1;
    IN tc;
    while (tc--)
    {
        solve();
    }
    return 0;
}