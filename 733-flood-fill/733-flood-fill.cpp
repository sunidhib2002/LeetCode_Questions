class Solution {
public:
    void dfs(vector<vector<int>>& image, int row, int col, int color, int prev) {
        if (row < 0 || row >= image.size() || col < 0 || col >= image[row].size() || image[row][col] != prev) {
            return;
        } 
        image[row][col] = color;
        dfs(image, row + 1, col, color, prev);
        dfs(image, row - 1, col, color, prev);
        dfs(image, row, col + 1, color, prev);
        dfs(image, row, col - 1, color, prev);
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if (image[sr][sc] == color) {
            return image;
        }
        dfs(image, sr, sc, color, image[sr][sc]);
        return image;
    }
};