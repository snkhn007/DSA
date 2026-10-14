class Solution {
public:
    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& vis, int i, int j){
        if(i<0 || j<0 || i >=grid.size() || j >= grid[0].size()) return;
        if(grid[i][j] != 1 || vis[i][j]) return;
        vis[i][j] = true;
        dfs(grid, vis, i+1, j);
        dfs(grid, vis, i-1, j);
        dfs(grid, vis, i, j+1);
        dfs(grid, vis, i, j-1);
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), cnt = 0;
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for(int i=0; i<n; i++){
            if(grid[i][0] == 1) dfs(grid, vis, i, 0);
            if(grid[i][m-1] == 1) dfs(grid, vis, i, m-1);
        }
        for(int j=0; j<m; j++){
            if(grid[0][j] == 1) dfs(grid, vis, 0, j);
            if(grid[n-1][j] == 1) dfs(grid, vis, n-1, j);
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j] && grid[i][j] == 1) cnt++;
            }
        }
        return cnt;
    }
};