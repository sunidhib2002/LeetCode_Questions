class Solution {
public:
    int helper(string s, set<string> &tracker) {
        int mx = 0;
        for (int i = 1; i <= s.length(); i++) {
            string str = s.substr(0, i);
            if (tracker.find(str) == tracker.end()) {
                tracker.insert(str);
                mx = max(mx, 1 + helper(s.substr(i), tracker));
                tracker.erase(str);
            }
        }
        return mx;
    }
    
    int maxUniqueSplit(string s) {
        set<string> tracker;
        return helper(s, tracker);
    }
};