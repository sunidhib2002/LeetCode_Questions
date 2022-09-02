class Solution {
public:
    
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int leftMost = 0;
        int rightMost = n - 1;
        int left = -1;
        int right = -1;
        
        if (colors[rightMost] == colors[leftMost]) {
            for (int i = n - 1; i >= 0; i--) {
                if (colors[i] != colors[leftMost]) {
                    right = i;
                    break;
                }
            }
            
            for (int i = 0; i < n; i++) {
                if (colors[i] != colors[rightMost]) {
                    left = i;
                    break;
                }
            }
            return max(rightMost - left, right - leftMost);
        } else {
            return (rightMost - leftMost);
        }
        
        return 0;
    }
};