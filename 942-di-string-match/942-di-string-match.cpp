class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n = s.length();
        vector<int> ans;
        vector<int> digits;
        for (int i = 0; i <= n; i++) {
            digits.push_back(i);
        }
        int left = 0;
        int right = n;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'I') {
                ans.push_back(digits[left]);
                left++; 
            } else {
                ans.push_back(digits[right]);
                right--;
            }
        }
        ans.push_back(digits[left]);
        return ans;
    }
};