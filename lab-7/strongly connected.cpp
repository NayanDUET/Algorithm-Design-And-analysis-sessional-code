#include <bits/stdc++.h>
using namespace std;

int n, tt;
vector<string> color;
vector<int> pi, d, f;
unordered_set<int> cycle;

void DFS(vector<vector<int>>& graph, int u) {
    color[u] = "g";
    tt++;
    d[u] = tt;

    for (int v : graph[u]) {
        if (color[v] == "w") {
            pi[v] = u;
            DFS(graph, v);
        } else if (color[v] == "g") {
            int node = u;
            while (node != v) {
                cycle.insert(node);
                node = pi[node];
            }
            cycle.insert(v);
        }
    }

    color[u] = "b";
    tt++;
    f[u] = tt;
}

int main() {
    int edge, u, v;
    cin >> n >> edge;
    vector<vector<int>> graph(n);

    color.assign(n, "w");
    d.assign(n, 0);
    f.assign(n, 0);
    pi.assign(n, -1);

    for (int i = 0; i < edge; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
    }

    tt = 0;

    for (int i = 0; i < n; i++) {
        if (color[i] == "w") DFS(graph, i);
    }

    for (auto a : cycle) {
        cout << a << " ";
    }
    cout << endl;

    return 0;
}
