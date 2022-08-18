class Solution {
public:
    int dfs(vector<vector<int>> &grid, int i, int j, vector<vector<int>> &visited) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()) {
            return 0;
        }
        
        if (visited[i][j] == 1) {
            return 0;
        }
        
        visited[i][j] = 1;
        if (grid[i][j] == 0) {
            return 0;
        }
        
        return 1 + dfs(grid, i + 1, j, visited) + dfs(grid, i - 1, j, visited) + dfs(grid, i, j + 1, visited) + dfs(grid, i, j - 1, visited);
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int mx = 0;
        vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), 0));
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1 && visited[i][j] == 0) {
                    int cnt = dfs(grid, i, j, visited);
                    // cout<<cnt<<" "<<mx<<endl;
                    if (mx < cnt) {
                        mx = cnt;
                    }
                }
            }
        }
        return mx;
    }
};