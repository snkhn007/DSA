#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
#include <vector>
using namespace std;
class Graph {
private:
    unordered_map<int, list<int>> adj;
    bool directed;

public:
    Graph(bool directed = false) {
        this->directed = directed;
    }
    void addNode(int u) {
        if (adj.find(u) == adj.end()) {
            adj[u] = list<int>();
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
    void bfs(int src, vector<int> &ans, unordered_map<int, bool> &vis){
        queue<int> q;
        q.push(src);
        vis[src] = true;
        
        while(!q.empty()){
            int temp = q.front();
            q.pop();
            ans.push_back(temp);
            
            for(auto i: adj[temp]){
                if(!vis[i]){
                    vis[i]=true;
                    q.push(i);
                }
            }
        }
    }
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
    Graph g(false);

    int n, e;
    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> e;
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

    unordered_map<int, bool> vis;
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        if(!vis[i]) g.bfs(i, ans, vis);
    }
    for (auto i: ans)
    {
        cout<<i<<" ";
    }
    return 0;
}
/*
5
4
0 1
1 2
2 3
3 4
*/

