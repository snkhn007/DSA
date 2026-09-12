class Solution {
public:
    void dfs(int row, int col, int rows, int cols, vector<vector<char>>& grid, vector<vector<bool>>& vis){
        vis[row][col] = true;
        if(row - 1 >= 0 && !vis[row-1][col] && grid[row-1][col]== '1') dfs(row-1, col,rows, cols, grid, vis);
        if(row + 1 < rows && !vis[row+1][col] && grid[row+1][col] == '1') dfs(row+1, col, rows, cols, grid, vis);
        if(col + 1 < cols && !vis[row][col+1] && grid[row][col +1] == '1') dfs(row, col+1, rows, cols, grid, vis);
        if(col - 1 >= 0 && !vis[row][col-1] && grid[row][col -1]== '1') dfs(row, col-1,rows, cols, grid, vis);
    }
    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        // vector<bool> vis(n, false);

        vector<vector<bool>> vis(rows, vector<bool>(cols, false));
        
        for(int i=0; i<rows ; i++){
            for(int j=0; j<cols; j++){

                if(!vis[i][j] && grid[i][j] == '1'){
                    dfs(i, j,rows, cols, grid, vis);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};