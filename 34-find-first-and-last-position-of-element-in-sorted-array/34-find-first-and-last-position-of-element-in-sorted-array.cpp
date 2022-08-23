class Solution {
public:
    int GetFirst(vector<int> &nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (target == nums[mid]) {
                if (mid == 0) {
                    return 0;    
                }
            } 
            if (mid - 1 >= 0 && nums[mid] == target && nums[mid - 1] < target) {
                return mid;
            } 
            
            if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return -1;
    }
    
    int GetLast(vector<int> &nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (target == nums[mid]) {
                if (mid + 1 == nums.size()) {
                    return mid;    
                }
            } 
            if (mid + 1 < nums.size() && nums[mid] == target && nums[mid + 1] > target) {
                return mid;
            } 
            if (nums[mid] <= target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return -1;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        int first_occurence = GetFirst(nums, target);
        int second_occurence = GetLast(nums, target);
        ans.push_back(first_occurence);
        ans.push_back(second_occurence);
        return ans;
    }
};