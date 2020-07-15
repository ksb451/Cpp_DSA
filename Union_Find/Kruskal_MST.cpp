#include "UNION_FIND.h"
#include <iostream>
#include <vector>
#include <algorithm>
struct EDGE
{
    int src;
    int dest;
    int weight;
    EDGE(int a, int b, int c)
    {
        src = a;
        dest = b;
        weight = c;
    }
};

struct mycompare
{
    bool operator()(EDGE a, EDGE b)
    {
        return a.weight < b.weight;
    }
};

vector<EDGE> kruskal_mst(vector<EDGE> &edges, int n)
{
    SETS set = SETS(n);
    sort(edges.begin(), edges.end(), mycompare());
    vector<EDGE> MST;
    int x = n - 1;
    auto itr = edges.begin();

    while (x && itr != edges.end())
    {
        EDGE next = *itr;
        int x = set.find(next.src);
        int y = set.find(next.dest);
        if (x != y)
        {
            MST.push_back(next);
            set.unify(x, y);
        }
        itr++;
    }
    return MST;
}

int main()
{
    int n;
    cin >> n;
    int e;
    cin >> e;
    vector<EDGE> edges;
    for (int i = 0; i < e; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back(EDGE(a, b, c));
    }
    vector<EDGE> ans = kruskal_mst(edges, n);
    cout << ans.size() << endl;
    for (auto i : ans)
    {
        cout << i.src << "  " << i.dest << "  " << i.weight << endl;
    }
    return 0;
}