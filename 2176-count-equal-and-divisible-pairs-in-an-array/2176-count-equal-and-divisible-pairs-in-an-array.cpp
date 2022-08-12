class Solution {
public:
    int findPairs(vector<int> vec, int k) {
        int cnt = 0;
        for (int i = 0; i < vec.size() - 1; i++) {
            for (int j = i + 1; j < vec.size(); j++) {
                if (vec[i] * vec[j] % k == 0) {
                    cnt++;
                }
            }                                                
        }
        return cnt;
    }
    
    int countPairs(vector<int>& nums, int k) {
        int cnt = 0;
        unordered_map<int, int> freq;
        unordered_map<int, vector<int>> IndexTracker;
        
        for (int i = 0; i < nums.size(); i++) {
            freq[nums[i]] += 1;
            IndexTracker[nums[i]].push_back(i);
        }
        
        for (auto pr : freq) {
            if (pr.second > 1) {
                cnt += findPairs(IndexTracker[pr.first], k);
            } 
        }
        
        return cnt;
    }
};