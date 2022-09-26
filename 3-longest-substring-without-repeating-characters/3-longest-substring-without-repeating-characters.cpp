class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() == 0) {
            return 0;
        }
        if (s.length() == 1) {
            return 1;
        }
        int left = 0;
        int right = 0;
        unordered_map<char, int> freq;
        int mx = 0;
        
        while (left <= right && right < s.length()) {
            if (freq.find(s[right]) != freq.end()) {
                mx = max(mx, right - left);
                while (freq.find(s[right]) != freq.end()) {
                    freq.erase(s[left]);
                    left += 1;
                }
                freq[s[right]] += 1;
                mx = max(mx, right - left);
            } else {
                freq[s[right]] += 1;
            }
            right++;
        }
        mx = max(mx, right - left);
        return mx;
    }
};