#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
class Graph{
    unordered_map <int, vector<int>> adj;
    // undirected
    public:
    void addNode(int u){
        if(adj.find(u)==adj.end()) adj[u]=vector<int>();
    }    
    void addEdge(int u, int v){
        addNode(u);
        addNode(v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void prepare(){
        for(auto &i: adj){
            sort(i.second.begin(), i.second.end());
        }
    }
    bool bfs(int src, unordered_map<int, bool> &vis, unordered_map<int, int> &parent){
        queue <int> q;
        q.push(src);
        vis[src]=true;
        parent[src] = -1;

        while(!q.empty()){
            int temp = q.front();
            q.pop();

            for(auto i: adj[temp]){
                if(!vis[i]){
                    q.push(i);
                    vis[i]=true;
                    parent[i]=temp;
                }
                else if(vis[i] && i != parent[temp]){
                    return true;
                }
            }
        }
        return false;
    }
};
int main(){
    int n, e;
    cin>>n>>e;
    Graph g;
    for(int i=0; i<n; i++) g.addNode(i);
    for(int i=0; i<e; i++){
        int u, v;
        cin>>u>>v;
        g.addEdge(u, v);
    }
    unordered_map<int, bool> vis;
    unordered_map<int, int> parent;
    g.prepare();

    bool ans = false;
    for(int i=0; i<n; i++){
        if(!vis[i]) ans = g.bfs(i, vis, parent);
    }
    cout<<"Cycle "<<(ans? "detected":"Not detected");
}