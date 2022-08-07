class Solution {
public:
    long long Count(int n) {
        long long cnt = 0;
        for (int i = 0; i < n; i++) {
            cnt += i;
        }
        return cnt;
    }
    
    long long countBadPairs(vector<int>& nums) {
        unordered_map<int, int> IndexdiffTracker;
        long long totalPairs = Count(nums.size());
        long long GoodPairs = 0;
        //cout<<totalPairs<<endl;
        for (int i = 0; i < nums.size(); i++) {
            IndexdiffTracker[(nums[i] - i)]++;
        }
        
        // for (auto pr : IndexdiffTracker) {
        //     cout<<pr.first<<" "<<pr.second<<endl;
        // }
        
        for (auto pr : IndexdiffTracker) {
            GoodPairs += Count(pr.second);
        }
        // cout<<GoodPairs<<endl;
        return (totalPairs - GoodPairs);
    }
};

// j - i, nums[j] - nums[i]
// nums[i] - i ,  nums[j] - j