#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

void primsAlgorithm(int n, vector<vector<pii>>& adj) {
    vector<int> key(n, INT_MAX); 
    vector<int> parent(n, -1); 
    vector<bool> inMST(n, false); 

    priority_queue<pii, vector<pii>, greater<pii>> pq; 
    key[0] = 0; //start form 0 node
    pq.push({0, 0});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (inMST[u]) 
          continue;
        inMST[u] = true;

      
        for (const auto& [weight, v] : adj[u]) {
            if (!inMST[v] && weight < key[v]) {
                key[v] = weight;
                pq.push({key[v], v});
                parent[v] = u;
            }
        }
    }

    
    cout << "Edges in the Minimum Spanning Tree:\n";
    int mstWeight = 0;
    for (int i = 1; i < n; ++i) {
        if (parent[i] != -1) {
            cout << parent[i] << " -- " << i << " == " << key[i] << "\n";
            mstWeight += key[i];
        }
    }
    cout << "Total weight of the Minimum Spanning Tree: " << mstWeight << "\n";
}

int main() 
{
    int n, m; 
    cout << "Enter the number of vertices and edges: ";
    cin >> n >> m;

    vector<vector<pii>> adj(n); // Adjacency list: adj[u] = {weight, v}
    cout << "Enter the edges (u, v, weight):\n";
    for (int i = 0; i < m; ++i) {
        int u, v, weight;
        cin >> u >> v >> weight;
        adj[u].push_back({weight, v});
        adj[v].push_back({weight, u}); 
    }

    primsAlgorithm(n, adj);

    return 0;
}
