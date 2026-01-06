#include <iostream>
#include <unordered_map>
#include <vector>
#include <utility>
#include <climits>
#include <queue>

using namespace std;

/*
    Weighted Graph using Adjacency List

    - Supports directed and undirected graphs
    - Nodes are created implicitly when edges are added
    - Handles disconnected components
    - Dijkstra's Algorithm for shortest paths
    - NOTE: Works only for NON-negative edge weights
*/

class Graph {
    // Adjacency list: node -> list of (neighbor, weight)
    unordered_map<int, vector<pair<int, int>>> adj;
    bool directed;

public:
    Graph(bool directed = false) {
        this->directed = directed;
    }
    void addNode(int u) {
        if (adj.find(u) == adj.end()) {
            adj[u] = vector<pair<int, int>>();
        }
    }
    void addEdge(int u, int v, int w) {
        addNode(u);
        addNode(v);

        adj[u].push_back({v, w});
        if (!directed) {
            adj[v].push_back({u, w});
        }
    }

    /*
        Dijkstra's Algorithm
        Returns shortest distance from src to all reachable nodes

    */
    unordered_map<int, int> dijkstra(int src) {
        unordered_map<int, int> dist;

        // Initialize distances to infinity
        for (const auto &i : adj) {
            dist[i.first] = INT_MAX;
        }

        // Distance to source is zero
        dist[src] = 0;

        // Min-heap priority queue: (distance, node)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        pq.push({0, src});

        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();

            int currDist = curr.first;
            int currNode = curr.second;

            // Ignore outdated entries
            if (currDist > dist[currNode]) continue;

            for (const auto &i : adj[currNode]) {
                int nextNode = i.first;
                int weight = i.second;

                if (currDist + weight < dist[nextNode]) {
                    dist[nextNode] = currDist + weight;
                    pq.push({dist[nextNode], nextNode});
                }
            }
        }

        return dist;
    }
};

int main() {
    Graph g(false);

    g.addEdge(0, 1, 4);
    g.addEdge(0, 2, 1);
    g.addEdge(2, 1, 2);
    g.addEdge(1, 3, 5);
    g.addEdge(3, 4, 3);

    // Run Dijkstra from source node 0
    unordered_map<int, int> shortestDistances = g.dijkstra(0);

    // Print shortest distances
    for (const auto &i : shortestDistances) {
        cout << "Node " << i.first << " -> Distance: " << i.second << endl;
    }

    return 0;
}
