class Solution {
public:
    void dfs(vector<vector<int>>& graph, vector<int>& path, int node, vector<vector<int>>& res){
        // vis[node] = true;
        path.push_back(node);

        for(auto i: graph[node]){
            // if(!vis[i]){
            //     vis[i] = true;
            //     dfs(graph, path, i, vis, res);
            //     path.pop_back();
            // }
            dfs(graph, path, i, res);
            path.pop_back();
        }

        if(node == graph.size() - 1){
            res.push_back(path);
            return;
        }
        return;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> res;
        vector<int> path;
        vector<bool> vis(n, false);

        // for(int i=0; i<n; i++){
        //     // if(!vis[i]){
        //     //     dfs(graph, path, i, vis, res);
        //     // }
        //     dfs(graph, path, i, res);
        // }
        dfs(graph, path, 0, res);


        return res;
    }
};