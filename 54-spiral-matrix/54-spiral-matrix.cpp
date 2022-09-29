class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int firstRow = 0;
        int lastRow = matrix.size();
        int firstCol = 0;
        int lastCol = matrix[0].size();
        int cnt = 0;
        while (firstRow <= lastRow && firstCol <= lastCol) {
            // cout<<"Row"<<endl;
            for (int i = firstCol; i < lastCol; i++) {
                // cout<<matrix[firstRow][i]<<endl;
                if (cnt == matrix.size() * matrix[0].size()) {
                    break;
                }
                cnt++;
                ans.push_back(matrix[firstRow][i]);
            }
            firstRow++;
            
            // cout<<"Column ->"<<endl;
            if (firstRow <= lastRow && firstCol <= lastCol && lastCol - 1 >= 0) {
                for (int i = firstRow; i < lastRow; i++) {
                    // cout<<matrix[i][lastCol - 1]<<endl;
                    if (cnt == matrix.size() * matrix[0].size()) {
                        break;
                    }
                    cnt++;
                    ans.push_back(matrix[i][lastCol - 1]);
                }
            }
            
            // cout<<"Row ->"<<endl;
            lastCol--;
            if (firstRow <= lastRow && firstCol <= lastCol && lastRow - 1 >= 0) {
                for (int i = lastCol - 1; i >= firstCol; i--) {
                    // cout<<matrix[lastRow - 1][i]<<endl;
                    if (cnt == matrix.size() * matrix[0].size()) {
                        break;
                    }
                    cnt++;
                    ans.push_back(matrix[lastRow - 1][i]);
                }
            }
            
            lastRow--;
            // cout<<"Column ->"<<endl;
            if (firstRow <= lastRow && firstCol <= lastCol) {
                for (int i = lastRow - 1; i >= firstRow; i--) {
                    // cout<<matrix[i][firstCol]<<endl;
                    if (cnt == matrix.size() * matrix[0].size()) {
                        break;
                    }
                    cnt++;
                    ans.push_back(matrix[i][firstCol]);
                }
            }
            firstCol++;    
        }
        
        return ans;
    }
};