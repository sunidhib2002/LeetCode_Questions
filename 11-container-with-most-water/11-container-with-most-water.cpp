class Solution {
public:
    int maxArea(vector<int>& height) {
        int mx = INT_MIN;
        int left = 0;
        int right = height.size() - 1;
        while (left <= right) {
            mx = max(mx, (right - left) * min(height[right], height[left]));
            if (height[right] < height[left]) {
                right -= 1;
            } else {
                left++;
            }
        }
        return mx;
    }
};