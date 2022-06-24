class Solution {
public:
    bool isLower(int val, vector<int> &nums) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < val) {
                return true;
            }
        }    
        return false;
    }
    
    bool isGreater(int val, vector<int> &nums) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > val) {
                return true;
            }
        }    
        return false;
    }
    
    int countElements(vector<int>& nums) {
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (isLower(nums[i], nums) && isGreater(nums[i], nums)) {
                //cout<<nums[i]<<endl;
                cnt++;
            }
        }
        
        return cnt;
    }
};