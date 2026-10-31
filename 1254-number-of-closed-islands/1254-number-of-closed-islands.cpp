class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i, int j, int n, int m, vector<vector<bool>>& vis){
        if(i<0 || j<0 || i>=n || j>=m) return;
        if(grid[i][j] == 1 || vis[i][j]) return;
        vis[i][j] = true;
        dfs(grid, i+1, j, n, m, vis);
        dfs(grid, i-1, j, n, m, vis);
        dfs(grid, i, j+1, n, m, vis);
        dfs(grid, i, j-1, n, m, vis);
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), res = 0;
        vector<vector<bool>>vis(n, vector<bool>(m, false));
        for(int i=0; i<n; i++){
            if(grid[i][0] == 0) dfs(grid, i, 0, n, m, vis);
            if(grid[i][m-1] == 0) dfs(grid, i, m-1, n, m, vis);
        }
        for(int j=0; j<m; j++){
            if(grid[0][j] == 0) dfs(grid, 0, j, n, m, vis);
            if(grid[n-1][j] == 0) dfs(grid, n-1, j, n, m, vis);
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 0 && !vis[i][j]){
                    res++;
                    dfs(grid, i, j, n, m, vis);
                }
            }
        }

        return res;
        
    }
};