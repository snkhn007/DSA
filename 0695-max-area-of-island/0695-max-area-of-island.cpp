class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i, int j, vector<vector<bool>>& vis, int &res){
        if(i<0 || i >= grid.size() || j<0 || j >= grid[0].size()) return;
        if(vis[i][j] || grid[i][j] != 1) return;
        vis[i][j] = true;
        res++;
        dfs(grid, i+1, j, vis, res);
        dfs(grid, i-1, j, vis, res);
        dfs(grid, i, j+1, vis, res);
        dfs(grid, i, j-1, vis, res);

    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        // does not ask you to eliminate islands touching the boundary**
        int n = grid.size(), m = grid[0].size(), res = 0;
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        for(int i=0; i<n; i++){
            for(int j =0; j<m; j++){
                int temp = 0;
                if(!vis[i][j] && grid[i][j] == 1) dfs(grid, i, j, vis, temp);
                res = max(temp, res);
            }
        }
        return res;
    }
};