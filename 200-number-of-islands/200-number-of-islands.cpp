class Solution {
public:
    void dfs(vector<vector<char>>& grid, int row, int col) {
        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[row].size()) {
            return;
        }
        
        if (grid[row][col] == '0' || grid[row][col] == '2') {
            return;
        }

        grid[row][col] = '2';
        
        dfs(grid, row + 1, col);
        dfs(grid, row - 1, col);
        dfs(grid, row, col - 1);
        dfs(grid, row, col + 1);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int countOfIslands = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == '1') {
                    countOfIslands += 1;
                    dfs(grid, i, j);
                }
            }
        }
        return countOfIslands;
    }
};