class Solution {
public:
    void dfs(vector<vector<char>>& board, int i, int j, vector<vector<bool>>& vis){
        if(i >= board.size() || i<0 || j>=board[0].size() || j <0) return;
        if (board[i][j] != 'O' || vis[i][j]) return;
        vis[i][j] = true;

        dfs(board, i+1, j, vis);
        dfs(board, i-1, j, vis);
        dfs(board, i, j+1, vis);
        dfs(board, i, j-1, vis);
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for(int i=0; i<n; i++){
            if(board[i][0] == 'O') dfs(board, i, 0, vis);
            if(board[i][m-1] == 'O') dfs(board, i, m-1, vis);
        }
        for(int i=0; i<m; i++){
            if(board[0][i] == 'O') dfs(board, 0, i, vis);
            if(board[n-1][i] == 'O') dfs(board, n-1,i,  vis);
        }      

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j] == 'O' && !vis[i][j]) board[i][j] = 'X';
            }
        }
    }
};