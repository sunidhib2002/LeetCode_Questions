class Solution {
public:
    bool allNegatives(vector<int> &nums) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                return false;
            }
        }    
        return true;
    }
    
    int maximum(vector<int> &nums) {
        int mx = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            mx = max(mx, nums[i]);
        }
        return mx;
    }
    
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int mx = 0;
        if (allNegatives(nums)) {
            return maximum(nums);       
        }
        
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (sum < 0) {
                sum = 0;
            }
            mx = max(mx, sum);
        }
        
        return mx;
    }
};