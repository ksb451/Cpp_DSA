// Swamp Thing feels a disturbance in the Green.It seems that Anton Arcane has once again taken over the Rot and is spreading its evil all over the world.A lot of the world's capital cities are feeling the power of the Rot right now. It is Swamp Thing's duty to preserve a balance between the forces of the Green and the Rot.He must travel to each of the cities affected by the Rot as soon as possible.Luckily, he can use the Green's help to travel to cities through special bidirectional roads. However using the Green to travel from one city to another requires a certain amount of energy. Swamp Thing can only expend a certain amount of energy while travelling.

// Swamp Thing wants to travel to all of the world's cities in such an order that the sum of the distances he travels is minimized while the total energy he spends travelling through the Green remains under the maximum energy he can spend.

// If such a order of cities does not exist print "-1", else print the minimum distance required to be travelled by Swamp Thing.

// Note that Swamp Thing always starts from his swamp whose index is 1 in the input.

// INPUT:

// Each input file with a line containing three integers, n - the number of cities, m - the number of roads between cities through the Green and E - the amount of energy Swamp Thing can spend.

// Then m lines follow, each describing a road.Each road is described in the following format:

// u v d e - this represents a bidirectional road from u to v having a distance of d and energy spent will be e.

// OUTPUT:

//     Print the minimum distance required to be traveled by Swamp Thing to visit all cities while spending energy <= E.If no such possible path exists, print -1.

//     CONSTRAINTS:

//     1 <= n <= 14

//     1 <= m <= n * (n - 1) / 2

//     1 <= E <= 100

//     1 <= dist between cities <= 100000

//     SAMPLE INPUT
//     3 3 25
//     1 2 4 20
//     2 3 1 20
//     1 3 10 5
//     SAMPLE OUTPUT
//     11


//problem link
//https://www.hackerearth.com/practice/algorithms/dynamic-programming/bit-masking/practice-problems/algorithm/fifth-1/description/

#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;

int dp[15][100][1 << 15];
int n;

struct edge {
    int u, v, w, energy;
    edge(int a, int b, int c, int d) {
        u = a, v = b, w = c, energy = d;
    }
};

vector<edge> graph[20];

int solve(int u, int mask, int energy) {
    if (mask == ((1 << n) - 1))
        return energy >= 0 ? 0 : inf;
    if (energy <= 0)
        return inf;
    int& ret = dp[u][energy][mask];
    if (ret != -1) return ret;

    ret = inf;
    for (edge e: graph[u]) {
        int v = e.v, w = e.w, req_energy = e.energy;
        if (mask & (1 << v))
            continue;
        else
            ret = min(ret, solve(v, mask | (1 << v), energy - req_energy) + w);
    }
    return ret;
}

int main(void) {
    int  m, energy;
    memset(dp, -1, sizeof(dp));
    scanf("%d %d %d", &n, &m, &energy);
    for (int i = 0; i < m; i++) {
        int u, v, w, en;
        scanf("%d %d %d %d", &u, &v, &w, &en);
        u--; v--;
        graph[u].push_back(edge(u, v, w, en));
        graph[v].push_back(edge(v, u, w, en));
    }
    int ans = solve(0, 1, energy);
    printf("%d\n", ans >= inf ? -1 : ans);
    return 0;
}