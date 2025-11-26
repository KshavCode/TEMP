#include <bits/stdc++.h>
using namespace std;

// Disjoint Set Union (Union-Find) for Kruskal
struct DSU {
    vector<int> parent, rnk;

    DSU(int n) {
        parent.resize(n);
        rnk.assign(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]); // path compression
    }

    bool unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) 
            return false; // already in same set
        if (rnk[x] < rnk[y]) swap(x, y);
        parent[y] = x;
        if (rnk[x] == rnk[y]) rnk[x]++;
        return true;
    }
};

struct Edge {
    int u, v, w;
};

int main() {
    int n, m;
    cout << "Enter number of vertices and edges: ";
    cin >> n >> m;

    vector<Edge> edges(m);
    cout << "Enter edges as: u v w (0-based vertices)\n";
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    // Sort edges by weight
    sort(edges.begin(), edges.end(), [](const Edge &a, const Edge &b) {
        return a.w < b.w;
    });

    DSU dsu(n);
    long long mst_weight = 0;
    vector<Edge> mst_edges;

    for (const auto &e : edges) {
        if (dsu.unite(e.u, e.v)) {
            mst_weight += e.w;
            mst_edges.push_back(e);
        }
    }

    cout << "\nMinimum Spanning Tree total weight = " << mst_weight << "\n";
    cout << "Edges in MST:\n";
    for (auto &e : mst_edges) {
        cout << e.u << " -- " << e.v << "  (w = " << e.w << ")\n";
    }

    return 0;
}
