class Solution {
public:
    void dfs(int node, vector<vector<int>>& mat, vector<bool>& vis){
        vis[node] = true;
        for(int i = 0; i < mat.size(); i++){
            if(mat[node][i] == 1 && !vis[i]){
                dfs(i, mat, vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> vis(n, false);
        int cnt = 0;

        for(int i=0; i<vis.size(); i++){
            if(!vis[i]){
                dfs(i, isConnected, vis);
                cnt++;
            }
        }

        return cnt;
    }
};