class Solution {
public:
    void dfs(vector<vector<int>> &grid, vector<vector<bool>> & vis, int i, int j, int &cnt){
        int n =grid.size(), m= grid[0].size();
        if(i >=n || i < 0 || j>=m || j <0) return;

        if(grid[i][j] == 0 || vis[i][j] == true) return;
        vis[i][j] = true;
        // if(i+1>= n || (i+1>=n && grid[i+1][j] == 0)) cnt++;
        if (i + 1 >= n || grid[i + 1][j] == 0) cnt++;
        if (i - 1 < 0 || grid[i - 1][j] == 0) cnt++;
        if (j + 1 >= m || grid[i][j + 1] == 0) cnt++;
        if (j - 1 < 0 || grid[i][j - 1] == 0) cnt++;
        dfs(grid, vis,i+1, j, cnt);
        dfs(grid, vis, i-1, j , cnt);
        dfs(grid, vis, i, j+1, cnt);
        dfs(grid, vis,i, j-1, cnt);
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), cnt = 0;
        vector<vector<bool>> vis(n, vector<bool> (m , false));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                // if(!vis[i][j]) dfs(grid, vis, i, j, cnt);
                if(grid[i][j] == 1){
                    if (i + 1 >= n || grid[i + 1][j] == 0) cnt++;
                    if (i - 1 < 0 || grid[i - 1][j] == 0) cnt++;
                    if (j + 1 >= m || grid[i][j + 1] == 0) cnt++;
                    if (j - 1 < 0 || grid[i][j - 1] == 0) cnt++;
                }
            }
        }
        return cnt;
    }
};