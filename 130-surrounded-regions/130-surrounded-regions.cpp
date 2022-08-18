class Solution {
public:
    void dfs(vector<vector<char>> &board, int i, int j) {
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size()) {
            return;
        }
        
        if (board[i][j] == 'X') {
            return;
        }
        
        if (board[i][j] == 'O') {
            board[i][j] = 'B';
            dfs(board, i - 1, j);
            dfs(board, i + 1, j);
            dfs(board, i, j + 1);
            dfs(board, i, j - 1);
        }
        
    }
    
    void print(vector<vector<char>> board) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                cout<<board[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    
    void solve(vector<vector<char>>& board) {
        int lastRow = board.size() - 1;
        int lastCol = board[0].size() - 1;
        
        for (int i = 0; i < board.size(); i++) {
            if (board[i][0] == 'O') {
                dfs(board, i, 0);
            }
            if (board[i][lastCol] == 'O') {
                dfs(board, i, lastCol);
            }
        }
        
        for (int i = 0; i < board[0].size(); i++) {
            if (board[0][i] == 'O') {
                dfs(board, 0, i);
            }
            if (board[lastRow][i] == 'O') {
                dfs(board, lastRow, i);
            }
        }
        
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
        
       for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == 'B') {
                    board[i][j] = 'O';
                }
            }
        }
        
    }
};