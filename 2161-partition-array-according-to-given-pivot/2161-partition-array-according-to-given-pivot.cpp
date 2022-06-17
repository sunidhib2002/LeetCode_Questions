class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> lessThan;
        vector<int> greaterThan;
        vector<int> ans;
        int countOfPivot = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < pivot) {
                lessThan.push_back(nums[i]);
            } else if (nums[i] == pivot) {
                countOfPivot++;
            } else {
                greaterThan.push_back(nums[i]);
            }
        }    
        for (int i = 0; i < lessThan.size(); i++)  {
            ans.push_back(lessThan[i]);
        } 
        for (int i = 0; i < countOfPivot; i++) {
            ans.push_back(pivot);
        } 
        for (int i = 0; i < greaterThan.size(); i++) {
            ans.push_back(greaterThan[i]);
        }
        return ans;    
    }
};