class Solution {
public:
    void dfs(int i, int j, int n, int m, vector<vector<bool>>& vis, vector<vector<int>>& grid, int&sum){
        if( i<0 || j<0 || i>=n || j>=m) return;
        if(vis[i][j] || grid[i][j] == 0) return;

        vis[i][j] = true;
        sum += grid[i][j];

        dfs(i+1, j, n, m, vis, grid, sum);
        dfs(i-1, j, n, m, vis, grid, sum);
        dfs(i, j+1, n, m, vis, grid, sum);
        dfs(i, j-1, n, m, vis, grid, sum);
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), res =0;
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j] && grid[i][j] != 0){
                    int sum = 0;
                    dfs(i, j, n, m, vis, grid, sum);
                    res = max(sum, res);
                }
            }
        }
        return res;
    }
};