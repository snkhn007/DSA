class Solution {
public:
    void dfs(vector<vector<int>> & grid, int node, vector<bool> & vis){
        vis[node] = true;
        for(int i=0; i<grid[0].size(); i++){
            if(grid[node][i] == 1 && !vis[i]){
                // edges between node <-> i
                dfs(grid, i, vis);                
            }
        }           
    }
    int findCircleNum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), res = 0;
        vector<bool> vis(n, false);
        for(int i=0; i<n; i++){
            if(!vis[i]){
                dfs(grid, i, vis);
                res++;
            }
        }
        return res;
    }
};