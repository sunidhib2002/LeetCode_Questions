class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int mx = INT_MIN;
        vector<int> maxSoFar;
        for (int i = nums.size() - 1; i >= 0; i--) {
            mx = max(mx, nums[i]);
            maxSoFar.push_back(mx);
        }
        reverse(maxSoFar.begin(), maxSoFar.end());
        int mxDiff = 0;
        for (int i = 0; i < maxSoFar.size(); i++) {
            mxDiff = max(mxDiff, maxSoFar[i] - nums[i]);
        }
        if (mxDiff == 0) {
            return -1;
        }
        return mxDiff;
    }
};