class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = 0;
        int mid = 0;
        int right = nums.size() - 1;
        while (left <= right && mid <= right) {
            if (nums[mid] == 1) {
                mid += 1;
            } else if (nums[mid] == 0) {
                swap(nums[mid], nums[left]);
                mid += 1;
                left += 1;
            } else {
                swap(nums[mid], nums[right]);
                right -= 1;
            }
        }
    }
};