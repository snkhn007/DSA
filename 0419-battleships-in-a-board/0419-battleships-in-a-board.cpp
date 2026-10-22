class Solution {
public:
    void dfs(vector<vector<char>> &board, vector<vector<bool>>& vis, int i, int j){
        int n = board.size(), m = board[0].size();
        if(i<0 || j<0 || i>=n || j>=m) return;
        if(vis[i][j] || board[i][j] != 'X') return;
        vis[i][j] = true;  
        dfs(board, vis, i+1, j);      
        dfs(board, vis, i-1, j);      
        dfs(board, vis, i, j+1);      
        dfs(board, vis, i , j-1);      
    }
    int countBattleships(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size(), cnt = 0;
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        for(int i=0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(!vis[i][j] && board[i][j] == 'X'){
                    dfs(board, vis, i, j);
                    cnt++;
                }
            }
        }

        return cnt;
        
    }
};