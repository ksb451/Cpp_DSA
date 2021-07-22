#include <iostream>

using namespace std;
using ll = long long;
#define N 1000000007
void mul(ll F[2][2], ll M[2][2]) 
{ 
  ll x =  (F[0][0]*M[0][0] + F[0][1]*M[1][0])%N; 
  ll y =  (F[0][0]*M[0][1] + F[0][1]*M[1][1])%N; 
  ll z =  (F[1][0]*M[0][0] + F[1][1]*M[1][0])%N; 
  ll w =  (F[1][0]*M[0][1] + F[1][1]*M[1][1])%N; 
  
  F[0][0] = x; 
  F[0][1] = y; 
  F[1][0] = z; 
  F[1][1] = w; 
} 
ll matmul(ll mat[2][2], ll n, ll m)
{
    ll ans[2][2];
    ans[0][0] = 1;
    ans[0][1] = 0;
    ans[1][0] = 0;
    ans[1][1] = 1;
    while(n > 0)
    {
        if(n%2 == 1)
            mul(ans, mat);
        n = n/2;
        mul(mat, mat);
    }
    ll x = (m*m)%N;
    return (ans[0][0]*x + ans[0][1]*m)%N;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        ll n, m;
        cin >> n >> m;
        m = m%N;
        ll mat[2][2];
        mat[0][0] = m-1;
        mat[0][1] = m-1;
        mat[1][0] = 1;
        mat[1][1] = 0;
        if(n == 1)
            cout << m << '\n';
        else if(n == 2)
            cout << (m*m)%N << '\n';
        else
            cout << (matmul(mat, n-2, m)+N)%N << '\n';
    }
}