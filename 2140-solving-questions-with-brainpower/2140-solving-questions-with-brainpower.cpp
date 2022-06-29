class Solution {
public:
    long long getMaxPoints(vector<vector<int>> &questions, int idx, vector<long long> &dp) {
        if (idx >= questions.size()) {
            return 0;
        }
        
        if (dp[idx] != -1) {
            return dp[idx];
        }
        
        return dp[idx] = max(getMaxPoints(questions, idx + 1, dp), questions[idx][0] + getMaxPoints(questions, idx + questions[idx][1] + 1, dp));        
    }
    
    long long mostPoints(vector<vector<int>>& questions) {
        //cout<<questions.size()<<endl;
        vector<long long> dp(questions.size(), -1);
        return getMaxPoints(questions, 0, dp);
    }
};