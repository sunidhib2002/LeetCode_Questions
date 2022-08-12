class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        vector<int> indices;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                indices.push_back(i);   
            }
        }
        for (int i = 1; i < indices.size(); i++) {
            if (indices[i] - indices[i - 1] - 1 >= k) {
                continue;
            } else {
                return false;
            }
        }
        return true;
    }
};