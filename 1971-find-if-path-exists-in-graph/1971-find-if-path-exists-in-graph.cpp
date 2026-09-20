class Solution {
public:
    bool dfs(int node, vector<vector<int>> &adj, vector<bool>& vis, int dest){
        vis[node] = true;
        for(auto i : adj[node]){
            if(i == dest) return true;
            if(!vis[i]){
                if(dfs(i, adj, vis, dest)) return true;
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int src, int dest) {
        if(src == dest) return true;
        vector<vector<int>> adj(n);
        for(auto i : edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }  
        vector<bool> vis(n, false);
        return dfs(src, adj, vis, dest);     

    }
};