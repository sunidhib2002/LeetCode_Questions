class Solution {
public:
    vector<int> GetIndices(string s) {
        vector<int> ans;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '|') {
                ans.push_back(i);
            }
        }
        return ans;
    }
    
    int GetCount(string s, int start, int end) {
        int cnt = 0;
        for (int i = start; i < end; i++) {
            if (s[i] == '*') {
                cnt++;
            }
        }
        return cnt;
    }
    
    int countAsterisks(string s) {
        vector<int> barIndex = GetIndices(s);
        int i = 1;
        int cnt = 0;
        int n = barIndex.size();
        
        if (n == 0) {
            return GetCount(s, 0, s.length());
        } else {
            cnt += GetCount(s, 0, barIndex[0]) + GetCount(s, barIndex[n - 1], s.length());
        }
        
        while (i + 1 < barIndex.size()) {
            cnt += GetCount(s, barIndex[i], barIndex[i + 1]);
            i = i + 2;
        }

        return cnt;
    }
};