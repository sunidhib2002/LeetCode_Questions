class Solution {
public:
    void dfs(vector<vector<int>> &image, int sr, int sc, int prevColor, int color, vector<vector<int>> &visited) {
        if (sr < 0 || sc < 0 || sr >= image.size() || sc >= image[0].size()) {
            return;
        }
        
        if (visited[sr][sc] == 1) {
            return;
        }
        
        visited[sr][sc] = 1;
        
        if (image[sr][sc] != prevColor) {
            return;
        }
        
        if (image[sr][sc] == prevColor) {
            image[sr][sc] = color;
            dfs(image, sr + 1, sc, prevColor, color, visited);
            dfs(image, sr - 1, sc, prevColor, color, visited);
            dfs(image, sr, sc + 1, prevColor, color, visited);
            dfs(image, sr, sc - 1, prevColor, color, visited);
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> visited(image.size(), vector<int>(image[0].size(), 0));
        dfs(image, sr, sc, image[sr][sc], color, visited);
        return image; 
    }
};