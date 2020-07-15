//union find
#ifndef UNION_FIND_H
#define UNION_FIND_H
#include <iostream>
#include <vector>
using namespace std;

class SETS
{
    int no_of_elements;
    int total_components;
    vector<int> sz;
    vector<int> parent;

public:
    SETS(int n)
    {
        no_of_elements = n;
        total_components = n;
        sz = vector<int>(n, 1);
        for (int i = 0; i < n; i++)
        {
            parent.push_back(i);
        }
    }
    int find(int x)
    {
        int root = x;
        while (parent[root] != root)
        {
            root = parent[root];
        }
        while (x != root)
        {
            int next = parent[x];
            parent[x] = root;
            x = next;
        }
        return root;
    }

    bool is_connected(int x, int y)
    {
        return find(x) == find(y);
    }

    int component_size(int x)
    {
        return sz[find(x)];
    }

    int size()
    {
        return no_of_elements;
    }

    int components()
    {
        return total_components;
    }

    void unify(int p, int q)
    {
        int root1 = find(p);
        int root2 = find(q);
        if (root1 == root2)
            return;
        if (sz[root1] < sz[root2])
        {
            sz[root2] += sz[root1];
            parent[root1] = root2;
        }
        else
        {
            sz[root1] += sz[root2];
            parent[root2] = root1;
        }
        total_components--;
    }
};
#endif