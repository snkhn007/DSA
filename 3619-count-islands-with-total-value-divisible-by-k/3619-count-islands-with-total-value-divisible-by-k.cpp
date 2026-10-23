class Solution {
public:
    long long dfs(vector<vector<int>>& grid, int i, int j, vector<vector<bool>>& vis){
        int n = grid.size(), m =grid[0].size();
        if(i>=n || j>=m || i<0 || j<0) return 0;
        if(vis[i][j] || grid[i][j] == 0) return 0;

        vis[i][j] = true;
        return (long long)grid[i][j] +
            dfs(grid, i+1, j, vis) +
            dfs(grid, i-1, j, vis) +
            dfs(grid, i, j+1, vis) +
            dfs(grid, i, j-1, vis);
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m =grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        int cnt = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j] && grid[i][j] != 0){
                    long long   res = 0;
                    res += dfs(grid, i, j, vis);
                    if(res%k == 0) cnt++;
                }
            }
        }
        return cnt ;
        
    }
};