class Solution {
public:
    bool isValid(int x, int y, int m, int n, vector<vector<int>> &grid) {
        if (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == 1) {
            return true;
        }
        return false;
    }
    
    void print(queue<pair<int, int>> q) {
        while (!q.empty()) {
            cout<<q.front().first<<" "<<q.front().second<<endl;
            q.pop();
        }
        cout<<endl;
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int fresh = 0;
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    fresh++;       
                }     
                if (grid[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }
        
        int time = 0;
        
        if (fresh == 0) {
            return 0;
        }
        
        while (!q.empty()) {
            int t = q.size();
            // cout<<n<<endl;
            // print(q);
            for (int i = 0; i < t; i++) {
                pair<int, int> p = q.front();
                q.pop();
                int x1 = p.first;
                int y1 = p.second;
                if (isValid(x1 - 1, y1, m, n, grid)) {
                    q.push({x1 - 1, y1});   
                    grid[x1 - 1][y1] = 2;
                }
                if (isValid(x1 + 1, y1, m, n, grid)) {
                    q.push({x1 + 1, y1}); 
                    grid[x1 + 1][y1] = 2;
                }
                if (isValid(x1, y1 + 1, m, n, grid)) {
                    q.push({x1, y1 + 1});         
                    grid[x1][y1 + 1] = 2;
                }
                if (isValid(x1, y1 - 1, m, n, grid)) {
                    q.push({x1, y1 - 1});         
                    grid[x1][y1 - 1] = 2;
                }
            }
            time++;
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    return -1;
                }
            }
        }
        
        return (time - 1);
    }
};