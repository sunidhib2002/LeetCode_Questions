class Solution {
public:
    void combinations(int idx, vector<int> &candidates, int target, vector<int> vec, vector<vector<int>> &ans) {
        if (target < 0) {
            return;
        }
        if (target == 0) {
            ans.push_back(vec);
            return;
        }
        if (idx >= candidates.size()) {
            return;
        }
        
        combinations(idx + 1, candidates, target, vec, ans);
        
        vec.push_back(candidates[idx]);
        combinations(idx, candidates, target - candidates[idx], vec, ans);
        vec.pop_back();
    }
    
    void convert(set<vector<int>> &store, vector<vector<int>> &ans) {
        for (auto it = store.begin(); it != store.end(); it++) {
            ans.push_back(*it);
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        set<vector<int>> store;
        vector<int> vec;
        combinations(0, candidates, target, vec, ans);
        // convert(store, ans);
        return ans;
    }
};