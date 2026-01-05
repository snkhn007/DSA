// Single Source Shortest Path in Unweighted Graph (BFS)

/*
        0
      /   \
     1     2
      \   /
        3
        |
        4
*/

#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

void addNode(int u, unordered_map<int, vector<int>> &adj) {
    if (adj.find(u) == adj.end())
        adj[u] = vector<int>();
}

void addEdge(int u, int v, unordered_map<int, vector<int>> &adj) {
    addNode(u, adj);
    addNode(v, adj);
    adj[u].push_back(v);
    adj[v].push_back(u);
}

/*
 EDITED:
 - BFS is now meant to be called ONLY from the source node
 - It returns parent map for shortest paths from src
*/
unordered_map<int, int> bfs(int src, unordered_map<int, bool> &vis, unordered_map<int, vector<int>> &adj) {
    unordered_map<int, int> parent;

    queue<int> q;
    q.push(src);
    vis[src] = true;
    parent[src] = -1;   // source has no parent

    while (!q.empty()) {
        int temp = q.front();
        q.pop();

        for (auto i : adj[temp]) {
            if (!vis[i]) {
                vis[i] = true;
                parent[i] = temp;
                q.push(i);
            }
        }
    }
    return parent;
}

int main() {
    int n = 5;
    unordered_map<int, vector<int>> adj;

    for (int i = 0; i < n; i++) addNode(i, adj);

    addEdge(0, 1, adj);
    addEdge(0, 2, adj);
    addEdge(1, 3, adj);
    addEdge(2, 3, adj);
    addEdge(3, 4, adj);

    int start = 0, end = 4;

    unordered_map<int, bool> vis;

    /*
     - BFS must run ONLY from start
     - Running BFS from all nodes breaks shortest path logic
    */
    unordered_map<int, int> parent = bfs(start, vis, adj);

    /*
     - Check if destination is reachable
     - Prevents infinite loop / crash
    */
    if (parent.find(end) == parent.end()) {
        cout << "No path exists\n";
        return 0;
    }

    vector<int> path;
    int curr = end;

    while (curr != start) {
        path.push_back(curr);
        curr = parent[curr];
    }
    path.push_back(start);

    reverse(path.begin(), path.end());

    cout << "Shortest path: ";
    for (int node : path)
        cout << node << " ";

    return 0;
}
