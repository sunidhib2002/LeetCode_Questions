class Solution {
public:
    void dfs(vector<vector<int>> &grid, int i, int j, vector<vector<int>> &visited) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()) {
            return;
        }    
        
        if (visited[i][j] == 1) {
            return;
        }
        
        if (grid[i][j] == 0) {
            return;
        }
        
        grid[i][j] = 0;
        visited[i][j] = 1;
        dfs(grid, i + 1, j, visited);
        dfs(grid, i - 1, j, visited);
        dfs(grid, i, j + 1, visited);
        dfs(grid, i, j - 1, visited);
        
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), 0));
        for (int i = 0; i < grid[0].size(); i++) {
            if (grid[0][i] == 1) {
                dfs(grid, 0, i, visited);
            } 
            if (grid[grid.size() - 1][i] == 1) {
                dfs(grid, grid.size() - 1, i, visited);
            }
        }
        
        for (int i = 0; i < grid.size(); i++) {
            if (grid[i][0] == 1) {
                dfs(grid, i, 0, visited);
            } 
            if (grid[i][grid[0].size() - 1] == 1) {
                dfs(grid, i, grid[0].size() - 1, visited);
            }
        }
        
        int cnt = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    cnt++;
                }
            }
        }
        
        return cnt;
    }
};