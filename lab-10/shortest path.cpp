#include <iostream>
#include <vector>
#include <limits>
using namespace std;

const double INF = numeric_limits<double>::infinity(); // Infinity for unreachable paths

// Function implementing the algorithm
void ShortestPaths(int v, const vector<vector<double>>& cost, vector<double>& dist, int n) {
    vector<bool> S(n, false); // To keep track of vertices included in S

    // Initialize distances and S
    for (int i = 0; i < n; ++i) {
        dist[i] = cost[v][i];
        S[i] = false;
    }

    S[v] = true;  // Add source vertex to S
    dist[v] = 0.0;

    // Find shortest paths for n - 1 vertices
    for (int num = 1; num < n; ++num) {
        int u = -1;
        double minDist = INF;

        // Choose u such that dist[u] is minimum among those not in S
        for (int i = 0; i < n; ++i) {
            if (!S[i] && dist[i] < minDist) {
                minDist = dist[i];
                u = i;
            }
        }

        if (u == -1) break; // If no valid vertex is found, exit

        S[u] = true; // Include u in S

        // Update distances for vertices adjacent to u
        for (int w = 0; w < n; ++w) {
            if (!S[w] && cost[u][w] < INF) {
                if (dist[w] > dist[u] + cost[u][w]) {
                    dist[w] = dist[u] + cost[u][w];
                }
            }
        }
    }
}

int main() {
    int n, v;
    cout << "Enter the number of vertices in the graph: ";
    cin >> n;

    // Initialize cost adjacency matrix
    vector<vector<double>> cost(n, vector<double>(n, INF));

    cout << "Enter the cost adjacency matrix (use a large number for INF):\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> cost[i][j];
        }
    }

    cout << "Enter the source vertex (0-based index): ";
    cin >> v;

    vector<double> dist(n, INF); // Distance array to store shortest distances

    // Call the ShortestPaths algorithm
    ShortestPaths(v, cost, dist, n);

    // Print the results
    cout << "Shortest distances from vertex " << v << ":\n";
    for (int i = 0; i < n; ++i) {
        cout << "Vertex " << i << ": ";
        if (dist[i] == INF)
            cout << "INF\n";
        else
            cout << dist[i] << "\n";
    }

    return 0;
}
