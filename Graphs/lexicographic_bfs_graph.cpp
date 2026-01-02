#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

/*
    Graph implementation using adjacency list.
    Prepared for lexicographic BFS:
    - Nodes are stored in sorted order using map
    - Adjacency lists are sorted so BFS picks
      the smallest possible node first
*/

class Graph {
private:
    map<int, vector<int>> adj; 
    bool directed;

public:
    // Constructor (default: undirected graph)
    Graph(bool directed = false) {
        this->directed = directed;
    }

    void addNode(int u) {
        if (adj.find(u) == adj.end()) {
            adj[u] = vector<int>();
        }
    }

    void addEdge(int u, int v) {
        addNode(u);
        addNode(v);

        adj[u].push_back(v);
        if (!directed) {
            adj[v].push_back(u);
        }
    }

    // Sort adjacency lists for lexicographic BFS
    void sortAdjacency() {
        for (auto &node : adj) {
            sort(node.second.begin(), node.second.end());
        }
    }

    // Print adjacency list
    void print() const {
        if (adj.empty()) {
            cout << "Graph is empty\n";
            return;
        }

        for (auto &node : adj) {
            cout << node.first << " -> ";
            for (int nbr : node.second) {
                cout << nbr << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Graph g(false);

    int n, e;
    cin >> n >> e;

    for (int i = 0; i < n; i++) {
        g.addNode(i);
    }

    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    cout << "Before sorting:\n";
    g.print();

    // Prepare graph for lexicographic BFS
    g.sortAdjacency();

    cout << "\nAfter sorting (lexicographic-ready):\n";
    g.print();

    return 0;
}

/*
Sample Input:
4 3
0 2
0 1
0 3
*/
