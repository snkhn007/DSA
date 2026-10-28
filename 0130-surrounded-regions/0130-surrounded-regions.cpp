class Solution {
public:
    void dfs(int i, int j, int n, int m, vector<vector<char>>& grid,  vector<vector<bool>>& vis){
        if(i<0 || j<0 || i>=n || j>= m ) return;
        if(vis[i][j] || grid[i][j] == 'X') return;

        vis[i][j] = true;

        dfs(i-1, j, n, m, grid, vis);
        dfs(i+1, j, n, m, grid, vis);
        dfs(i, j+1, n, m, grid, vis);
        dfs(i, j-1, n, m, grid, vis);
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m, false));
        for(int i=0; i<n; i++){
            dfs(i, 0, n, m, board, vis);
            dfs(i, m-1, n, m, board, vis);
        }
        for(int i=0; i<m; i++){
            dfs(0, i, n, m, board, vis);
            dfs(n-1, i, n, m, board, vis);
        }

        for(int i=0; i<n; i++){
            for(int j =0; j<m; j++){
                if(!vis[i][j] && board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }
    }
};