class Solution {
public:
    bool dfs(int i, int j, int n, int m, vector<vector<bool>> &vis, vector<vector<char>> &grid, string word, int index){
        if(i>=n || j>=m || i<0 || j<0) return false;
        if(vis[i][j] || grid[i][j] != word[index]) return false;
        if(index >= word.size()-1) return true;

        vis[i][j] = true;

        if(i+1 < n && grid[i+1][j] == word[index+1]) {
            if(dfs(i+1, j, n, m, vis, grid, word, index+1)) return true;
        }
        if(i-1 >= 0 && grid[i-1][j] == word[index+1]) {
            if(dfs(i-1, j, n, m, vis, grid, word, index+1)) return true;
        }
        if(j+1 < m && grid[i][j+1] == word[index+1]) {
            if(dfs(i, j+1, n, m, vis, grid, word, index+1)) return true;
        }
        if(j-1 >= 0 && grid[i][j-1] == word[index+1]) {
            if(dfs(i, j-1, n, m, vis, grid, word, index+1)) return true;
        }
        vis[i][j] = false;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j] && board[i][j] == word[0]){
                    if(dfs(i, j, n, m, vis, board, word, 0)) return true;
                }
            }
        }
        return false;
    }
};