#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

/*
    Graph implementation using adjacency list.
    - Supports BFS and DFS
    - Handles disconnected graphs
    - Lexicographic traversal using sorted adjacency list
*/

class Graph{
    private:
    unordered_map <int, vector<int>> adj;
    bool direction;
    public:
    Graph(bool direction = false){
        this->direction = direction;
    }
    void addNode(int u){
        if(adj.find(u)==adj.end()) adj[u]=vector<int>();
    }
    void addEdge(int u,  int v){
        addNode(u);
        addNode(v);

        adj[u].push_back(v);
        if(!direction) adj[v].push_back(u);
    }
    void print(){
        for(auto i: adj){
            cout<<i.first<<" -> ";
            for(auto j:i.second) cout<<j<<" ";
            cout<<endl;
        }
    }

    // Sort adjacency list for lexicographic traversal
    void prepare(){
        for(auto &i: adj){
            sort(i.second.begin(), i.second.end());
        }
        cout<<endl;
    }
    
    // Depth First Search (DFS)
    void dfs(int src, unordered_map<int, bool> & vis){
        vis[src]=true;
        cout<<src<<" ";
        for(auto i: adj[src]){
            if(!vis[i]) dfs(i, vis);
        }
    }

    void bfs(int src, vector<int> &ans, unordered_map<int, bool> & vis){
        queue<int> q;
        q.push(src);
        vis[src]=true;
        while(!q.empty()){
            int temp = q.front();
            q.pop();
            ans.push_back(temp);

            for(auto i: adj[temp]){
                if(!vis[i]){
                    q.push(i);
                    vis[i]=true;
                }
            }
        }
    }

};
int main() {
    Graph g(false);

    int n = 5;

    // Add edges
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(4, 3);

    cout << "Adjacency List:\n";
    g.print();

    // Prepare for lexicographic traversal
    g.prepare();

    cout << "\nSorted Adjacency List:\n";
    g.print();
    
    // BFS (handles disconnected graph)
    unordered_map<int, bool> visBfs;
    vector<int> bfsResult;

    for (int i = 0; i < n; i++) {
        if (!visBfs[i])
            g.bfs(i, bfsResult, visBfs);
    }

    cout << "\nBFS Traversal: ";
    for (int x : bfsResult)
    cout << x << " ";
    cout << endl;
    
    // DFS (handles disconnected graph)
    unordered_map<int, bool> visDfs;
    
    cout << "\nDFS Traversal: ";
    for (int i = 0; i < n; i++) {
        if (!visDfs[i])
            g.dfs(i, visDfs);
    }

}
/*
Sample Graph:
0 -- 1
|    |
4    2
|
3

Expected Output:

Adjacency List:
0 -> 1 4
1 -> 0 2
2 -> 1
3 -> 4
4 -> 0 3

BFS Traversal:
0 1 4 2 3

DFS Traversal:
0 1 2 4 3
*/








