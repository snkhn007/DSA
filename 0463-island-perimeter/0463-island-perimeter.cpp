class Solution {
public:
    void dfs(int i, int j, int n, int m, vector<vector<int>>& grid, vector<vector<bool>>& vis, int&res){
        if(i<0 || j<0 || i>=n ||j>=m) return;
        if(vis[i][j] || grid[i][j] == 0) return;
        vis[i][j] = true;

        if(i+1>=n || grid[i+1][j] == 0) res++;
        if(i-1<0 || grid[i-1][j] == 0) res++;
        if(j-1<0 || grid[i][j-1] == 0) res++;
        if(j+1>=m || grid[i][j+1] == 0) res++;

        dfs(i+1, j, n, m, grid, vis, res);
        dfs(i-1, j, n, m, grid, vis, res);
        dfs(i, j+1, n, m, grid, vis, res);
        dfs(i, j-1, n, m, grid, vis, res);
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), res = 0;
        vector<vector<bool>>vis(n, vector<bool>(m, false));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j] && grid[i][j] == 1) dfs(i, j, n, m, grid, vis, res);
            }
        }
        return res;
    }
};