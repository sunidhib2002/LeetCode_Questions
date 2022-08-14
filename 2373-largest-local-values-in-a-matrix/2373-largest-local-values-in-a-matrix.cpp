class Solution {
public:
    int findMaxVal(int i1, int i2, int j1, int j2, vector<vector<int>> &grid) {
        int mx = 0;
        for (int i = i1; i <= i2; i++) {
            for (int j = j1; j <= j2; j++) {
                mx = max(mx, grid[i][j]);
            }
        }
        return mx;
    }
    
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int i = 0;
        int j = 0;
        int row = grid.size();
        int col = grid.size();
        vector<vector<int>> maxVal;
        while (i < row && i + 2 < row) {
            j = 0;
            vector<int> vec;
            while (j < col && j + 2 < col) {
                vec.push_back(findMaxVal(i, i + 2, j, j + 2, grid));
                j++;    
            }
            maxVal.push_back(vec);
            i++;
        }
        return maxVal;
    }
};