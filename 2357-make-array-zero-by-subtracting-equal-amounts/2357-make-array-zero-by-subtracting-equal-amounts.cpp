class Solution {
public:
    bool isAllZero(vector<int> &nums) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                return false;
            }
        }    
        return true;
    }
    
    int getMin(vector<int> &nums) {
        int mn = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                continue;
            } else if (mn > nums[i]) {
                mn = nums[i];
            }
        }
        return mn;
    }
    
    void Subtract(vector<int> &nums, int mn) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                continue;
            }
            nums[i] -= mn;
        }
    }
    
    int minimumOperations(vector<int>& nums) {
        int cnt = 0;
        while (!isAllZero(nums)) {
            int mn = getMin(nums); 
            //cout<<mn<<endl;
            Subtract(nums, mn);
            cnt++;
        }
        return cnt;
    }
};