#include <bits/stdc++.h>
using namespace std;


struct Edge {
    int u, v, weight;
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};


class DSU {
private:
    vector<int> parent, rank;
public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    // Find the root of a node with path compression
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    // Union by rank
    void unite(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY)
        {
            if (rank[rootX] > rank[rootY])
             {
                parent[rootY] = rootX;
            }
            else if (rank[rootX] < rank[rootY])
            {
                parent[rootX] = rootY;
            }
            else
            {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
};


int kruskal(int n, vector<Edge>& edges) {

    sort(edges.begin(), edges.end());
    DSU dsu(n);
    int mstWeight = 0;

    cout << "Edges in the Minimum Spanning Tree:\n";
    for (const auto& edge : edges) {
        if (dsu.find(edge.u) != dsu.find(edge.v))
        {
            dsu.unite(edge.u, edge.v);
            mstWeight += edge.weight;
            cout << edge.u << " -- " << edge.v << " == " << edge.weight << "\n";
        }
    }

    return mstWeight;
}

int main()
{
    int n, m;
    cout << "Enter the number of nodes and edges: ";
    cin >> n >> m;

    vector<Edge> edges(m);
    cout << "Enter the edges (u, v, weight):\n";
    for (int i = 0; i < m; ++i) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    }

    int mstWeight = kruskal(n, edges);
    cout << "Total weight of the Minimum Spanning Tree: " << mstWeight << "\n";

    return 0;
}

/*

5 7
0 1 2
0 3 6
1 2 3
1 3 8
1 4 5
2 4 7
3 4 9

*/

