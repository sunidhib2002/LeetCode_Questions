class Solution {
public:
    // void convert2Vec(vector<vector<int>> &ans, set<vector<int>> store) {
    //     for (auto it = store.begin(); it != store.end(); it++) {
    //         ans.push_back(*it);
    //     }    
    // }
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        // set<vector<int>> store;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (i == 0 || i > 0 && nums[i] != nums[i - 1]) {
                int target = nums[i] * (-1);
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right) {
                if (nums[left] + nums[right] == target) {
                    vector<int> vec;
                    vec.push_back(nums[i]);
                    vec.push_back(nums[left]);
                    vec.push_back(nums[right]);
                    ans.push_back(vec);
                    
                    while (left < right && nums[left] == nums[left + 1]) {
                        left++;
                    }
                    
                    while (left < right && nums[right] == nums[right - 1]) {
                        right--;
                    }
                    
                    left++;
                    right--;
                } else if (nums[left] + nums[right] > target) {
                    right -= 1;
                } else {
                    left += 1;
                }
            }
        }
            
        }
        // convert2Vec(ans, store);
        return ans;
    }
};