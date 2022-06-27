class Solution {
public:
    void dfs(vector<vector<char>> &board, int row, int col, string word, int k, string &str, int prevRow, int prevCol, int &flag, vector<vector<int>> &visited) {
        if (row < 0 || row >= board.size() || col < 0 || col >= board[row].size()) {
            return;
        }
        
        //cout<<row<<" "<<col<<" "<<prevRow<<" "<<prevCol<<" "<<str<<endl;
        
        if (row == prevRow && col == prevCol) {
            return;
        }
        
        if (str == word) {
            flag = 1;
            return;
        }
        
        if (word[k] == board[row][col] && visited[row][col] != 1) {
            str += board[row][col];
            visited[row][col] = 1;
            if (str == word) {
                flag = 1;
                return;
            }
            //cout<<"match "<<str<<endl;
          //  cout<<"next ch "<<word[k + 1]<<endl;
            if (col + 1 < board[row].size() && board[row][col + 1] == word[k + 1]) {
            //    cout<<" next col "<<endl;
                dfs(board, row, col + 1, word, k + 1, str, row, col, flag, visited);
            }
            if (col - 1 >= 0 && board[row][col - 1] == word[k + 1]) {
           //     cout<<" prev col "<<endl;
                dfs(board, row, col - 1, word, k + 1, str, row, col, flag, visited);
            }
            if (row + 1 < board.size() && board[row + 1][col] == word[k + 1]) {
           //     cout<<" next row "<<endl;
                dfs(board, row + 1, col, word, k + 1, str, row, col, flag, visited);
            }
            if (row - 1 >= 0 && board[row - 1][col] == word[k + 1]) {
          //      cout<<" prev row "<<endl;
                dfs(board, row - 1, col, word, k + 1, str, row, col, flag, visited);
            }
            str.erase(str.length() - 1);
            visited[row][col] = 0;
        }
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (word[0] == board[i][j]) {
                    string str = "";
                    int k = 0, flag = 0;
                    vector<vector<int>> visited(board.size(), vector<int>(board[0].size(), 0));
                    dfs(board, i, j, word, k, str, -1, -1, flag, visited);
                    if (flag) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};