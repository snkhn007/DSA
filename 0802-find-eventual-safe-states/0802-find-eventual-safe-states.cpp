class Solution {
public:
    bool dfs(vector<vector<int>>& graph, vector<bool>& vis, vector<int>& path, int node, vector<int>& res){
        vis[node] = true;
        path[node] = 1;
        for(auto i : graph[node]){
            if(!vis[i]){
                if(!dfs(graph, vis, path, i, res)) return false;
                else res.push_back(i);
            }else if(vis[i] && path[i] == 1){
                // cycle detected
                return false;
            }
        }
        path[node] = 0;
        return true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool> vis(n, false);
        vector<int> path(n, 0), res;
        for(int i=0; i<n; i++){
            if(!vis[i]){
                if(dfs(graph, vis, path, i, res)) res.push_back(i);
            }
        }
        sort(res.begin(), res.end());
        return res;        
    }
};