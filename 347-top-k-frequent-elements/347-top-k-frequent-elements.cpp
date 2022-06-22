class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        priority_queue<pair<int, int>> topK;
        int i = 0;
        while (i < nums.size()) {
            int cnt = 1;
            if (i + 1 != nums.size() && nums[i + 1] == nums[i]) {
                while (i + 1 != nums.size() && nums[i + 1] == nums[i]) {
                    cnt++;
                    i++;
                }
                topK.push({cnt, nums[i]});
                i++;
            } else {
                topK.push({cnt, nums[i]});    
                i++;
            }
        }
        vector<int> ans;
        while (k > 0) {
            ans.push_back(topK.top().second);
            topK.pop();
            k--;
        }
        return ans;
    }
};