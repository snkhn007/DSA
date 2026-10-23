class Solution {
public:
    void dfs(vector<vector<int>>& grid,vector<vector<bool>>& vis, int i, int j, int &cordI, int&cordJ){
        int n = grid.size(), m =grid[0].size();
        if( i<0 || j<0 || i>=n || j >=m) return;
        if(grid[i][j] == 0 || vis[i][j]) return;

        vis[i][j] = true;
        cordI = max(i , cordI);
        cordJ = max(j , cordJ);
        dfs(grid, vis, i+1, j, cordI, cordJ);
        dfs(grid, vis, i-1, j, cordI, cordJ);
        dfs(grid, vis, i, j+1, cordI, cordJ);
        dfs(grid, vis, i, j-1, cordI, cordJ);     
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int n = land.size(), m =land[0].size();
        vector<vector<bool>> vis(n, vector<bool> (m, false));
        vector<vector<int>> res;
        for(int i=0; i<n; i++){
            for(int j =0; j<m; j++){
                if(!vis[i][j] && land[i][j] == 1){
                    int cordI = i, cordJ = j;
                    dfs(land, vis, i, j, cordI, cordJ);
                    res.push_back({i, j, cordI, cordJ});
                }
            }
        }
        return res;
        
    }
};