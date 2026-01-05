#include <iostream>
#include <unordered_map>
#include <vector>
#include <utility>

/*
    Weighted Graph using Adjacency List

    - Supports directed and undirected graphs
    - Safe node handling (nodes created implicitly via addEdge)
    - Handles disconnected components
*/

using namespace std;
class Graph{
    unordered_map<int, vector<pair<int,int>>> adj;
    bool directed = false;

    // pair = (neighbor, weight)
    public:
    Graph(bool directed = false){
        this->directed = directed;
    }
    void addNode(int u){
        if(adj.find(u)==adj.end()) adj[u] = vector<pair<int, int>>();
    }
    void addEdge(int u, int v, int w){
        // Keep addNode()
        // Call it only inside addEdge()
        // Do NOT rely on n unless required by problem
        addNode(u);
        addNode(v);

        adj[u].push_back({v, w});
        if(!directed){
            adj[v].push_back({u, w});
        }
    }

    void print(){
        // const auto& in range-based loops to avoid unnecessary copies and to ensure the container is not modified accidentally
        for(const auto &i: adj){
            cout<<i.first<<"->";
            for(const auto &j: i.second){
                cout<<"("<<j.first<<","<<j.second<<")"<<" ";
            }
            cout<<endl;
        }
    }

};
int main(){
    Graph g(false);
    g.addEdge(0, 1, 4);
    g.addEdge(0, 2, 1);
    g.addEdge(2, 1, 2);
    g.addEdge(1, 3, 5);
    g.addEdge(3, 4, 3);

    // disconnected component
    g.addEdge(5, 6, 2);

    g.print();
}