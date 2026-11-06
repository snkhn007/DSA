class Solution {
public:
    int count = 0;

    bool isSafe(int row, int col, vector<string>& board, int n) {

        // Check column
        for(int i = 0; i < row; i++) {
            if(board[i][col] == 'Q')
                return false;
        }

        // Check upper-left diagonal
        int i = row - 1, j = col - 1;

        while(i >= 0 && j >= 0) {
            if(board[i][j] == 'Q')
                return false;
            i--;
            j--;
        }

        // Check upper-right diagonal
        i = row - 1;
        j = col + 1;

        while(i >= 0 && j < n) {
            if(board[i][j] == 'Q')
                return false;
            i--;
            j++;
        }

        return true;
    }

    void solve(int row, vector<string>& board, int n) {

        if(row == n) {
            count++;
            return;
        }

        for(int col = 0; col < n; col++) {

            if(isSafe(row, col, board, n)) {

                board[row][col] = 'Q';

                solve(row + 1, board, n);

                board[row][col] = '.';
            }
        }
    }

    int totalNQueens(int n) {

        vector<string> board(n, string(n, '.'));

        solve(0, board, n);

        return count;
    }
};