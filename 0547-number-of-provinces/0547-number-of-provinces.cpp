class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& vis){
        vis[node] = true;
        for(auto i:adj[node]){
            if(!vis[i]){
                dfs(i, adj, vis);
            }else continue;
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        // building adj list->
        int n = isConnected.size();
        vector<vector<int>> adj(n);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(isConnected[i][j] == 1){
                    adj[i].push_back(j);
                }
            }
        }

        vector<bool> vis(n, false);
        int cnt = 0;

        for(int i=0; i<vis.size(); i++){
            if(!vis[i]){
                dfs(i, adj, vis);
                cnt++;
            }
        }

        return cnt;
    }
};