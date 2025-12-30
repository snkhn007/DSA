#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

/*
    Graph class using adjacency list.
    - Supports directed and undirected graphs
    - Handles isolated nodes
    - Safe against misuse (edges before nodes)
*/
class Graph {
private:
    // Adjacency list: node -> list of neighbors
    unordered_map<int, list<int>> adj;

    // true  = directed graph
    // false = undirected graph
    bool directed;

public:
    // Constructor
    // Default graph is undirected
    Graph(bool directed = false) {
        this->directed = directed;
    }

    /*
        Ensures that a node exists in the graph.
        If the node is already present, nothing happens.
        This allows isolated nodes (nodes with no edges).
    */
    void addNode(int u) {
        if (adj.find(u) == adj.end()) {
            adj[u] = list<int>();  // create empty neighbor list
        }
    }

    /*
        Adds an edge between u and v.
        - Automatically ensures both nodes exist
        - Works even if addNode() was never called explicitly
    */
    void addEdge(int u, int v) {
        // Ensure nodes exist (robust design)
        addNode(u);
        addNode(v);

        // Add edge u -> v
        adj[u].push_back(v);

        // If graph is undirected, also add v -> u
        if (!directed) {
            adj[v].push_back(u);
        }
    }

    /*
        Prints the adjacency list of the graph.
    */
    void print() {
        if (adj.empty()) {
            cout << "Graph is empty\n";
            return;
        }

        for (auto &node : adj) {
            cout << node.first << " -> ";
            for (int neighbour : node.second) {
                cout << neighbour << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    // Create an undirected graph
    // Use true for directed graph
    Graph g(false);

    int n, e;
    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> e;

    /*
        Create all nodes beforehand.
        This ensures isolated nodes are present in the graph.
        Example: nodes with no edges will still appear.
    */
    for (int i = 0; i < n; i++) {
        g.addNode(i);
    }

    cout << "Enter edges (u v):\n";
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    cout << "\nAdjacency List:\n";
    g.print();

    return 0;
}

// 5
// 4
// 0 1
// 1 2
// 2 3
// 3 4

