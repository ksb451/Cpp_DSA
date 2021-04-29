


## Graph-Theory

### MST

- A minimum spanning tree of a graph is unique, if the weight of all the edges are distinct. Otherwise, there may be multiple minimum spanning trees. (Specific algorithms typically output one of the possible minimum spanning trees).
- Minimum spanning tree is also the tree with minimum product of weights of edges. (It can be easily proved by replacing the weights of all edges with their logarithms)
- In a minimum spanning tree of a graph, the maximum weight of an edge is the minimum possible from all possible spanning trees of that graph. (This follows from the validity of Kruskal's algorithm).
- The maximum spanning tree (spanning tree with the sum of weights of edges being maximum) of a graph can be obtained similarly to that of the minimum spanning tree, by changing the signs of the weights of all the edges to their opposite and then applying any of the minimum spanning tree algorithm.

#### KRUSKAL

O(1) amortized time complexity per query and join operation using DSU.

total time complexity of M log N as we have to sort the array of edges according to their weight.

```c++
vector<int> parent, rank;

void make_set(int v) {
    parent[v] = v;
    rank[v] = 0;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (rank[a] < rank[b])
            swap(a, b);
        parent[b] = a;
        if (rank[a] == rank[b])
            rank[a]++;
    }
}

struct Edge {
    int u, v, weight;
    bool operator<(Edge const& other) {
        return weight < other.weight;
    }
};

int n;
vector<Edge> edges;

int cost = 0;
vector<Edge> result;
parent.resize(n);
rank.resize(n);
for (int i = 0; i < n; i++)
    make_set(i);

sort(edges.begin(), edges.end());

for (Edge e : edges) {
    if (find_set(e.u) != find_set(e.v)) {
        cost += e.weight;
        result.push_back(e);
        union_sets(e.u, e.v);
    }
}
```



#### PRIMS





## DSU
```c++
class DSU
{
    ll N;
    ll total_components;
    vector<ll> sz;
    vector<ll> parent;

public:
    DSU(ll n)
    {
        no_of_elements = n;
        total_components = n;
        sz = vector<ll>(n, 0);
        for (ll i = 0; i < n; i++)
        {
            parent.push_back(i);
        }
    }
    
    ll find_set(ll x) // path compression
    {
        if(x == parent[x])
        {
            return x;
        }
        return parent[x] = find_set(parent[x]);
    }

    ll component_size(int x)
    {
        return sz[find(x)];
    }
    
    ll size()
    {
        return N;
    }
    
    ll components()
    {
        return total_components;
    }
    
    void unify(ll p, ll q)// attach the lower size to the higher size
    {
        ll a = find(p);
        ll b = find(q);
        if (a != b)
        {
            if(sz[a]<sz[b])
                swap(a,b);
            parent[b] = a;
            sz[a]+=sz[b];
            total_components--;
        }
    }
};
```
## Segment Trees

> ```c++
> ll t[MAXN*4];//4 time s the size of array
> ll combine (ll a,ll b)//combine funciton to combine two children
> {
> 	return a+b;
> }
> 
> void build(vll &arr, ll v, ll tl , ll tr)//build function
> {
> 	if(tl == tr)
> 	{
> 		t[v] = arr[tl];
> 	}
> 	else{
> 		ll tm = (tl+tr)/2;
> 		build(arr, v*2,tl,tm);
> 		build(arr,v*2+1,tm+1, tr);
> 		t[v] = combine(t[v*2] , t[v*2+1]);
> 	}
> }
> 
> ll query(ll v, ll tl, ll tr, ll l, ll r)
> {
> 	if(l>r)
> 	{
> 		return 0;//default value depends on the combine function
> 	}
> 	if(l == tl && r==tr)
> 	{
> 		return t[v];
> 	}
> 	else{
> 		ll tm = (tl+tr)/2;
> 		return combine(query(v*2, tl, tm , l ,min(r,tm)), query(v*2+1, tm+1, tr, max(l, tm+1), r));//query sent down to the children nodes take precautions with the min and max.
> 	}
> }
> 
> void update(ll v, ll tl, ll tr, ll pos, ll new_val)
> {
> 	if(tl == tr)
> 	{
> 		t[v] = new_val;
> 	}
> 	else{
> 		ll tm = (tl+tr)/2;
> 		if(pos<=tm)//update the node
> 		{
> 			update(v*2, tl, tm, pos, new_val);
> 		}
> 		else{
> 			update(v*2+1, tm+1, tr, pos, new_val);
> 		}
> 		t[v] = combine(t[v*2] , t[v*2+1]);//update the upper tree
> 	}
> }
> ```



## Segment Tree DP



## RANDOM TECHNIQUES

### Venice Technique

https://codeforces.com/blog/entry/58316

https://codeforces.com/problemset/problem/893/D

https://codeforces.com/problemset/problem/923/B	

Suppose we have to do 4 types of operation

1. Add a number to set
2. Delete a number form set
3. Remove some amount from all the numbers
4. find the min element

1 2 4 can be handled easily using a set. but 3 is costly. So as in Venice

keep a global variable water_level.

when performing operation 3 just increase water_level by that amount. and all add operation(1) after that can be done with amount +waterlevel.

```c++
struct VeniceSet {
	multiset<int> S;
	int water_level = 0;
	void add(int v) {
		S.insert(v + water_level);
	}
	void remove(int v) {
		S.erase(S.find(v + water_level));
	}
	void updateAll(int v) {
		water_level += v;
	}
	int getMin() {
		return *S.begin() - water_level;
	}
	int size() {
		return S.size();
	}
};
```



## PROBLEMS()

https://codeforces.com/contest/1396/problem/D

https://codeforces.com/problemset/problem/1508/C

https://codeforces.com/contest/1485/problem/F //Venice technique

https://codeforces.com/contest/842/problem/D // Venice trie



