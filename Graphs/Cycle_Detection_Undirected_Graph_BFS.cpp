#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
using namespace std;

/*
    Cycle Detection in Undirected Graph using BFS
    Time Complexity: O(V + E)
    Space Complexity: O(V)
*/

class Graph {
    unordered_map<int, vector<int>> adj;

public:
    void addNode(int u) {
        if (adj.find(u) == adj.end())
            adj[u] = vector<int>();
    }

    void addEdge(int u, int v) {
        if (u == v) return; // ignore self-loops (optional)
        addNode(u);
        addNode(v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool bfs(int src, unordered_map<int, bool> &vis) {
        queue<int> q;
        unordered_map<int, int> parent; //inside function

        q.push(src);
        vis[src] = true;
        parent[src] = -1;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int nbr : adj[node]) {
                if (!vis[nbr]) {
                    vis[nbr] = true;
                    parent[nbr] = node;
                    q.push(nbr);
                }
                else if (nbr != parent[node]) {
                    return true; // cycle detected
                }
            }
        }
        return false;
    }
};

int main() {
    int n, e;
    cin >> n >> e;

    Graph g;
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    unordered_map<int, bool> vis;
    bool cycle = false;

    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            if (g.bfs(i, vis)) {
                cycle = true;
                break;
            }
        }
    }

    cout << "Cycle " << (cycle ? "detected" : "not detected");
}
