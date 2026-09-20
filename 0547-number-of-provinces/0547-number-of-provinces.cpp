class Solution {
public:
    void dfs(int node, vector<bool> & vis, vector<vector<int>>& mat){
        vis[node] = true;
        for(int i=0; i<mat[node].size(); i++){
            if(mat[node][i]  &&  !vis[i]) dfs(i, vis, mat);
        }
        // for(auto i: mat[node]){
        // here i is value not the index
        //     if(i == 1 && !vis[i]) dfs(i, vis, mat);
        // }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n  = isConnected.size();
        vector<bool> vis(n, false);
        int cnt = 0;
        for(int i=0; i<n; i++){
            if(!vis[i]){
                dfs(i, vis, isConnected);
                cnt++;
            }
        }
        return cnt;
    }
};