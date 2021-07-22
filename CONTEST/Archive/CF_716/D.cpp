//**sn0wrus**//
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cout.tie(NULL);                   \
    cin.tie(NULL);
#define write(a)          \
    for (auto x : a)      \
    {                     \
        cout << x << " "; \
    }                     \
    cout << endl;
#define read(a)       \
    for (auto &x : a) \
    {                 \
        cin >> x;     \
    }
#define IN cin >>
#define OUT cout <<
#define endl "\n"
#define all(a) (a).begin(), (a).end()
#define allr(a) (a).rbegin(), (a).rend()
#define pb push_back
#define fi first;
#define se second;

using ll = long long int;
using ld = long double;
using pll = pair<ll, ll>;   
using pii = pair<int, int>;
using plll  = pair<ll,pll>;
using vll = vector<ll>;
using vi = vector<int>;
const ll mod = (ll)(1e9) + 7LL;
const ll M = 998244353LL;

const int dir8[8][2]={{1,0},{0,1},{-1,0},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
const int dir4[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
const int MAXA = 300001;
const int MAXN = 300001;
const int MAXQ = 300001;
 

int a[MAXN];
typedef tuple<int, int, int, int> Query;
Query query[MAXQ];
 
inline void moAlgorithm(const int n, const int a[], const int q, tuple<int, int, int, int> query[])
{
	const int blockSize = (int)sqrt((long double)n);
 
	const auto getLeft = [](const Query &q) {return get<0>(q); };
	const auto getRight = [](const Query &q) {return get<1>(q); };
	const auto getBlockIndex = [=](const Query &q) {return getLeft(q) / blockSize; };
 
	sort(query, query + q, [=](const Query &a, const Query &b) {
		return
			getBlockIndex(a) < getBlockIndex(b) ||
			getBlockIndex(a) == getBlockIndex(b) && getRight(a) > getRight(b);
	});
 
	static int count[MAXA + 1];
	memset(count, 0, sizeof(count));
	static int numberOfValuesWithCount[MAXN + 1];
	memset(numberOfValuesWithCount, 0, sizeof(*numberOfValuesWithCount) * (n + 1));
	int maxCount = 0;
 
	const auto remove = [&](const int index) {
		--numberOfValuesWithCount[count[a[index]]];
		if (count[a[index]] == maxCount && numberOfValuesWithCount[count[a[index]]] == 0)
		{
			--maxCount;
		}
		--count[a[index]];
		++numberOfValuesWithCount[count[a[index]]];
 
	};
	const auto add = [&](const int index) {
		--numberOfValuesWithCount[count[a[index]]];
		if (count[a[index]] == maxCount)
		{
			++maxCount;
		}
		++count[a[index]];
		++numberOfValuesWithCount[count[a[index]]];
	};
 
	int left = 0, right = -1;
 
	for (int i = 0; i < q; ++i)
	{
		for (; left < getLeft(query[i]); ++left)
		{
			remove(left);
		}
		for (; left > getLeft(query[i]); )
		{
			add(--left);
		}
		for (; right < getRight(query[i]); )
		{
			add(++right);
		}
		for (; right > getRight(query[i]); --right)
		{
			remove(right);
		}
		get<3>(query[i]) = maxCount;
	}
 
	sort(query, query + q, [=](const Query &a, const Query &b) {
		return get<2>(a) < get<2>(b);
	});
}
 
int solve(int a, int b)
{
	if(b <= ((a+1)/2))
		return 1;
	else{
		return (2*b- a);
	}
}

int main()
{
	int n, q;
	scanf("%d%d", &n, &q);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &a[i]);
	}
	for (int k = 0; k < q; ++k)
	{
		int l,r;
		scanf("%d%d", &l, &r);
			get<0>(query[k]) = l-1;
			get<1>(query[k]) = r-1;
			get<2>(query[k]) = k;
	}

	moAlgorithm(n, a, q, query);

	for (int k = 0; k < q; ++k)
	{
		cout<<solve(get<1>(query[k])-get<0>(query[k])+1, get<3>(query[k]))<<endl;
		//printf("%d %d %d\n",get<0>(query[k]),get<1>(query[k]), get<3>(query[k]));
	}
	return 0;
}