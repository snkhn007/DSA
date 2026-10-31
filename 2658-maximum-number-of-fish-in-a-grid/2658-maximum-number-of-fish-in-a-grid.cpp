class Solution {
public:
    void dfs(int i, int j, int n, int m, vector<vector<int>>& grid, int&sum){
        if( i<0 || j<0 || i>=n || j>=m) return;
        if(grid[i][j] == 0) return;

        sum += grid[i][j];
        grid[i][j] = 0;

        dfs(i+1, j, n, m, grid, sum);
        dfs(i-1, j, n, m, grid, sum);
        dfs(i, j+1, n, m, grid, sum);
        dfs(i, j-1, n, m, grid, sum);
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), res =0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] != 0){
                    int sum = 0;
                    dfs(i, j, n, m, grid, sum);
                    res = max(sum, res);
                }
            }
        }
        return res;
    }
};