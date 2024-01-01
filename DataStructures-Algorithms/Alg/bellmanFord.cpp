#include <iostream>
#include <vector>
#include <climits>

using namespace std;

const int INF = INT_MAX;

void bellmanFord(vector<pair<pair<int, int>, int>>& edges, int V, int src) {
    vector<int> dist(V, INF);
    dist[src] = 0;

    for (int i = 0; i < V - 1; ++i) {
        for (const auto& edge : edges) {
            int u = edge.first.first;
            int v = edge.first.second;
            int weight = edge.second;

            if (dist[u] != INF && dist[v] > dist[u] + weight)
                dist[v] = dist[u] + weight;
        }
    }

    // Check for negative cycles
    for (const auto& edge : edges) {
        int u = edge.first.first;
        int v = edge.first.second;
        int weight = edge.second;

        if (dist[u] != INF && dist[v] > dist[u] + weight) {
            cout << "Graph contains negative cycle!";
            return;
        }
    }

    // Output distances
    cout << "Vertex   Distance from Source\n";
    for (int i = 0; i < V; ++i)
        cout << i << "\t\t" << dist[i] << "\n";
}

int main() {
    int V = 5;
    vector<pair<pair<int, int>, int>> edges = {
        {{0, 1}, 2},
        {{0, 2}, 4},
        {{1, 2}, 1},
        {{1, 3}, 7},
        {{2, 4}, 3},
        {{3, 4}, 2}
    };

    bellmanFord(edges, V, 0);

    return 0;
}
