class Solution {
public:
    void dfs(int i, int j, vector<vector<char>>& grid, vector<vector<bool>>& vis){
        vis[i][j] = true;
        int n = grid.size();
        int m = grid[0].size();

        if(i+1 < n && !vis[i+1][j] && grid[i+1][j] == '1'){
            dfs(i+1, j, grid, vis);
        }
        if(i-1 >= 0 && !vis[i-1][j] && grid[i-1][j] == '1'){
            dfs(i-1, j, grid, vis);
        }
        if(j-1 >= 0 && !vis[i][j-1] && grid[i][j-1] == '1'){
            dfs(i, j-1, grid, vis);
        }
        if(j+1 < m && !vis[i][j+1] && grid[i][j+1] == '1'){
            dfs(i, j+1, grid, vis);
        }  
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m, false));
        int cnt = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == '1' && !vis[i][j]){
                    dfs(i, j, grid , vis);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};