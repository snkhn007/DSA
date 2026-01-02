#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;
class Graph{
    map <int ,vector<int>> adj;
    bool direction;

    public:
    Graph(bool direction = false){
        this->direction = direction;
    }

    void addNode(int u){
        if(adj.find(u)==adj.end()) adj[u]=vector<int>();
    }

    void addEdge(int u, int v){
        if(u == v) return; // remove self-loops
        addNode(u);
        addNode(v);

        adj[u].push_back(v);
        if(!direction) adj[v].push_back(u);
    }

    void prepare(){
        for(auto &i: adj){
            sort(i.second.begin(), i.second.end());
        }
    }

    void bfs(int src, vector<int> &ans, map<int, bool> &vis){
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

    void print(){
        if(adj.empty()){
            cout<<"Empty graph"; 
            return;
        }
        for(auto i: adj){
            cout<<i.first<<" -> ";
            for(auto j: i.second){
                cout<<j<<" ";
            }
            cout<<endl;
        }
    }
};
int main(){
    Graph g;
    int n, e;
    cin>>n>>e;
    for (int i = 0; i < n; i++) g.addNode(i);
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin>>u>>v;
        g.addEdge(u, v);
    }
    g.print();
    cout<<endl;
    // g.prepare();
    // cout<<endl;
    g.print();
    vector <int> ans;
    map<int, bool> vis;
    for (int i = 0; i < n; i++)
    {
        if(!vis[i]) g.bfs(i, ans, vis);
    }
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
}