class Solution {
public:
    void dfs(vector<vector<char>>& grid, int i, int j, vector<vector<bool>>& vis, int n, int m){
        if(i>=n || j>=m || i<0 || j<0) return;
        if(vis[i][j] || grid[i][j] == '0') return;    
        vis[i][j] = true;

        dfs(grid, i+1, j, vis, n, m);    
        dfs(grid, i-1, j, vis, n, m);    
        dfs(grid, i, j+1, vis, n, m);    
        dfs(grid, i, j-1, vis, n, m);    
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m , false));
        int res = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                // if(!vis[i][j]){
                //     dfs(grid, i, j, vis, n, m);
                //     res++;
                // }
                if(!vis[i][j] && grid[i][j] == '1'){
                    dfs(grid, i, j, vis, n, m);
                    res++;
                }
            }
        }

        return res;
        
    }
};