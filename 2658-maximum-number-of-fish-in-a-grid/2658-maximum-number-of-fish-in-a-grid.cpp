class Solution {
public:
    int dfs(int i, int j, int n, int m, vector<vector<int>>& grid){
        if( i<0 || j<0 || i>=n || j>=m) return 0;
        if(grid[i][j] == 0) return 0;

        int sum = grid[i][j];
        grid[i][j] = 0;

        sum += dfs(i+1, j, n, m, grid);
        sum += dfs(i-1, j, n, m, grid);
        sum += dfs(i, j+1, n, m, grid);
        sum += dfs(i, j-1, n, m, grid);

        return sum;
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), res =0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] != 0){
                    res = max(res, dfs(i, j, n, m, grid));
                }
            }
        }
        return res;
    }
};