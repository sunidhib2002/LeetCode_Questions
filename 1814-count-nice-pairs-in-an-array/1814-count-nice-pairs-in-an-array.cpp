class Solution {
public:
    int getReverse(int n) {
        int rev = 0;
        while (n > 0) {
            int rem = n % 10;
            rev = rev * 10 + rem;
            n /= 10;
        }
        return rev;
    }
    
    long long Count(int n) {
        long long cnt = 0;
        cnt = (n * 1LL * (n - 1)) / 2;
        return cnt;
    }
    
    int countNicePairs(vector<int>& nums) {
        long long cnt = 0;
        int m = 1000000007;
        unordered_map<int, int> diffTracker;

        for (int i = 0; i < nums.size(); i++) {
            int diff = nums[i] - getReverse(nums[i]);
            diffTracker[diff] += 1;
        }
        
        for (auto pr : diffTracker) {
            cnt += Count(pr.second);
        }
        
        return cnt % m;
    }
};