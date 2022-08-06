class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> temp;
        vector<int> ans;
        for (int i = temperatures.size() - 1; i >= 0; i--) {
            if (temp.empty()) {
                ans.push_back(0);
            } else if (!temp.empty() && temp.top().first > temperatures[i]) {
                ans.push_back(temp.top().second - i);
            } else if (!temp.empty() && temp.top().first <= temperatures[i]) {
                while (!temp.empty() && temp.top().first <= temperatures[i]) {
                    temp.pop();
                }
                if (temp.empty()) {
                    ans.push_back(0);
                } else {
                    ans.push_back(temp.top().second - i);
                }
            }
            temp.push({temperatures[i], i});
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};