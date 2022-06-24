class Solution {
public:
    void dfs(vector<vector<int>>& grid, int row, int col) {
        //cout<<row<<" "<<col<<endl;
        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[row].size()) {
            return;
        }
        if (grid[row][col] == 1) {
            return;
        }
        grid[row][col] = 1;
        dfs(grid, row + 1, col);
        dfs(grid, row - 1, col);
        dfs(grid, row, col - 1);
        dfs(grid, row, col + 1);
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        int firstRow = 0;
        int lastRow = grid.size() - 1;
        int firstCol = 0;
        int lastCol = grid[0].size() - 1;
        int cnt = 0;
        
        // for (int i = 0; i < grid.size(); i++) {
        //     for (int j = 0; j < grid[i].size(); j++) {
        //         cout<<grid[i][j]<<" "; 
        //     }
        //     cout<<endl;
        // }
        // cout<<endl;
        
        for (int i = 0; i < grid[0].size(); i++) {
            if (grid[firstRow][i] == 0) {
                dfs(grid, firstRow, i);
            } 
        }
        
        for (int i = 0; i < grid[0].size(); i++) {
            if (grid[lastRow][i] == 0) {
                dfs(grid, lastRow, i);
            } 
        }
        
        for (int i = 0; i < grid.size(); i++) {
            if (grid[i][firstCol] == 0) {
                dfs(grid, i, firstCol);
            } 
        }
        
        for (int i = 0; i < grid.size(); i++) {
            if (grid[i][lastCol] == 0) {
                dfs(grid, i, lastCol);
            } 
        }
        
        // for (int i = 0; i < grid.size(); i++) {
        //     for (int j = 0; j < grid[i].size(); j++) {
        //         cout<<grid[i][j]<<" "; 
        //     }
        //     cout<<endl;
        // }
        
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 0) {
                    dfs(grid, i, j);
                    cnt++;
                }    
            }
        }
        
        return cnt;
    }
};