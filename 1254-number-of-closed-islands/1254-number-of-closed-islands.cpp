class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i, int j, int n, int m){
        if(i<0 || j<0 || i>=n || j>=m) return;
        // if(grid[i][j] != 0) return;
        if(grid[i][j] == 1) return;

        grid[i][j] = 1;
        dfs(grid, i+1, j, n, m);
        dfs(grid, i-1, j, n, m);
        dfs(grid, i, j+1, n, m);
        dfs(grid, i, j-1, n, m);
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), res = 0;
        for(int i=0; i<n; i++){
            if(grid[i][0] == 0) dfs(grid, i, 0, n, m);
            if(grid[i][m-1] == 0) dfs(grid, i, m-1, n, m);
        }
        for(int j=0; j<m; j++){
            if(grid[0][j] == 0) dfs(grid, 0, j, n, m);
            if(grid[n-1][j] == 0) dfs(grid, n-1, j, n, m);
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 0){
                    res++;
                    dfs(grid, i, j, n, m);
                }
            }
        }

        return res;
        
    }
};